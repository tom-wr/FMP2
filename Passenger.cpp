#include "Passenger.h"


Passenger::Passenger(string _name, Seat::Type _seat, string _flightNums)
{
	name = _name;
	seat = _seat;
	flightNums = _flightNums;
}

string Passenger::getFlightNumbers() const
{
	return flightNums;
}

Seat::Type Passenger::getSeat() const
{
	return seat;
}

string Passenger::getName() const
{
	return name;
}
