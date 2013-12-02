#include "Passenger.h"

Passenger::Passenger(string _name)
: name(_name)
{
}

void Passenger::addBooking(Booking& booking)
{
	cout << "ADDBOOKING: " << booking.getSeatType() << endl;
	Booking* bookingPtr = new Booking(booking);
	bookings.insert(pair<string, Booking*>(booking.getFlightNumber(), bookingPtr));
	string flightNumber = "ABC123";
	Booking *found = getBookingByFlightNumber(flightNumber);
	cout << "ADDBOOKING: " << found->getSeatType() << endl;
}

void Passenger::addBooking(string& flightNumber, Seat::Type seat, BookingStatus::Type status)
{
	Booking booking(flightNumber, seat, status);
	bookings.insert(pair<string, Booking*>(booking.getFlightNumber(), &booking));
}

map<string, Booking*>* Passenger::getBookings()
{
	return &bookings;
}

string Passenger::getName() const
{
	return name;
}

Booking* Passenger::getBookingByFlightNumber(string& flightNumber)
{
	map<string, Booking*>::iterator it = bookings.find(flightNumber);
	return it->second;
}
