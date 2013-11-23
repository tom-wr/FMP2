//
//  Flight.cpp
//  Airline
//
//  Created by rachael daminabo on 20/11/2013.
//  Copyright (c) 2013 rachael daminabo. All rights reserved.
//

/*
 
 
 */

#include "Flight.h"
Flight::Flight(){}

Flight::Flight(string newFlightNumber, int newcapacity, string newdate,string newtime, PassengerList newWaitingList, PassengerList newPassengerList)
{
	flightNumber = newFlightNumber;
	capacity = newcapacity;
	date = newdate;
    time = newtime;
	waitingList = newWaitingList;
    passengerList= newPassengerList;
}

string Flight::getFlightNumber() const
{
	return flightNumber;
}

int Flight::getFlightCapacity() const
{
	return capacity;
}

string Flight::getFlightDate() const
{
	return date;
}

string Flight::getFlightTime() const
{
	return time;
}
PassengerList Flight::getPassengerList() const
{
	return passengerList;
}

PassengerList Flight::getWaitingList() const
{
	return waitingList;
}
void Flight::setFlightNumber(string num) {
	flightNumber = num;
    
}
void Flight::setFlightCapacity(int cap) {
    
	capacity = cap;
}

void Flight::setFlightDate(string dat)
{
    date= dat;
}


void Flight::setFlightTime(string tim)
{
    time =tim;
}
