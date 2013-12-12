#include "PassengerList.h"

/**
 * create a passenger and add to the list.
 * @param name string - the name of the new passenger.
 */
void PassengerList::addPassenger(string name)
{
	Passenger *pass_ptr = new Passenger(name);
	passengerList.push_back(pass_ptr);
}


/**
 * remove passenger from the list.
 * @param name string& - the name of the passenger to be removed.
 * @return bool - true if removal successful / false if the removal failed.
 */
bool PassengerList::removePassenger(string& name)
{
	vector<Passenger*>::iterator it;
	for( it = passengerList.begin(); it != passengerList.end(); ++it)
	{
		if( (*it)->getName() == name)
		{
			delete (*it);
			passengerList.erase(it);
			return true;
		}
	}
	return false;
}

/**
 * search for passengers in the passenger list.
 * @param name string& - name of the passenger to search for.
 * @return bool - true is passenger exists / false if passenger is not found.
 */
bool PassengerList::searchForPassenger(string& name)
{
	vector<Passenger*>::iterator it;
	for(it = passengerList.begin(); it != passengerList.end(); ++it)
	{
		if( (*it)->getName() == name)
		{
			return true;
		}
	}
	return false;
}

/**
 * get passenger from the passenger list.
 * @param name string - name of passenger to be found.
 * @return Passenger* - pointer to the found passenger. returns NULL is no passenger is found.
 */
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
