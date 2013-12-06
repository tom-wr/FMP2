/*
 * BookedList.h
 *
 *  Created on: 26 Nov 2013
 *      Author: tomto
 */

#ifndef BOOKEDLIST_H_
#define BOOKEDLIST_H_

#include "WaitingList.h"
#include <math.h>

class BookedList : public WaitingList {
public:
	BookedList(int capacity);
	int getFirstCapacity(void);
	int getEconomyCapacity(void);
	int getFirstSize();
	int getEconomySize();
private:
	int firstCapacity;
	int economyCapacity;
};


#endif /* BOOKEDLIST_H_ */
