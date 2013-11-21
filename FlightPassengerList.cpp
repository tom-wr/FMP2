#include "FlightPassengerList.h"

FlightPassengerList::FlightPassengerList(int capacity)
{
	cout << "in constructor: " << capacity << endl;
	firstCapacity = capacity * 0.10;
	cout << firstCapacity << endl;
	economyCapacity = capacity - firstCapacity;
}

void FlightPassengerList::add(Passenger& passenger)
{
	if( (passenger.getSeat() == 'F') && (firstList.size() < firstCapacity) )
			firstList.push_back(passenger);
		else if( (passenger.getSeat() == 'E') && (economyList.size() < economyCapacity) )
			economyList.push_back(passenger);
}

int FlightPassengerList::getFirstCapacity()
{
	cout << "getting first capacity: " << firstCapacity << endl;
	return firstCapacity;
}

int FlightPassengerList::getEconomyCapacity()
{
	return economyCapacity;
}
