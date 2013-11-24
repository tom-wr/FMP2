#include "ReservationSystem.h"

ReservationSystem::ReservationSystem(FlightList& _flightList)
: flightList(_flightList)
{
}


void ReservationSystem::addPassengerToFlight(Passenger& passenger, string& flightNumber)
{
	flightList.addPassengerToFlight(passenger, flightNumber);
}

FlightList ReservationSystem::getFlightList()const
{
	return flightList;
}
