/*
 * ReservationSystem.h
 *
 *  Created on: 28 Nov 2013
 *      Author: tomto
 */

#ifndef RESERVATIONSYSTEM_H_
#define RESERVATIONSYSTEM_H_

#include <string>
#include <map>
#include <vector>

#include "FlightList.h"
#include "PassengerList.h"
#include "Flight.h"
#include "UI.h"

using namespace std;

class ReservationSystem
{
public:
	ReservationSystem(FlightList& _flightList, PassengerList& _passengerList);
	void makeReservation(string passname);
	Passenger* createPassenger(string& name);
	Passenger* findOrCreatePassenger(string& name);
	void bookSeat(Passenger* passenger, Booking& booking, Flight* flight);
	void bookPassengerOnFlight(Passenger* passenger, Booking& booking, Flight* flight);
	void queuePassengerOnFlight(Passenger* passenger, Booking& booking, Flight* flight);

//private
	FlightList& flightList;
	PassengerList& passengerList;
	bool dateIsValid(Passenger* passenger, Date& date);
	bool checkDoubleBooking(Passenger* passenger, string& flightNumber);
	bool checkDateOverlap();
};
#endif /* RESERVATIONSYSTEM_H_ */
