/*
 * WaitingList.h
 *
 *  Created on: 26 Nov 2013
 *      Author: tomto
 */

#ifndef WAITINGLIST_H_
#define WAITINGLIST_H_

#include <string>
#include <vector>
#include <iostream>

#include "Passenger.h"

using namespace std;

class WaitingList
{
public:
	void addPassengerToFirst(Passenger* passenger);
	void addPassengerToEconomy(Passenger* passenger);
	Passenger* getPassenger(string& name);
	const vector<Passenger*>& getFirstClassList()const;
	const vector<Passenger*>& getEconomyClassList()const;
	virtual void removePassenger(string name);
	virtual bool searchForPassenger(string name);
	virtual ~WaitingList(){};

protected:
	vector<Passenger*> firstList;
	vector<Passenger*> economyList;
	Passenger* getPassengerFromList(string& name, vector<Passenger*>& list);
	bool removePassengerFromList(string name, vector<Passenger*>& list);
	bool searchPassengerList(string name, vector<Passenger*>& list);
};


#endif /* WAITINGLIST_H_ */
