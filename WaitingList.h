/*
 * WaitingList.h
 *
 *  Created on: 26 Nov 2013
 *      Author: tomto
 */

#ifndef WAITINGLIST_H_
#define WAITINGLIST_H_

#include <string>
#include <deque>
#include <iostream>

#include "Passenger.h"

using namespace std;

class WaitingList
{
public:
	void addPassengerToFirst(Passenger* passenger);
	void addPassengerToEconomy(Passenger* passenger);
	Passenger* getPassenger(string& name);
	const deque<Passenger*>& getFirstClassList()const;
	const deque<Passenger*>& getEconomyClassList()const;
	virtual void removePassenger(string name);
	virtual bool searchForPassenger(string& name);
	virtual Passenger* popFirstClassWaiting();
	virtual Passenger* popEconomyClassWaiting();
	virtual ~WaitingList(){};

protected:
	deque<Passenger*> firstList;
	deque<Passenger*> economyList;
	Passenger* getPassengerFromList(string& name, deque<Passenger*>& list);
	bool removePassengerFromList(string name, deque<Passenger*>& list);
	bool searchPassengerList(string name, deque<Passenger*>& list);
};


#endif /* WAITINGLIST_H_ */
