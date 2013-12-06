/*
 * Flight.h
 *
 *  Created on: 28 Nov 2013
 *      Author: tomto
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <string>
#include <vector>
#include <iostream>

#include "WaitingList.h"
#include "BookedList.h"
#include "Date.h"

using namespace std;

class Flight {
public:
	Flight(string& _flightNumber, const int _capacity, Date& _date);
	void addPassengerToBookedList(Passenger* passenger, const Seat::Type seat);
	void addPassengerToWaitingList(Passenger* passenger, const Seat::Type seat);
	void removePassenger(string& name);
	bool checkSeatIsAvailable(Seat::Type seat);
	bool searchForPassenger(string& passengerName);

	const string& getFlightNumber() const;
	const int getCapacity() const;
	Date& getDate();
	WaitingList* getWaitingList();
	BookedList* getBookedList();

	 void setFlightNumber(string _flightNumber);
	 void setFlightCapacity(const int _capacity);
	 //void setFlightTime(times);
	 void setFlightDate(Date& _date);

private:
	string flightNumber;
	const int capacity;
	Date date;

	WaitingList waitingList;
	BookedList bookedList;

	bool firstIsFull();
	bool economyIsFull();
};
#endif /* FLIGHT_H_ */
