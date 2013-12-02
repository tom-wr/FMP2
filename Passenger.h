/*
 * Passenger.h
 *
 *  Created on: 20 Nov 2013
 *      Author: tomto
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <vector>
#include <map>
#include <string>
#include <utility>
#include <iostream>

#include "Seat.h"
#include "Booking.h"

using namespace std;

class Passenger
{
public:
	Passenger(string name);
	string getFlightNumbers() const;
	Seat::Type getSeat(void) const;
	string getName() const;
	void addBooking(Booking& booking);
	void addBooking(string& flightNumber, Seat::Type, BookingStatus::Type);
	map<string, Booking*>* getBookings();
	Booking* getBookingByFlightNumber(string& flightNumber);

private:
	string name;
	map<string, Booking*> bookings;
};
#endif /* PASSENGER_H_ */
