/** ReservationSystem class controls the creation of bookings and adds passengers on flights.
 */

#ifndef RESERVATIONSYSTEM_H_
#define RESERVATIONSYSTEM_H_

#include <string>
#include <map>
#include <vector>

#include "FlightList.h"
#include "PassengerList.h"
#include "Flight.h"
#include "UI.h"

using namespace std;

class ReservationSystem
{
public:
	/**
	 * ReservationSystem constructor.
	 * @param flightList FlightList& reference to the main flight list.
	 * @param passengerList PassengerList& reference to the main passengerList.
	 */
	ReservationSystem(FlightList& flightList, PassengerList& passengerList);

	/**
	 * makes a reservation for a passenger.
	 */
	void makeReservation(void);

private:
	// reference to main flight list
	FlightList& flightList;
	// reference to main passenger list
	PassengerList& passengerList;

	/**
	 * creates a passenger object with the given name.
	 * @param name string& - name of the new passenger.
	 * @return Passenger* - pointer to the found passenger.
	 */
	Passenger* createPassenger(string& name);

	/**
	 * searches for and returns a passenger in the passenger list.
	 * if a passenger is not found a new one is created.
	 * @param name string& - the name of the passenger.
	 * @return Passenger* - pointer to the found passenger.
	 */
	Passenger* findOrCreatePassenger(string& name);

	/**
	 * books a seat for a passenger on a flight providing the proposed booking passes validity tests.
	 * @param passenger Passenger* - passenger to be booked on flight.
	 * @param booking Booking& - proposed booking to be created.
	 * @param flight Flight* - flight to book the passenger on.
	 */
	void bookSeat(Passenger* passenger, Booking& booking, Flight* flight);

	/**
	 * adds a passenger to a flight's booked list.
	 * @param passenger Passenger* - passenger to be booked on flight.
	 * @param booking Booking& - booking to be given to passenger.
	 * @param flight Flight* - flight to book the passenger on.
	 */
	void bookPassengerOnFlight(Passenger* passenger, Booking& booking, Flight* flight);

	/**
	 * adds a passenger to a flights waiting list.
	 * @param passenger Passenger* - passenger to be booked on flight.
	 * @param booking Booking& - booking to be given to passenger.
	 * @param flight Flight* - flight to book the passenger on.
	 */
	void queuePassengerOnFlight(Passenger* passenger, Booking& booking, Flight* flight);

	/**
	 * checks if the proposed date of a booking is not on the same day as a passenger's other flights.
	 * @param passenger Passenger* - passenger to check.
	 * @param date Date& - proposed date to check against.
	 * @return bool true if date is valid / false if date is not valid
	 */
	bool dateIsValid(Passenger* passenger, Date& date);

	/**
	 * check if passenger is already booked a given flight by searching their bookings.
	 * @param passenger Passenger* - pointer to passenger to be checked.
	 * @param flightNumber string& - flight number to be checked.
	 */
	bool isDoubleBooking(Passenger* passenger, string& flightNumber);

	/**
	 * check if the date clashes with the dates of other bookings.
	 * @param passenger Passenger* - pointer to passenger to be tested.
	 * @param date Date& - date to be tested.
	 * @return bool - true if there is a date clash / false if there is not a date clash.
	 */
	bool isDateClash(Passenger* passenger, Date& date);

	/**
	 * checks if number is the same // might not be needed.
	 */
	bool checkSameNumber(const int& i, const int& j);

	/**
	 * checks if dates are different.
	 * @param date Date& - first date to tested.
	 * @param bookedDate Date& - second date to be tested.
	 * @return bool - true if dates are different / false if dates are the same.
	 */
	bool dateIsDifferent(Date& date, Date& bookedDate);
};
#endif /* RESERVATIONSYSTEM_H_ */
