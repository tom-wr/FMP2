#include "PassengerList.h"

PassengerList::PassengerList(){}

// Add a passenger to the appropriate list according to assigned seat preference
void PassengerList::add(Passenger& passenger)
{
	if(passenger.getSeat() == Seat::FIRST)
		firstList.push_back(passenger);
	else if(passenger.getSeat() == Seat::ECONOMY)
		economyList.push_back(passenger);
}

// Remove passenger from the economy or first class list
void PassengerList::remove(string name)
{
	if(!removePassengerFromList(name, economyList))
		removePassengerFromList(name, firstList);
}

// Remove passenger from a given list by searching for matching name
bool PassengerList::removePassengerFromList(string name, vector<Passenger>& list)
{
	for(vector<Passenger>::iterator it = list.begin(); it != list.end(); ++it)
	{
		if(it->getName() == name)
		{
			cout << name << " is being removed." << endl;
			list.erase(it);
			return true;
		}
	}
	return false;
}

bool PassengerList::search(string name)
{
	if(searchPassengerList(name, economyList))
		return true;
	else return searchPassengerList(name, firstList);
}

bool PassengerList::searchPassengerList(string name, vector<Passenger>& list)
{
	for(vector<Passenger>::iterator it = list.begin(); it != list.end(); ++it)
	{
		if(it->getName() == name)
		{
			cout << "Found " << name << endl;
			return true;
		}
	}
	return false;
}

Passenger* PassengerList::getPassenger(string name)
{
	Passenger* foundPassenger = getPassengerFromList(name, economyList);
	if(foundPassenger)
		return foundPassenger;
	foundPassenger = getPassengerFromList(name, firstList);
	if(foundPassenger)
		return foundPassenger;

	return NULL;
}

Passenger* PassengerList::getPassengerFromList(string name, vector<Passenger>& list)
{
	for(vector<Passenger>::iterator it = list.begin(); it != list.end(); ++it)
	{
		if(it->getName() == name)
		{
			return &(*it);
		}
	}
	return NULL;
}




