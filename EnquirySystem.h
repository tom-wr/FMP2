/*
 * EnquirySystem.h
 *
 *  Created on: 2 Dec 2013
 *      Author: tomto
 */

#ifndef ENQUIRYSYSTEM_H_
#define ENQUIRYSYSTEM_H_

#include <string>
#include <vector>
#include <iostream>

#include "FlightList.h"
#include "PassengerList.h"
#include "Passenger.h"
#include "BookedList.h"
#include "WaitingList.h"

using namespace std;

class EnquirySystem
{
public:

	EnquirySystem(FlightList& flightList, PassengerList& passengerList);
	void enquireFlightInformation(string& flightNumber);
	void enquirePassengerInformation(string& passengerJim);
private:
	FlightList& flightList;
	PassengerList& passengerList;
	void enquireFlightPassengers(vector<Passenger*> list);
};
#endif /* ENQUIRYSYSTEM_H_ */
