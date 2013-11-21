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
	PassengerList();
	void add(Passenger& passenger);
	void remove(string name);
	bool search(string name);

protected:
	vector<Passenger> firstList;
	vector<Passenger> economyList;
	bool removePassengerFromList(string name, vector<Passenger>& list);
	bool searchPassengerList(string name, vector<Passenger>& list);
};
#endif /* PASSENGERLIST_H_ */
