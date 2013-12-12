/** CancellationSystem controls the removal and transference of passengers in the system.
 */

#include "CancellationSystem.h"

/**
 * CancellationSystem constructor.
 * @param flightList FlightList - reference to list of flights
 * @param passengerList PassengerList - reference to list of passengers
 */
CancellationSystem::CancellationSystem(FlightList& _flightList, PassengerList& _passengerList)
:flightList(_flightList), passengerList(_passengerList)
{
}

/**
 * cancels a passenger's booking from a flight.
 * The passenger name and flight number of the booking to be cancelled
 * are determined by asking the user through the UI.
 */
void CancellationSystem::makeCancellation()
{
	// get user input
	UI::outputAskPassengerName();
	string passengerName = UI::inputName();
	UI::outputAskFlightNumber();
	string flightNumber = UI::inputFlightNumber();

	// Get flight and passenger
	Flight *flight = flightList.getFlight(flightNumber);
	Passenger *passenger = passengerList.getPassenger(passengerName);
	if(flight && passenger) // if flight and passenger exist
	{
		Seat::Type seatFreed = passenger->getBookingByFlightNumber(flightNumber)->getSeatType();
		// remove passenger from flight and remove booking from passenger
		flight->removePassenger(passengerName);
		passenger->removeBooking(flightNumber);
		View::successCancelledPassenger(passengerName, flightNumber);
		//promote waiting passengers if space created in booked list
		transferPassengers(flight, seatFreed);
		//remove passenger from system if they have no bookings
		if(passenger->getBookings()->empty())
			passengerList.removePassenger(passengerName);
	}
}

/**
 * Transfers passengers from waiting list to booked list of a flight.
 * Which list type is indicated by the seat type parameter
 * @param flight Flight* - pointer to flight
 * @param seat Seat::Type - which seat type list to be operated on
 */
void CancellationSystem::transferPassengers(Flight* flight, Seat::Type seat)
{
	//get the lists
	BookedList *bookedList = flight->getBookedList();
	WaitingList *waitingList = flight->getWaitingList();

	if(seat == Seat::FIRST) // if requested seat is first class
	{
		if( (bookedList->getFirstSize() < bookedList->getFirstCapacity())
				&& !(waitingList->getFirstClassList().empty()) )
		{
			Passenger *nextPassenger = waitingList->popFirstClassWaiting(); // get next passenger in queue
			Booking* booking = nextPassenger->getBookingByFlightNumber(flight->getFlightNumber());
			booking->setStatus(BookingStatus::BOOKED);
			bookedList->addPassengerToFirst(nextPassenger);
			View::successTransferedPassenger(nextPassenger->getName(), Seat::toString[Seat::FIRST]);
		}
	}
	else if (seat == Seat::ECONOMY) // if requested seat is economy class
	{
		if( (bookedList->getEconomySize() < bookedList->getEconomyCapacity())
				&& !(waitingList->getEconomyClassList().empty()) )
		{
			Passenger* nextPassenger = waitingList->popEconomyClassWaiting(); // get next passenger in the queue
			Booking* booking = nextPassenger->getBookingByFlightNumber(flight->getFlightNumber());
			booking->setStatus(BookingStatus::BOOKED);
			bookedList->addPassengerToEconomy(nextPassenger);
			View::successTransferedPassenger(nextPassenger->getName(), Seat::toString[Seat::ECONOMY]);
		}
	}
}
