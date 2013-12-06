#include "Passenger.h"

Passenger::Passenger(string _name)
: name(_name)
{
}

Passenger::~Passenger()
{
	cout << name << " HAS DIED" << endl;
}

void Passenger::addBooking(Booking& booking)
{
	Booking* bookingPtr = new Booking(booking);
	bookings.insert(pair<string, Booking*>(booking.getFlightNumber(), bookingPtr));
}

void Passenger::addBooking(string& flightNumber, Seat::Type seat, BookingStatus::Type status)
{
	Booking *bookingPtr = new Booking(flightNumber, seat, status);
	bookings.insert(pair<string, Booking*>(flightNumber, bookingPtr));
}

void Passenger::removeBooking(string& flightNumber)
{
	map<string, Booking*>::iterator it = bookings.find(flightNumber);
	bookings.erase(it);
	delete (*it).second;
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
	cout << "- get booking by flight number" << endl;
	if(!bookings.empty())
	{
		cout << "-- bookings is not empty!" << endl;
		map<string, Booking*>::iterator it = bookings.find(flightNumber);
		if(it != bookings.end())
		{
			cout << "-- booking for flight found" << endl;
			return it->second;
		}
	}
	cout << "-- booking for flight not found" << endl;
	return NULL;

}
