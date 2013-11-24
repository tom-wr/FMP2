#include "FlightList.h"

Flight* FlightList::getFlight(string& flightNumber)
{
	for(vector<Flight>::iterator it = flightList.begin(); it != flightList.end(); ++it)
	{
		if(it->getFlightNumber() == flightNumber)
		{
			return &(*it);
		}
	}
	return NULL;
}

vector<Flight> FlightList::getList() const
{
	return flightList;
}

bool FlightList::checkFlightExists(string flightNumber)
{
	for(vector<Flight>::iterator it = flightList.begin(); it != flightList.end(); ++it)
	{
		if(it->getFlightNumber() == flightNumber)
		{
			return true;
		}
	}
	return false;
}

void FlightList::addFlight(Flight& flight)
{
	flightList.push_back(flight);
}

void FlightList::addPassengerToFlight(Passenger& passenger, string& flightNumber)
{
	Flight* foundFlight = getFlight(flightNumber);
	if(foundFlight)
		foundFlight->addPassenger(passenger);
	else
		cout << "flight not found" << endl;
}

Passenger* FlightList::getPassengerByName(string& name)
{
	for(vector<Flight>::iterator it = flightList.begin(); it != flightList.end(); ++it)
	{
		Passenger* foundPassenger =  it->getFlightPassengerList().getPassenger(name);
		return foundPassenger;
	}
	return NULL;
}
