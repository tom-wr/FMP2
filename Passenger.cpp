/** Passenger class holds the passenger attributes and map of their bookings.
 *
 * The bookings map stores the booking flight number against it's respective Booking object.
 */


#include "Passenger.h"

/**
 * Passenger constructor.
 * @param name string - name of the passenger.
 */
Passenger::Passenger(string _name)
: name(_name)
{
}

/**
 * add a booking to the passenger's booking map.
 * @param booking Booking& - the booking to be added.
 */
void Passenger::addBooking(Booking& booking)
{
	Booking* bookingPtr = new Booking(booking);
	bookings.insert(pair<string, Booking*>(booking.getFlightNumber(), bookingPtr));
}

/**
 * add a booking to the passenger's booking map.
 * @param flightNumber string& - flight number of the booking.
 * @param seat Seat::Type - seat type of the booking.
 * @param status Booking::Type - status of the booking.
 */
void Passenger::addBooking(string& flightNumber, Seat::Type seat, BookingStatus::Type status)
{
	Booking *bookingPtr = new Booking(flightNumber, seat, status);
	bookings.insert(pair<string, Booking*>(flightNumber, bookingPtr));
}

/**
 * remove a booking from the passenger's booking map.
 * @param flightNumber string& - flight number of the booking to be removed.
 */
void Passenger::removeBooking(string& flightNumber)
{
	if(!bookings.empty())
	{
		map<string, Booking*>::iterator it = bookings.find(flightNumber);
		delete (*it).second;
		bookings.erase(it);
	}
}

/**
 * get pointer to the passenger's map of bookings.
 * @return map<string, Booking*>* - pointer to map of bookings.
 */
map<string, Booking*>* Passenger::getBookings()
{
	return &bookings;
}

/**
 * getter for name of the passenger.
 * @return string - name of the passenger.
 */
string Passenger::getName() const
{
	return name;
}

/**
 * get booking from the booking map given the flight number.
 * if no booking if found NULL is returned.
 * @param flightNumber string& - flight number of booking to be returned.
 * @return Booking* - pointer to booking.
 */
Booking* Passenger::getBookingByFlightNumber(string& flightNumber)
{
	if(!bookings.empty())
	{
		map<string, Booking*>::iterator it = bookings.find(flightNumber);
		if(it != bookings.end())
		{
			return it->second;
		}
	}
	return NULL;

}
