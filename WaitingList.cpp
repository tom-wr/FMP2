/** WaitingList holds first and economy class deques of passengers
 *
 */

#include "WaitingList.h"

/**
 * adds a passenger to the first class list.
 * @param passenger Passenger* - passenger to be added.
 */
void WaitingList::addPassengerToFirst(Passenger* passenger)
{
	firstList.push_back(passenger);
}

/**
 * adds a passenger to the economy class list.
 * @param passenger Passenger* - passenger to be added.
 */
void WaitingList::addPassengerToEconomy(Passenger* passenger)
{
	economyList.push_back(passenger);
}

/**
 * removes a passenger from the deques.
 * @param name string - name of the passenger to be removed.
 */
void WaitingList::removePassenger(string name)
{
	if(!removePassengerFromList(name, firstList))
		removePassengerFromList(name, economyList);
}

/**
 * gets and erases the first element from the first class deque.
 * returns NULL if the deque is empty.
 * @return Passenger* - pointer to the passenger.
 */
Passenger* WaitingList::popFirstClassWaiting()
{
	if(!firstList.empty())
	{
		Passenger* frontPassenger = firstList.front();
		firstList.pop_front();
		return frontPassenger;
	}
	return NULL;
}

/**
 * gets and erases the first element from the economy class deque.
 * returns NULL if the deque is empty.
 * @return Passenger* - pointer to the passenger.
 */
Passenger* WaitingList::popEconomyClassWaiting()
{
	if(!economyList.empty())
	{
		Passenger* frontPassenger = economyList.front();
		economyList.pop_front();
		return frontPassenger;
	}
	return NULL;
}

/**
 * removes a passenger from a deque.
 * @param name string& - name of passenger to be removed.
 * @param list deque<Passenger*>& deque to remove passenger from.
 * @return bool - true if passenger is removed / false is passenger has not been removed.
 */
bool WaitingList::removePassengerFromList(string name, deque<Passenger*>& list)
{
	for(deque<Passenger*>::iterator it = list.begin(); it != list.end(); ++it)
	{
		if((*it)->getName() == name)
		{
			list.erase(it);
			return true;
		}
	}
	return false;
}

/**
 * search for passenger in all deques.
 * @param name string& - name of passenger to be found.
 * @return bool - true if passenger exists / false if passenger does not exist.
 */
bool WaitingList::searchForPassenger(string& name)
{
	if(searchPassengerList(name, economyList))
		return true;
	else return searchPassengerList(name, firstList);
}

/**
 * searches for a passenger in a specific deque.
 * @param name string& - name of passenger to be found.
 * @param list deque<Passenger*>& deque to be searched.
 * @return bool - true if passenger is found / false is passenger has not been found.
 */
bool WaitingList::searchPassengerList(string name, deque<Passenger*>& list)
{
	for(deque<Passenger*>::iterator it = list.begin(); it != list.end(); ++it)
	{
		if((*it)->getName() == name)
		{
			return true;
		}
	}
	return false;
}

/**
 * gets passenger from the lists.
 * returns NULL is no passenger is found.
 * @param name string& - name of the passenger to be retrieved.
 * @return Passenger* - retrieved passenger.
 */
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

/**
 * gets a passenger from a deque.
 * returns NULL if the passenger is not found.
 * @param name string& - name of passenger to be found.
 * @param list deque<Passenger*>& deque to be searched.
 * @return Passenger* - pointer to the passenger.
 */
Passenger* WaitingList::getPassengerFromList(string& name, deque<Passenger*>& list)
{
	for(deque<Passenger*>::iterator it = list.begin(); it != list.end(); ++it)
	{
		if((*it)->getName() == name)
		{
			return (*it);
		}
	}
	return NULL;
}

/**
 * gets first class deque of passengers.
 * @return constant deque<Passenger*>& - first class deque of pointers to passengers.
 */
const deque<Passenger*>& WaitingList::getFirstClassList()const
{
	return firstList;
}

/**
 * gets economy class deque of passengers.
 * @return constant deque<Passenger*>& - economy class deque of pointers to passengers.
 */
const deque<Passenger*>& WaitingList::getEconomyClassList()const
{
	return economyList;
}



