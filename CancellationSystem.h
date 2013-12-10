/** CancellationSystem controls the removal and transference of passengers in the system.
 */
#ifndef CANCELLATIONSYSTEM_H_
#define CANCELLATIONSYSTEM_H_

#include <string>
#include <vector>
#include <iostream> // cout

#include "FlightList.h"
#include "PassengerList.h"
#include "Flight.h"
#include "Passenger.h"
#include "UI.h"

using namespace std;

class CancellationSystem
{
public:
	/**
	 * CancellationSystem constructor.
	 * @param flightList FlightList - reference to list of flights
	 * @param passengerList PassengerList - reference to list of passengers
	 */
	CancellationSystem(FlightList& flightList, PassengerList& passengerList);
	/**
	 * cancels a passenger's booking from a flight
	 */
	void makeCancellation(void);
private:
	// reference to flight list
	FlightList& flightList;
	// reference to passenger list
	PassengerList& passengerList;

	/**
	 * Transfers passengers from waiting list to booked list of a flight.
	 * Which list type is indicated by the seat type parameter
	 * @param flight Flight* - pointer to flight
	 * @param seat Seat::Type - which seat type list to be operated on
	 */
	void transferPassengers(Flight* flight, Seat::Type seat);
};
#endif /* CANCELLATIONSYSTEM_H_ */
