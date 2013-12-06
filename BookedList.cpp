/*
 * BookedList.cpp
 *
 *  Created on: 26 Nov 2013
 *      Author: tomto
 */

#include "BookedList.h"

BookedList::BookedList(int capacity)
{
	cout << "full capacity: " << capacity << endl;
	firstCapacity = (int)floor(capacity*0.1);
	cout << "First capacity: " << firstCapacity << endl;
	economyCapacity = capacity - firstCapacity;
	cout << "Economy capacity: " << economyCapacity <<endl;
}

int BookedList::getFirstCapacity()
{
	return firstCapacity;
}

int BookedList::getEconomyCapacity()
{
	return economyCapacity;
}

int BookedList::getFirstSize()
{
	return firstList.size();
}

int BookedList::getEconomySize()
{
	return economyList.size();
}



