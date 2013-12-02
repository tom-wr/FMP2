
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

bool Flight::firstIsFull()
{
	cout << "-- checking first is full" << endl;
	int capacity = bookedList.getFirstCapacity();
	int size = bookedList.getFirstSize();
	cout << "-- size is " << size << endl;
	cout << "-- capacity is " << capacity << endl;;

	if(size < capacity)
		return false;
	else
		return true;
}

bool Flight::economyIsFull()
{
	cout << "-- checking economy is full" << endl;
	int capacity = bookedList.getEconomyCapacity();
	int size = bookedList.getEconomySize();
	cout << "-- size is " << size << endl;
	cout << "-- capacity is " << capacity << endl;;
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

const int Flight::getCapacity() const
{
	return capacity;
}

const Date& Flight::getDate() const
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
