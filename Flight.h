//
//  Flight.h
//  Airline
//
//  Created by rachael daminabo on 20/11/2013.
//  Copyright (c) 2013 rachael daminabo. All rights reserved.
//
#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <string>
#include "Date.h"
#include "PassengerList.h"


using namespace std;

class Flight
{
    
public:
	Flight();
	Flight(string flightNumber, int capacity, string date, string time,PassengerList waitingList, PassengerList passengerList);
    
	string getFlightNumber() const;
	int getFlightCapacity() const;
	string getFlightDate() const;
    string getFlightTime() const;
	PassengerList getPassengerList() const;
	PassengerList getWaitingList() const;
	void setFlightNumber(string num);
	void setFlightCapacity(int cap);
	void setFlightDate(string dat);
	void setFlightTime(string tim);
private:
	string flightNumber;
	int capacity;
	string date;
    string time;
	PassengerList passengerList;
	PassengerList waitingList;
};

#endif
