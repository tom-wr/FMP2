#include "FlightPassengerList.h"

FlightPassengerList::FlightPassengerList(int capacity)
{
	firstCapacity = (capacity * 0.10);
	economyCapacity = capacity - firstCapacity;
}

bool FlightPassengerList::add(Passenger& passenger)
{
	if( (passenger.getSeat() == Seat::FIRST) && (firstList.size() < firstCapacity) )
	{
		firstList.push_back(passenger);
		return true;
	}
	else if( (passenger.getSeat() == Seat::ECONOMY) && (economyList.size() < economyCapacity) )
	{
		economyList.push_back(passenger);
		return true;
	}
	return false;
}

int FlightPassengerList::getFirstCapacity()
{
	return firstCapacity;
}

int FlightPassengerList::getEconomyCapacity()
{
	return economyCapacity;
}
