/*
 * BookedList.cpp
 *
 *  Created on: 26 Nov 2013
 *      Author: tomto
 */

#include "BookedList.h"

BookedList::BookedList(int capacity)
{
	firstCapacity = (capacity * 0.10);
	economyCapacity = capacity - firstCapacity;
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



