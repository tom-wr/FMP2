/** ReservationSystem class controls the creation of bookings and adds passengers on flights.
 * Many checks are made to see if the reservation is valid
 * and if a passenger is allowed to be added to the flight
 */


#include "ReservationSystem.h"

/**
 * ReservationSystem constructor.
 * @param flightList FlightList& reference to the main flight list.
 * @param passengerList PassengerList& reference to the main passengerList.
 */
ReservationSystem::ReservationSystem(FlightList& _flightList, PassengerList& _passengerList)
: flightList(_flightList), passengerList(_passengerList)
{
}

/**
 * makes a reservation for a passenger.
 * user input is required to determine the booking details
 */
void ReservationSystem::makeReservation()
{
	// get user input holder
	/**/
	UI::outputAskPassengerName();
	string passengerName = UI::inputName();

	UI::outputAskFlightNumber();
	string flightNumber = UI::inputFlightNumber();

	UI::outputAskSeatType();
	Seat::Type seat = UI::inputSeatType();
    
	Booking booking(flightNumber, seat, BookingStatus::NONE);
	Flight *flight = flightList.getFlight(flightNumber);
	if(flight)
	{
        
		Passenger *passenger = findOrCreatePassenger(passengerName);
		if( !isDoubleBooking(passenger , flightNumber) && !isDateClash(passenger, flight->getDate()) )
		{
			bookSeat(passenger, booking, flight);
		}
	}
	else
		View::error(View::errorFlightNotFound);
}

/**
 * creates a passenger object with the given name.
 * @param name string& - name of the new passenger.
 * @return Passenger* - pointer to the found passenger.
 */
Passenger* ReservationSystem::createPassenger(string& name)
{
	passengerList.addPassenger(name);
	Passenger *foundPassenger = passengerList.getPassenger(name);
	return foundPassenger;
}


/**
 * searches for and returns a passenger in the passenger list.
 * if a passenger is not found a new one is created.
 * @param name string& - the name of the passenger.
 * @return Passenger* - pointer to the found passenger.
 */
Passenger* ReservationSystem::findOrCreatePassenger(string& passengerName)
{
	Passenger *passenger = passengerList.getPassenger(passengerName);
	if(!passenger)
	{
		passenger = createPassenger(passengerName);
	}
	return passenger;
}

/**
 * books a seat for a passenger on a flight providing the proposed booking passes validity tests.
 * @param passenger Passenger* - passenger to be booked on flight.
 * @param booking Booking& - proposed booking to be created.
 * @param flight Flight* - flight to book the passenger on.
 */
void ReservationSystem::bookSeat(Passenger* passenger, Booking& booking, Flight* flight)
{
	Seat::Type seat = booking.getSeatType();
	if(flight->checkSeatIsAvailable(seat))
	{
		bookPassengerOnFlight(passenger, booking, flight);
	}
	else
	{
		// if first class seat requested ask to change class if economy is available
		if(seat == Seat::FIRST && flight->checkSeatIsAvailable(Seat::ECONOMY))
		{
			View::question(View::q_firstClassFull);
			if(UI::inputYesNo())
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

/**
 * adds a passenger to a flight's booked list.
 * @param passenger Passenger* - passenger to be booked on flight.
 * @param booking Booking& - booking to be given to passenger.
 * @param flight Flight* - flight to book the passenger on.
 */
void ReservationSystem::bookPassengerOnFlight(Passenger* passenger, Booking& booking, Flight* flight)
{
	booking.setStatus(BookingStatus::BOOKED);
	Seat::Type seat = booking.getSeatType();
	passenger->addBooking(booking);
	flight->addPassengerToBookedList(passenger, seat);
    //UI::outputFlightNotification(passenger->getName(), flight->getFlightNumber(), Seat::toString[booking.getSeatType()]);
	View::successAddedToBookedList(passenger->getName(), flight->getFlightNumber(), Seat::toString[seat]);
}

/**
 * adds a passenger to a flights waiting list.
 * @param passenger Passenger* - passenger to be booked on flight.
 * @param booking Booking& - booking to be given to passenger.
 * @param flight Flight* - flight to book the passenger on.
 */
void ReservationSystem::queuePassengerOnFlight(Passenger* passenger, Booking& booking, Flight* flight)
{
	Seat::Type seat = booking.getSeatType();
	booking.setStatus(BookingStatus::WAITING);
	passenger->addBooking(booking);
	flight->addPassengerToWaitingList(passenger, seat);

	View::successAddedToWaitingList(passenger->getName(), flight->getFlightNumber(), Seat::toString[seat]);
}

/**
 * checks if dates are different.
 * @param date Date& - first date to tested.
 * @param bookedDate Date& - second date to be tested.
 * @return bool - true if dates are different / false if dates are the same.
 */
bool ReservationSystem::dateIsDifferent(Date& date, Date& bookedDate)
{
	if(		(date.getYear() == bookedDate.getYear())
       && 	(date.getMonth() == bookedDate.getMonth())
       && 	(date.getDay() == bookedDate.getDay()) )
	{
		return false;
	}
	else
		return true;
}

/**
 * checks if the proposed date of a booking is not on the same day as a passenger's other flights.
 * @param passenger Passenger* - passenger to check.
 * @param date Date& - proposed date to check against.
 * @return bool true if date is valid / false if date is not valid
 */
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

/**
 * check if passenger is already booked a given flight by searching their bookings.
 * @param passenger Passenger* - pointer to passenger to be checked.
 * @param flightNumber string& - flight number to be checked.
 */
bool ReservationSystem::isDoubleBooking(Passenger* passenger, string& flightNumber)
{
	Booking *booking = passenger->getBookingByFlightNumber(flightNumber);
	if(booking)
	{
		View::error(View::errorDoubleBooked);
		return true;
	}
	else
		return false;
}

/**
 * check if the date clashes with the dates of other bookings.
 * @param passenger Passenger* - pointer to passenger to be tested.
 * @param date Date& - date to be tested.
 * @return bool - true if there is a date clash / false if there is not a date clash.
 */
bool ReservationSystem::isDateClash(Passenger* passenger, Date& date)
{
	if(!dateIsValid(passenger, date))
	{
		View::error(View::errorSameDateBooked);
		return true;
	}
	else
		return false;
}

