#include "Booking.h"

Booking::Booking(string _flightNumber, Seat::Type _seat, BookingStatus::Type _status)
: flightNumber(_flightNumber), seat(_seat), status(_status)
{
}

Booking::~Booking()
{
	cout << "DEATH TO BOOKINGS!" << endl;
}

Booking::Booking(string _flightNumber, Seat::Type _seat)
: flightNumber(_flightNumber), seat(_seat), status(BookingStatus::NONE)
{
}

Seat::Type Booking::getSeatType() const
{
	return seat;
}

void Booking::setSeatType(Seat::Type _seat)
{
	seat = _seat;
}

string Booking::getFlightNumber() const
{
	return flightNumber;
}

BookingStatus::Type Booking::getStatus() const
{
	return status;
}
void Booking::setStatus(BookingStatus::Type _status)
{
	status = _status;
}
