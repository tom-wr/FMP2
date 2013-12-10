/** WaitingList holds first and economy class deques of passengers
 *
 */
#ifndef WAITINGLIST_H_
#define WAITINGLIST_H_

#include <string>
#include <deque>
#include <iostream> //cout

#include "Passenger.h"

using namespace std;

class WaitingList
{
public:
	/**
	 * adds a passenger to the first class list.
	 * @param passenger Passenger* - passenger to be added.
	 */
	void addPassengerToFirst(Passenger* passenger);

	/**
	 * adds a passenger to the economy class list.
	 * @param passenger Passenger* - passenger to be added.
	 */
	void addPassengerToEconomy(Passenger* passenger);

	/**
	 * gets passenger from the lists.
	 * returns NULL is no passenger is found.
	 * @param name string& - name of the passenger to be retrieved.
	 * @return Passenger* - retrieved passenger.
	 */
	Passenger* getPassenger(string& name);

	/**
	 * gets first class deque of passengers.
	 * @return constant deque<Passenger*>& - first class deque of pointers to passengers.
	 */
	const deque<Passenger*>& getFirstClassList(void)const;

	/**
	 * gets economy class deque of passengers.
	 * @return constant deque<Passenger*>& - economy class deque of pointers to passengers.
	 */
	const deque<Passenger*>& getEconomyClassList(void)const;

	/**
	 * removes a passenger from the deques.
	 * @param name string - name of the passenger to be removed.
	 */
	virtual void removePassenger(string name);

	/**
	 * search for passenger in the deques.
	 * @param name string& - name of passenger to be found.
	 * @return bool - true if passenger exists / false if passenger does not exist.
	 */
	virtual bool searchForPassenger(string& name);

	/**
	 * gets and erases the first element from the first class deque.
	 * returns NULL if the deque is empty.
	 * @return Passenger* - pointer to the passenger.
	 */
	virtual Passenger* popFirstClassWaiting(void);

	/**
	 * gets and erases the first element from the economy class deque.
	 * returns NULL if the deque is empty.
	 * @return Passenger* - pointer to the passenger.
	 */
	virtual Passenger* popEconomyClassWaiting(void);

	/**
	 * WaitingList destructor.
	 */
	virtual ~WaitingList(void){};

protected:
	// queue for first class
	deque<Passenger*> firstList;
	// queue for economy class
	deque<Passenger*> economyList;

	/**
	 * gets a passenger from a deque.
	 * returns NULL if the passenger is not found.
	 * @param name string& - name of passenger to be found.
	 * @param list deque<Passenger*>& deque to be searched.
	 * @return Passenger* - pointer to the passenger.
	 */
	Passenger* getPassengerFromList(string& name, deque<Passenger*>& list);

	/**
	 * removes a passenger from a deque.
	 * @param name string& - name of passenger to be removed.
	 * @param list deque<Passenger*>& deque to remove passenger from.
	 * @return bool - true if passenger is removed / false is passenger has not been removed.
	 */
	bool removePassengerFromList(string name, deque<Passenger*>& list);

	/**
	 * searches for a passenger in a deque.
	 * @param name string& - name of passenger to be found.
	 * @param list deque<Passenger*>& deque to be searched.
	 * @return bool - true if passenger is found / false is passenger has not been found.
	 */
	bool searchPassengerList(string name, deque<Passenger*>& list);
};


#endif /* WAITINGLIST_H_ */
