/** FlightList class holds a list of Flight objects.
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
	/**
	 * adds flight to the flight list.
	 * @param flight Flight& - the flight to be added to the list.
	 */
	void addFlight(Flight& flight);

	/**
	 * removes flight to the flight list.
	 * @param flight Flight& - the flight to be removed from the list.
	 */
	void removeFlight(Flight& flight);

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
