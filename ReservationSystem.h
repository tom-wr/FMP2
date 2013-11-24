/*
 * ReservationSystem.h
 *
 *  Created on: 22 Nov 2013
 *      Author: tomto
 */

#ifndef RESERVATIONSYSTEM_H_
#define RESERVATIONSYSTEM_H_

#include "FlightList.h"
#include "Flight.h"
#include "Passenger.h"

class ReservationSystem
{
public:
	ReservationSystem(FlightList& flightList);
	Flight* findFlight(std::string& flightNumber) const;
	void addPassengerToFlight(Passenger& passenger, string& flight);
	FlightList getFlightList() const;
private:
	FlightList flightList;
};
#endif /* RESERVATIONSYSTEM_H_ */
