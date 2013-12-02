#include "FlightList.h"

Flight* FlightList::getFlight(string& flightNumber)
{
	map<string, Flight*>::iterator it = flightList.find(flightNumber);
	return it->second;
}

void FlightList::addFlight(Flight& flight)
{
	Flight *flight_ptr = new Flight(flight);
	flightList.insert(pair<string, Flight*>(flight.getFlightNumber(), flight_ptr));
}

void FlightList::removeFlight(Flight& flight)
{
	delete &flight;
}
