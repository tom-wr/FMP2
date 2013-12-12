/** FlightList class holds a list of Flight objects.
 * The list is used to keep track of the Flight objects.
 * Flights are only added to the list and live for the entirety
 * of the program and therefore there is no need to remove flights.
 */

#include "FlightList.h"

/*
 * searches for and returns a flight to the list.
 * returns void if no flight is found.
 * @param flightNumber string& - flight number of flight to be retrieved.
 */
Flight* FlightList::getFlight(string& flightNumber)
{
	map<string, Flight*>::iterator it = flightList.find(flightNumber);
	if(it != flightList.end())
	{
		return it->second;
	}
	else
		return NULL;
}

/**
 * adds flight to the flight list.
 * @param flight Flight& - the flight to be added to the list.
 */
void FlightList::addFlight(Flight& flight)
{
	Flight *flight_ptr = new Flight(flight);
	flightList.insert(pair<string, Flight*>(flight.getFlightNumber(), flight_ptr));
}
