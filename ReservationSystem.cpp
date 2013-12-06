#include "ReservationSystem.h"

ReservationSystem::ReservationSystem(FlightList& _flightList, PassengerList& _passengerList)
: flightList(_flightList), passengerList(_passengerList)
{
}

void ReservationSystem::makeReservation()
{
	// get user input holder
	/**/ Seat::Type seat = Seat::FIRST;
	UI::outputAskPassengerName();
	string passengerName = UI::inputName();
	UI::outputAskFlightNumber();
	string flightNumber = UI::inputFlightNumber();

	Booking booking(flightNumber, seat, BookingStatus::NONE);
	Flight *flight = flightList.getFlight(flightNumber);
	if(flight)
	{
		cout << "Flight exists" << endl;
		Passenger *passenger = findOrCreatePassenger(passengerName);
		if( !isDoubleBooking(passenger , flightNumber) && !isDateClash(passenger, flight->getDate()) )
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

bool ReservationSystem::checkSameNumber(const int& i, const int& j)
{
	if(i == j)
		return true;
	else
		return false;
}

bool ReservationSystem::dateIsDifferent(Date& date, Date& bookedDate)
{
	if(		checkSameNumber(date.getYear(), bookedDate.getYear())
		&& 	checkSameNumber(date.getMonth(), bookedDate.getMonth())
		&& 	checkSameNumber(date.getDay(), bookedDate.getDay()) )
	{
		cout << "date same" << endl;
		return false;
	}
	else if( abs(date.getDay()-bookedDate.getDay()) == 1)
	{
		//checkTimeDifference(date.getTime(), bookedDate.getTime());
	}
	cout << "date different" << endl;
	return true;
}

bool ReservationSystem::dateIsValid(Passenger* passenger, Date& date)
{
	map<string, Booking*> *bookings = passenger->getBookings();
	map<string, Booking*>::iterator it;
	for(it = (*bookings).begin(); it != (*bookings).end(); ++it)
	{
		string flightNumber = it->first;
		Date bookedDate = flightList.getFlight(flightNumber)->getDate();
		if(!dateIsDifferent(date, bookedDate))
			return false;
	}
	return true;
}

bool ReservationSystem::isDoubleBooking(Passenger* passenger, string& flightNumber)
{
	Booking *booking = passenger->getBookingByFlightNumber(flightNumber);
	if(booking)
	{
		cout << "!!!\tPassenger already booked on flight. Double booking not allowed." << endl;
		return true;
	}
	else
		return false;
}

bool ReservationSystem::isDateClash(Passenger* passenger, Date& date)
{
	if(!dateIsValid(passenger, date))
	{
		cout << "!!!\tDate is cannot be on same day as another booked flight." << endl;
		return true;
	}
	else
		return false;
}
