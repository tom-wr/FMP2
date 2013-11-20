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

using namespace std;

class Passenger
{
public:
	Passenger(string name, char seat, string flightNum);

	string getFlightNumber() const;
	char getSeat(void) const;
	string getName() const;

private:
	string name;
	char seat;
	string flightNum;
};
#endif /* PASSENGER_H_ */
