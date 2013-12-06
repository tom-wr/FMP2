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

	cout << "making cancellation" << endl;
	// Get flight and passenger
	Flight *flight = flightList.getFlight(flightNumber);
	Passenger *passenger = passengerList.getPassenger(passengerName);
	cout << "-- get flight and passenger" << endl;
	if(flight && passenger)
	{
		Seat::Type seatFreed = passenger->getBookingByFlightNumber(flightNumber)->getSeatType();
		cout << "--- removing passenger" << endl;
		// remove passenger from flight and remove booking from passenger
		flight->removePassenger(passengerName);
		passenger->removeBooking(flightNumber);

		cout << "--- promoting passengers" << endl;
		//promote waiting passengers if space created in booked list
		transferPassengers(flight, seatFreed);

		//remove passenger from system if they have no bookings
		cout << "--- removing passenger from system" << endl;
		if(passenger->getBookings()->empty())
			passengerList.removePassenger(passengerName);
		cout << "--- finished cancellation" << endl;
		// clean up
	}
}

void CancellationSystem::transferPassengers(Flight* flight, Seat::Type seat)
{
	cout << "--- transferring passenger" << endl;
	BookedList *bookedList = flight->getBookedList();
	WaitingList *waitingList = flight->getWaitingList();
	if(seat == Seat::FIRST)
	{
		if( (bookedList->getFirstSize() < bookedList->getFirstCapacity())
				&& !(waitingList->getFirstClassList().empty()) )
		{
			Passenger *nextPassenger = waitingList->popFirstClassWaiting();
			bookedList->addPassengerToFirst(nextPassenger);
		}
	}
	else if (seat == Seat::ECONOMY)
	{
		if( (bookedList->getEconomySize() < bookedList->getEconomyCapacity())
				&& !(waitingList->getEconomyClassList().empty()) )
		{
			Passenger* nextPassenger = waitingList->popEconomyClassWaiting();
			waitingList->addPassengerToEconomy(nextPassenger);
		}
	}
}

void CancellationSystem::makeTransfer()
{

}
