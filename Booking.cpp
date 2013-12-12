/** Booking for a flight has a flight number seat type and booking status.
 */


#include "Booking.h"

/**
 * Booking constructor.
 * @param _flightNumber string flight number of booking
 * @param _seat Seat::Type type of seat
 * @param _BookingStatus::Type status of the booking
 */
Booking::Booking(string _flightNumber, Seat::Type _seat, BookingStatus::Type _status)
: flightNumber(_flightNumber), seat(_seat), status(_status)
{
}

/**
 * Booking constructor. The booking status is set at none by default.
 * @param _flightNumber string flight number of booking
 * @param _seat Seat::Type type of seat
 */
Booking::Booking(string _flightNumber, Seat::Type _seat)
: flightNumber(_flightNumber), seat(_seat), status(BookingStatus::NONE)
{
}

/**
 * Booking destructor.
 */
Booking::~Booking()
{
}


/**
 * gets the seat type of the booking
 * @return Seat::Type - the seat type
 */
Seat::Type Booking::getSeatType() const
{
	return seat;
}

/**
 * sets the seat type of the booking
 * @param seat Seat::Type - the new seat type
 */
void Booking::setSeatType(Seat::Type _seat)
{
	seat = _seat;
}

/**
 * gets the flight number of the booking
 * @return string - the flight number
 */
string Booking::getFlightNumber() const
{
	return flightNumber;
}

/**
 * gets the status of the booking
 * @return BookingStatus::Type - the status
 */
BookingStatus::Type Booking::getStatus() const
{
	return status;
}

/**
 * sets the seat type of the booking
 * @param status BookingStatus::Type - the new status
 */
void Booking::setStatus(BookingStatus::Type _status)
{
	status = _status;
}
