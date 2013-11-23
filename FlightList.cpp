#include "FlightList.h"


FlightList::FlightList(){}

// Add a flight to the list
void FlightList::add(Flight& flight)
{
	flightList.push_back(flight);
}
