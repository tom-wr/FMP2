/** BookedList a waiting list with capacity constraints for the lists.
 *
 * Inherits from WaitingList.
 * First class list has a 10% capacity of the total flight capacity.
 */

#include "BookedList.h"

/**
 * BookedList constructor.
 * Sets the max first class capacity to 10% of the flight capacity.
 * Economy class capacity is the remaining 90%.
 * @param capacity int - capacity of the flight
 */
BookedList::BookedList(int capacity)
{
	firstCapacity = (int)floor(capacity*0.1);
	economyCapacity = capacity - firstCapacity;
}

/**
 * get capacity of the first class list
 * @return int - first class capacity
 */
int BookedList::getFirstCapacity()
{
	return firstCapacity;
}

/**
 * get capacity of the first class list
 * @return int - economy class capacity
 */
int BookedList::getEconomyCapacity()
{
	return economyCapacity;
}

/**
 * get size of the first class list
 * @return int - the size of the first class list
 */
int BookedList::getFirstSize()
{
	return firstList.size();
}

/**
 * get size of the economy class list
 * @return int - the size of the economy class list
 */
int BookedList::getEconomySize()
{
	return economyList.size();
}



