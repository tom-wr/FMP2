#include "PassengerList.h"

// Add a passenger to the appropriate list according to assigned seat preference
void PassengerList::addPassenger(string name)
{
	Passenger *pass_ptr = new Passenger(name);
	passengerList.push_back(pass_ptr);
}


// Remove passenger from a given list by searching for matching name
bool PassengerList::removePassenger(string& name)
{
	for(vector<Passenger*>::iterator it = passengerList.begin(); it != passengerList.end(); ++it)
	{
		if( (*it)->getName() == name)
		{
			cout << name << " is being removed." << endl;
			passengerList.erase(it);
			return true;
		}
	}
	return false;
}

// Search for passenger by name
bool PassengerList::searchForPassenger(string& name)
{
	vector<Passenger*>::iterator it;
	for(it = passengerList.begin(); it != passengerList.end(); ++it)
	{
		if( (*it)->getName() == name)
		{
			cout << "just found " << (*it)->getName() << endl;;
			return true;
		}
	}
	return false;
}

// get pointer to passenger given a name
Passenger* PassengerList::getPassenger(string name)
{
	for(vector<Passenger*>::iterator it = passengerList.begin(); it != passengerList.end(); ++it)
	{
		if((*it)->getName() == name)
		{
			return *it;
		}
	}
	return NULL;
}
