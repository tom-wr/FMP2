/** Passenger class holds the passenger attributes and map of their bookings.
 *
 * The bookings map stores the booking flight number against it's respective Booking object.
 */
#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <vector>
#include <map>
#include <string>
#include <utility> // pair

#include "Seat.h"
#include "Booking.h"

using namespace std;

class Passenger
{
public:
	/**
	 * Passenger constructor.
	 * @param name string - name of the passenger.
	 */
	Passenger(string name);

	/**
	 * getter for name of the passenger.
	 * @return string - name of the passenger.
	 */
	string getName(void) const;

	/**
	 * add a booking to the passenger's booking map.
	 * @param booking Booking& - the booking to be added.
	 */
	void addBooking(Booking& booking);

	/**
	 * add a booking to the passenger's booking map.
	 * @param flightNumber string& - flight number of the booking.
	 * @param seat Seat::Type - seat type of the booking.
	 * @param status Booking::Type - status of the booking.
	 */
	void addBooking(string& flightNumber, Seat::Type seat, BookingStatus::Type status);

	/**
	 * remove a booking from the passenger's booking map.
	 * @param flightNumber string& - flight number of the booking to be removed.
	 */
	void removeBooking(string& flightNumber);

	/**
	 * get pointer to the passenger's map of bookings.
	 * @return map<string, Booking*>* - pointer to map of bookings.
	 */
	map<string, Booking*>* getBookings(void);

	/**
	 * get booking from the booking map given the flight number.
	 * if no booking if found NULL is returned.
	 * @param flightNumber string& - flight number of booking to be returned.
	 * @return Booking* - pointer to booking.
	 */
	Booking* getBookingByFlightNumber(string& flightNumber);

private:
	// passenger name.
	string name;
	// map of bookings - flight number string against respective booking object.
	map<string, Booking*> bookings;
};
#endif /* PASSENGER_H_ */
