/*
 * FlightPassengerList.h
 *
 *  Created on: 21 Nov 2013
 *      Author: tomto
 */

#ifndef FLIGHTPASSENGERLIST_H_
#define FLIGHTPASSENGERLIST_H_

#include "Passenger.h"
#include "PassengerList.h"
#include <iostream>


class FlightPassengerList : public PassengerList
{
public:
	FlightPassengerList(int capacity);
	bool add(Passenger& passenger);
	int getFirstCapacity(void);
	int getEconomyCapacity(void);
private:
	int firstCapacity;
	int economyCapacity;
};
#endif /* FLIGHTPASSENGERLIST_H_ */
