#include "Flight.h"

Flight::Flight(string newcode, int newcapacity, string newdate)
{
	code = newcode;
	capacity = newcapacity;
	date = newdate;
}

string Flight::getFlightCode() const
{
	return code;
}

int Flight::getFlightCapacity() const
{
	return capacity;
}

string Flight::getFlightDate() const
{
	return date;
}

