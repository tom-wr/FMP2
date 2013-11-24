#include "Flight.h"

Flight::Flight(string _flightNumber, int _capacity, Date& _date)
:flightPassengerList(_capacity)
{
	flightNumber = _flightNumber;
	capacity = _capacity;
	date = _date;
}

void Flight::addPassenger(Passenger& passenger)
{
	if(!flightPassengerList.add(passenger))
		waitingList.add(passenger);
}

string Flight::getFlightNumber() const
{
	return flightNumber;
}

int Flight::getFlightCapacity() const
{
	return capacity;
}

Date Flight::getFlightDate() const
{
	return date;
}

PassengerList& Flight::getWaitingList()
{
	return waitingList;
}

FlightPassengerList& Flight::getFlightPassengerList()
{
	return flightPassengerList;
}
