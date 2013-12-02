#include "ReservationSystem.h"

ReservationSystem::ReservationSystem(FlightList& _flightList, PassengerList& _passengerList)
: flightList(_flightList), passengerList(_passengerList)
{
}

void ReservationSystem::makeReservation(string passengerName)
{
	// get user input holder
	/**/ Seat::Type seat = Seat::FIRST;
	//

	//string passengerName("Jim");
	string flightNumber("ABC123");

	Booking booking(flightNumber, seat, BookingStatus::NONE);
	Flight *flight = flightList.getFlight(flightNumber);
	cout << "About to check if flight exists" << endl;
	if(flight)
	{
		cout << "flight exists" << endl;
		Passenger *passenger = findOrCreatePassenger(passengerName);
		bookSeat(passenger, booking, flight);
	}
	else
	{
		cout << "Flight does not exist!" << endl;
	}
	cout << "end of function" << endl;
}

Passenger* ReservationSystem::createPassenger(string& name)
{
	cout << "creating passenger " << name << endl;
	passengerList.addPassenger(name);
	Passenger *foundPassenger = passengerList.getPassenger(name);
	cout << "got passenger " << foundPassenger->getName() << endl;
	return foundPassenger;
}

Passenger* ReservationSystem::findOrCreatePassenger(string& passengerName)
{
	Passenger *passenger = passengerList.getPassenger(passengerName);
	if(!passenger)
	{
		cout << "passenger does not exist creating fresh." << endl;
		passenger = createPassenger(passengerName);
	}
	cout << "passenger " << passenger->getName()  << " checked/created" << endl;
	return passenger;
}

void ReservationSystem::bookSeat(Passenger* passenger, Booking& booking, Flight* flight)
{
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
			string answer;
			cout << "First class full. Change to Economy?";
			cin >> answer;

			if(answer == "yes")
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
			cout << "adding to waiting list" << endl;
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
