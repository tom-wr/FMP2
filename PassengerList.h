/*
 * PassengerList.h
 *
 *  Created on: 20 Nov 2013
 *      Author: tomto
 */

#ifndef PASSENGERLIST_H_
#define PASSENGERLIST_H_

#include <string>
#include <vector>
#include <iostream>

#include "Passenger.h"

using namespace std;

class PassengerList
{
public:
	void add(Passenger& passenger);
	void remove(string name);
private:
	vector<Passenger> firstList;
	vector<Passenger> economyList;
};
#endif /* PASSENGERLIST_H_ */
