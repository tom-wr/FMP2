
#include "Flight.h"

// Constructor for flight
Flight::Flight(string& _flightNumber, const int _capacity, Date& _date)
: flightNumber(_flightNumber), capacity(_capacity), date(_date), bookedList(10)
{
}

// Add a passenger to the flight given the seat type so they are
// added to the appropriate queue.
void Flight::addPassengerToBookedList(Passenger* passenger, const Seat::Type seat)
{
	if(seat == Seat::FIRST)
	{
		bookedList.addPassengerToFirst(passenger);
	}
	else if (seat == Seat::ECONOMY)
	{
		bookedList.addPassengerToEconomy(passenger);
	}
}

void Flight::addPassengerToWaitingList(Passenger* passenger, const Seat::Type seat)
{
	if(seat == Seat::FIRST)
	{
		waitingList.addPassengerToFirst(passenger);
	}
	else if (seat == Seat::ECONOMY)
	{
		waitingList.addPassengerToEconomy(passenger);
	}
}

void Flight::removePassenger(string& name)
{
	if(bookedList.searchForPassenger(name))
	{
		cout << "Removing passenger from booked list" << endl;
		bookedList.removePassenger(name);
	}
	else if(waitingList.searchForPassenger(name))
	{
		cout << "Removing passenger from waiting list" << endl;
		waitingList.removePassenger(name);
	}
	else
	{
		cout << "Passenger does not exist" << endl;
	}
}

bool Flight::firstIsFull()
{
	int capacity = bookedList.getFirstCapacity();
	int size = bookedList.getFirstSize();

	if(size < capacity)
		return false;
	else
		return true;
}

bool Flight::economyIsFull()
{
	int capacity = bookedList.getEconomyCapacity();
	int size = bookedList.getEconomySize();
	if(size < capacity)
		return false;
	else
		return true;
}

bool Flight::checkSeatIsAvailable(Seat::Type seat)
{
	cout << "- checking seat is available" << endl;
	if((seat == Seat::FIRST) && firstIsFull())
	{
		cout << "- first seat is unavailable" << endl;
		return false;
	}
	else if((seat == Seat::ECONOMY) && economyIsFull())
	{
		cout << "- economy seat is unavailable" << endl;
		return false;
	}
	else
	{
		cout << "- seat is available" << endl;
		return true;
	}
}

bool Flight::searchForPassenger(string& passengerName)
{
	waitingList.searchForPassenger(passengerName);
	return false;
}

const int Flight::getCapacity() const
{
	return capacity;
}

Date& Flight::getDate()
{
	return date;
}

// get the flight number of the flight
const string& Flight::getFlightNumber() const
{
	return flightNumber;
}

BookedList* Flight::getBookedList()
{
	return &bookedList;
}

WaitingList* Flight::getWaitingList()
{
	return &waitingList;
}
