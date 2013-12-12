/** Flight class holds it's own flight information and passenger lists.
 */

#include "Flight.h"

/**
 * Flight constructor.
 * @param flightNumber string& - flight number.
 * @param capacity int - capacity of flight.
 * @param date Date& - date of flight.
 */
Flight::Flight(string& _flightNumber, int _capacity, Date& _date)
: flightNumber(_flightNumber), capacity(_capacity), date(_date), bookedList(_capacity)
{
}

/**
 * adds a passenger to the booked list given the required seat type.
 * @param passenger Passenger* - pointer to passenger to add.
 * @param seat const Seat::Type - seat type indicating which list to add passenger to.
 */
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

/**
 * adds a passenger to the waiting list given the required seat type.
 * @param passenger Passenger* - pointer to passenger to add.
 * @param seat const Seat::Type - seat type indicating which list to add passenger to.
 */
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

/**
 * remove passenger from flight.
 * @param name string& - name of passenger to remove.
 */
void Flight::removePassenger(string& name)
{
	if(bookedList.searchForPassenger(name))
	{
		bookedList.removePassenger(name);
	}
	else if(waitingList.searchForPassenger(name))
	{
		waitingList.removePassenger(name);
	}
	else
	{
		View::error(View::errorPassengerNotExist);
	}
}


/*
 * checks if the first class booked list is full/
 * @return bool - true if first class list is full / false if not full
 */
bool Flight::firstIsFull()
{
	int capacity = bookedList.getFirstCapacity();
	int size = bookedList.getFirstSize();

	if(size < capacity)
		return false;
	else
		return true;
}

/*
 * checks if the economy class booked list is full/
 * @return bool - true if economy class list is full / false if not full
 */
bool Flight::economyIsFull()
{
	int capacity = bookedList.getEconomyCapacity();
	int size = bookedList.getEconomySize();

	if(size < capacity)
		return false;
	else
		return true;
}

/**
 * checks seat is available in booked list for given seat type.
 * @param seat Seat::Type - seat type to be check if available.
 */
bool Flight::checkSeatIsAvailable(Seat::Type seat)
{
	if((seat == Seat::FIRST) && firstIsFull())
		return false;
	else if((seat == Seat::ECONOMY) && economyIsFull())
		return false;
	else
		return true;
}

/**
 * searches for a passenger on the flight based on their name.
 * @param passengerName string& - name of passenger to be searched for.
 */
bool Flight::searchForPassenger(string& passengerName)
{
	waitingList.searchForPassenger(passengerName);
	return false;
}

/**
 * getter for flight capacity.
 * @return const int - capacity of flight.
 */
const int Flight::getCapacity() const
{
	return capacity;
}

/**
 * getter for flight date.
 * @return Date& - date of flight.
 */
Date& Flight::getDate()
{
	return date;
}

/**
 * getter for flight number.
 * @return const string& - flight number of flight.
 */
string& Flight::getFlightNumber()
{
	return flightNumber;
}

/**
 * getter for booked list.
 * @return BookedList* - pointer to booked list of flight.
 */
BookedList* Flight::getBookedList()
{
	return &bookedList;
}

/**
 * getter for waiting list.
 * @return WaitingList* - pointer to waiting list of flight.
 */
WaitingList* Flight::getWaitingList()
{
	return &waitingList;
}
