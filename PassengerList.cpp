#include "PassengerList.h"

void PassengerList::add(Passenger& passenger)
{
	if(passenger.getSeat() == 'F')
		firstList.push_back(passenger);
	else if(passenger.getSeat() == 'E')
		economyList.push_back(passenger);
}

void PassengerList::remove(string name)
{
	for(int i = 0; i<economyList.size(); i++)
	{
		if(economyList[i].getName() == name)
		{
			cout << "match found!" << endl;
		}
	}
}
