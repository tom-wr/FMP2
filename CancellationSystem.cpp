#include "CancellationSystem.h"

CancellationSystem::CancellationSystem(FlightList& _flightList, PassengerList& _passengerList)
:flightList(_flightList), passengerList(_passengerList)
{
}

void CancellationSystem::makeCancellation()
{
	UI::outputAskPassengerName();
	string passengerName = UI::inputName();
	UI::outputAskFlightNumber();
	string flightNumber = UI::inputFlightNumber();

	// Get flight and passenger
	Flight *flight = flightList.getFlight(flightNumber);
	Passenger *passenger = passengerList.getPassenger(passengerName);
	if(flight && passenger)
	{
		Seat::Type seatFreed = passenger->getBookingByFlightNumber(flightNumber)->getSeatType();
		// remove passenger from flight and remove booking from passenger
		flight->removePassenger(passengerName);
		passenger->removeBooking(flightNumber);
		View::successCancelledPassenger(passengerName);
		//promote waiting passengers if space created in booked list
		transferPassengers(flight, seatFreed);
		//remove passenger from system if they have no bookings
		if(passenger->getBookings()->empty())
			passengerList.removePassenger(passengerName);
	}
}

void CancellationSystem::transferPassengers(Flight* flight, Seat::Type seat)
{
	BookedList *bookedList = flight->getBookedList();
	WaitingList *waitingList = flight->getWaitingList();
	if(seat == Seat::FIRST)
	{
		if( (bookedList->getFirstSize() < bookedList->getFirstCapacity())
				&& !(waitingList->getFirstClassList().empty()) )
		{
			Passenger *nextPassenger = waitingList->popFirstClassWaiting();
			Booking* booking = nextPassenger->getBookingByFlightNumber(flight->getFlightNumber());
			booking->setStatus(BookingStatus::BOOKED);
			bookedList->addPassengerToFirst(nextPassenger);
			View::successTransferedPassenger(nextPassenger->getName(), Seat::toString[Seat::FIRST]);
		}
	}
	else if (seat == Seat::ECONOMY)
	{
		if( (bookedList->getEconomySize() < bookedList->getEconomyCapacity())
				&& !(waitingList->getEconomyClassList().empty()) )
		{
			Passenger* nextPassenger = waitingList->popEconomyClassWaiting();
			Booking* booking = nextPassenger->getBookingByFlightNumber(flight->getFlightNumber());
			booking->setStatus(BookingStatus::BOOKED);
			bookedList->addPassengerToEconomy(nextPassenger);
			View::successTransferedPassenger(nextPassenger->getName(), Seat::toString[Seat::ECONOMY]);
		}
	}
}
