/*
 * Passenger.h
 *
 *  Created on: 20 Nov 2013
 *      Author: tomto
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <vector>
#include <string>
#include "Seat.h"

using namespace std;


class Passenger
{
public:
	Passenger(string name, Seat::Type seat, string flightNums);
	string getFlightNumbers() const;
	Seat::Type getSeat(void) const;
	string getName() const;

private:
	string name;
	Seat::Type seat;
	string flightNums;
};
#endif /* PASSENGER_H_ */
