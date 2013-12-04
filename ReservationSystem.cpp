#include "ReservationSystem.h"

ReservationSystem::ReservationSystem(FlightList& _flightList, PassengerList& _passengerList)
: flightList(_flightList), passengerList(_passengerList)
{
}

void ReservationSystem::makeReservation(string passengerName)
{
	// get user input holder
	/**/ Seat::Type seat = Seat::FIRST;
	string flightNumber("ABC123");

	Booking booking(flightNumber, seat, BookingStatus::NONE);
	Flight *flight = flightList.getFlight(flightNumber);
	if(flight)
	{
		Passenger *passenger = findOrCreatePassenger(passengerName);
		if( !checkDoubleBooking(passenger , flightNumber) )
		{
			bookSeat(passenger, booking, flight);
		}
	}
	else
		cout << "Flight does not exist!" << endl;
}

Passenger* ReservationSystem::createPassenger(string& name)
{
	passengerList.addPassenger(name);
	Passenger *foundPassenger = passengerList.getPassenger(name);
	return foundPassenger;
}

Passenger* ReservationSystem::findOrCreatePassenger(string& passengerName)
{
	Passenger *passenger = passengerList.getPassenger(passengerName);
	if(!passenger)
	{
		passenger = createPassenger(passengerName);
	}
	return passenger;
}

void ReservationSystem::bookSeat(Passenger* passenger, Booking& booking, Flight* flight)
{
	cout << passenger->getName() << endl;
	cout << flight->getCapacity() << endl;
	Seat::Type seat = booking.getSeatType();
	if(flight->checkSeatIsAvailable(seat))
	{
		cout << "booking passenger straight on flight!" << endl;
		bookPassengerOnFlight(passenger, booking, flight);
	}

	else
	{
		cout << "Seat unavailable for chosen class!" << endl;
		// if first class seat requested ask to change class if economy is available
		if(seat == Seat::FIRST && flight->checkSeatIsAvailable(Seat::ECONOMY))
		{
			string question("First class is fully booked. Would the passenger like to fly economy instead?");
			if(UI::inputYesNo(question))
			{
				booking.setSeatType(Seat::ECONOMY);
				bookPassengerOnFlight(passenger, booking, flight);
			}
			else
			{
				queuePassengerOnFlight(passenger, booking, flight);
			}
		}
		else
		{
			queuePassengerOnFlight(passenger, booking, flight);
		}
	}
}

void ReservationSystem::bookPassengerOnFlight(Passenger* passenger, Booking& booking, Flight* flight)
{
	booking.setStatus(BookingStatus::BOOKED);
	passenger->addBooking(booking);
	flight->addPassengerToBookedList(passenger, booking.getSeatType());
}

void ReservationSystem::queuePassengerOnFlight(Passenger* passenger, Booking& booking, Flight* flight)
{
	booking.setStatus(BookingStatus::WAITING);
	passenger->addBooking(booking);
	flight->addPassengerToWaitingList(passenger, booking.getSeatType());
}

bool ReservationSystem::dateIsValid(Passenger* passenger, Date& date)
{
	map<string, Booking*> *bookings = passenger->getBookings();
	map<string, Booking*>::iterator it;
	for(it = (*bookings).begin(); it != (*bookings).end(); ++it)
	{
		cout << it->first << endl;
	}
	return true;
}

bool ReservationSystem::checkDoubleBooking(Passenger* passenger, string& flightNumber)
{
	Booking *booking = passenger->getBookingByFlightNumber(flightNumber);
	if(booking != NULL)
	{
		cout << "!!!\tPassenger already booked on flight. Double booking not allowed." << endl;
		return true;
	}
	else
	{
		if(checkDateOverlap())
		{
			cout << "!!!\tPassenger already booked on flight within 24 hours." << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool ReservationSystem::checkDateOverlap()
{
	return false;
}
