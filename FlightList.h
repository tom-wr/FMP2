/** FlightList class holds a list of Flight objects.
 * The list is used to keep track of the Flight objects.
 * Flights are only added to the list and live for the entirety
 * of the program and therefore there is no need to remove flights.
 */


#ifndef FLIGHTLIST_H_
#define FLIGHTLIST_H_

#include <map>
#include <string>
#include <utility> // pair
#include <memory>

#include "Flight.h"

class FlightList
{
public:
	/*
	 * FlightList Constructor.
	 */
	FlightList(void){}

	/**
	 * adds flight to the flight list.
	 * @param flight Flight& - the flight to be added to the list.
	 */
	void addFlight(Flight& flight);

	/**
	 * searches for and returns a flight to the list.
	 * returns void if no flight is found.
	 * @param flightNumber string& - flight number of flight to be retrieved.
	 */
	Flight* getFlight(string& flightNumber);

private:
	// map of flight number strings paired with their respective flights.
	map<string, Flight*> flightList;
};
#endif /* FLIGHTLIST_H_ */
