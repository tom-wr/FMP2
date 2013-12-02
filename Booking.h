/*
 * Booking.h
 *
 *  Created on: 24 Nov 2013
 *      Author: tomto
 */

#ifndef BOOKING_H_
#define BOOKING_H_

#include <string>
#include "Seat.h"
#include "BookingStatus.h"

using namespace std;

class Booking
{
public:
	Booking(string _flightNumber, Seat::Type _seat, BookingStatus::Type _status);
	Booking(string _flightNumber, Seat::Type _seat);
	Seat::Type getSeatType() const;
	void setSeatType(Seat::Type seat);
	BookingStatus::Type getStatus() const;
	void setStatus(BookingStatus::Type);
	string getFlightNumber() const;


private:
	string flightNumber;
	Seat::Type seat;
	BookingStatus::Type status;
};
#endif /* BOOKING_H_ */
