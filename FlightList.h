/*
 * FlightList.h
 *
 *  Created on: 28 Nov 2013
 *      Author: tomto
 */

#ifndef FLIGHTLIST_H_
#define FLIGHTLIST_H_

#include <map>
#include <string>
#include <utility>
#include <memory>

#include "Flight.h"

class FlightList
{
public:
	void addFlight(Flight& flight);
	void removeFlight(Flight& flight);
	Flight* getFlight(string& flightNumber);
private:
	map<string, Flight*> flightList;
};
#endif /* FLIGHTLIST_H_ */
