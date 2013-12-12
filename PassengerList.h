/** PassengerList class holds vector of passengers active in the system.
 *
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
	/**
	 * PassengerList constructor.
	 */
	PassengerList(void){};

	/**
	 * PassengerList destructor.
	 */
	~PassengerList(void){};

	/**
	 * create a passenger and add to the list.
	 * @param name string - the name of the new passenger.
	 */
	void addPassenger(string name);

	/**
	 * remove passenger from the list.
	 * @param name string& - the name of the passenger to be removed.
	 * @return bool - true if removal successful / false if the removal failed.
	 */
	bool removePassenger(string& name);

	/**
	 * search for passengers in the passenger list.
	 * @param name string& - name of the passenger to search for.
	 * @return bool - true is passenger exists / false if passenger is not found.
	 */
	bool searchForPassenger(string& name);

	/**
	 * get passenger from the passenger list.
	 * returns NULL if not found.
	 * @param name string - name of passenger to be found.
	 * @return Passenger* - pointer to the found passenger. returns NULL is no passenger is found.
	 */
	Passenger* getPassenger(string name);

private:
	// vector of pointers to the passengers.
	vector<Passenger*> passengerList;
};

#endif /* PASSENGERLIST_H_ */
