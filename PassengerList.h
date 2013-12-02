/*
 * PassengerList.h
 *
 *  Created on: 26 Nov 2013
 *      Author: tomto
 */

#ifndef PASSENGERLIST_H_
#define PASSENGERLIST_H_

#include <vector>
#include <string>
#include <iostream>

#include "Passenger.h"

using namespace std;

class PassengerList {
public:
	PassengerList(){};
	void addPassenger(string name);
	bool removePassenger(string& name);
	bool searchForPassenger(string& name);
	Passenger* getPassenger(string name);
	~PassengerList(){};

private:
	vector<Passenger*> passengerList;
};

#endif /* PASSENGERLIST_H_ */
