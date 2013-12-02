/*
 * WaitingList.cpp
 *
 *  Created on: 26 Nov 2013
 *      Author: tomto
 */

#include "WaitingList.h"

// Add a passenger to the appropriate list according to assigned seat preference
void WaitingList::addPassengerToFirst(Passenger* passenger)
{
	firstList.push_back(passenger);
}

void WaitingList::addPassengerToEconomy(Passenger* passenger)
{
	economyList.push_back(passenger);
}

// Remove passenger from the economy or first class list
void WaitingList::removePassenger(string name)
{
	if(!removePassengerFromList(name, economyList))
		removePassengerFromList(name, firstList);
}

bool WaitingList::removePassengerFromList(string name, vector<Passenger*>& list)
{
	for(vector<Passenger*>::iterator it = list.begin(); it != list.end(); ++it)
	{
		if((*it)->getName() == name)
		{
			cout << name << " is being removed." << endl;
			list.erase(it);
			return true;
		}
	}
	return false;
}


bool WaitingList::searchForPassenger(string name)
{
	if(searchPassengerList(name, economyList))
		return true;
	else return searchPassengerList(name, firstList);
}

bool WaitingList::searchPassengerList(string name, vector<Passenger*>& list)
{
	for(vector<Passenger*>::iterator it = list.begin(); it != list.end(); ++it)
	{
		if((*it)->getName() == name)
		{
			cout << "Found " << name << endl;
			return true;
		}
	}
	return false;
}


Passenger* WaitingList::getPassenger(string& name)
{
	Passenger * foundPassenger = getPassengerFromList(name, economyList);
	if(foundPassenger)
		return foundPassenger;
	foundPassenger = getPassengerFromList(name, firstList);
	if(foundPassenger)
		return foundPassenger;

	return NULL;
}

Passenger* WaitingList::getPassengerFromList(string& name, vector<Passenger*>& list)
{
	for(vector<Passenger*>::iterator it = list.begin(); it != list.end(); ++it)
	{
		if((*it)->getName() == name)
		{
			return (*it);
		}
	}
	return NULL;
}

const vector<Passenger*>& WaitingList::getFirstClassList()const
{
	return firstList;
}

const vector<Passenger*>& WaitingList::getEconomyClassList()const
{
	return economyList;
}



