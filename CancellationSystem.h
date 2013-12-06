/*
 * CancellationSystem.h
 *
 *  Created on: 2 Dec 2013
 *      Author: tomto
 */

#ifndef CANCELLATIONSYSTEM_H_
#define CANCELLATIONSYSTEM_H_

#include <string>
#include <vector>
#include <iostream>

#include "FlightList.h"
#include "PassengerList.h"
#include "Flight.h"
#include "Passenger.h"
#include "UI.h"

class CancellationSystem
{
public:
	CancellationSystem(FlightList& flightList, PassengerList& passengerList);
	void makeCancellation();
private:
	FlightList& flightList;
	PassengerList& passengerList;

	void transferPassengers(Flight* flight, Seat::Type seat);
	void makeTransfer();
};
#endif /* CANCELLATIONSYSTEM_H_ */
