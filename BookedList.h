/** BookedList a waiting list with capacity constraints for the lists.
 *
 * Inherits from WaitingList.
 * First class list has a 10% capacity of the total flight capacity.
 */

#ifndef BOOKEDLIST_H_
#define BOOKEDLIST_H_

#include "WaitingList.h"
#include <math.h> // floor

class BookedList : public WaitingList {
public:
	/**
	 * BookedList constructor
	 * @param capacity int - capacity of the flight
	 */
	BookedList(int capacity);

	/**
	 * get capacity of the first class list
	 * @return int - first class capacity
	 */
	int getFirstCapacity(void);

	/**
	 * get capacity of the first class list
	 * @return int - economy class capacity
	 */
	int getEconomyCapacity(void);

	/**
	 * get size of the first class list
	 * @return int - the size of the first class list
	 */
	int getFirstSize(void);

	/**
	 * get size of the economy class list
	 * @return int - the size of the economy class list
	 */
	int getEconomySize(void);

private:
	// capacity of first class
	int firstCapacity;
	// capacity of second class
	int economyCapacity;
};


#endif /* BOOKEDLIST_H_ */
