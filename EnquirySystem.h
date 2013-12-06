/*
 * EnquirySystem.h
 *
 *  Created on: 2 Dec 2013
 *      Author: tomto
 */

#ifndef ENQUIRYSYSTEM_H_
#define ENQUIRYSYSTEM_H_

#include <string>
#include <deque>
#include <iostream>
#include <map>

#include "FlightList.h"
#include "PassengerList.h"
#include "Passenger.h"
#include "BookedList.h"
#include "WaitingList.h"
#include "UI.h"

using namespace std;

class EnquirySystem
{
public:

	EnquirySystem(FlightList& flightList, PassengerList& passengerList);
	void enquireFlightInformation();
	void enquirePassengerInformation();
private:
	FlightList& flightList;
	PassengerList& passengerList;
	void enquireFlightPassengers(deque<Passenger*> list);
};
#endif /* ENQUIRYSYSTEM_H_ */
