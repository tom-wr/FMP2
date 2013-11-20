#include "Passenger.h"

Passenger::Passenger(string newname, char newseat, string newflightNum)
{
	name = newname;
	seat = newseat;
	flightNum = newflightNum;
}

string Passenger::getFlightNumber() const
{
	return flightNum;
}

char Passenger::getSeat() const
{
	return seat;
}

string Passenger::getName() const
{
	return name;
}
