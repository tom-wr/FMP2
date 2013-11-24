/*
 * FlightList.h
 *
 *  Created on: 22 Nov 2013
 *      Author: tomto
 */

#ifndef FLIGHTLIST_H_
#define FLIGHTLIST_H_

#include <vector>
#include "Flight.h"

class FlightList
{
public:
	bool checkFlightExists(string flightNumber);
	void addFlight(Flight& flight);
	void addPassengerToFlight(Passenger& passenger, string& flightNumber);
	Passenger* getPassengerByName(string& name);
	Flight* getFlight(string& flightNumber);
	vector<Flight> getList() const;
private:
	vector<Flight> flightList;
};
#endif /* FLIGHTLIST_H_ */
