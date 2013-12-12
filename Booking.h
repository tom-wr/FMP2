/** Booking for a flight has a flight number seat type and booking status.
 */

#ifndef BOOKING_H_
#define BOOKING_H_

#include <string>
#include "Seat.h"
#include "BookingStatus.h"

using namespace std;

class Booking
{
public:
	/**
	 * Booking constructor.
	 * @param _flightNumber string flight number of booking
	 * @param _seat Seat::Type type of seat
	 * @param _BookingStatus::Type status of the booking
	 */
	Booking(string _flightNumber, Seat::Type _seat, BookingStatus::Type _status);

	/**
	 * Booking constructor. The booking status is set at none by default.
	 * @param _flightNumber string flight number of booking
	 * @param _seat Seat::Type type of seat
	 */
	Booking(string _flightNumber, Seat::Type _seat);

	/**
	 * Booking destructor.
	 */
	~Booking();

	/**
	 * gets the seat type of the booking
	 * @return Seat::Type - the seat type
	 */
	Seat::Type getSeatType(void) const;

	/**
	 * sets the seat type of the booking
	 * @param seat Seat::Type - the new seat type
	 */
	void setSeatType(Seat::Type seat);

	/**
	 * gets the status of the booking
	 * @return BookingStatus::Type - the status
	 */
	BookingStatus::Type getStatus(void) const;

	/**
	 * sets the seat type of the booking
	 * @param status BookingStatus::Type - the new status
	 */
	void setStatus(BookingStatus::Type status);

	/**
	 * gets the flight number of the booking
	 * @return string - the flight number
	 */
	string getFlightNumber() const;


private:
	// flight number of the booking
	string flightNumber;
	// seat class type of the booking
	Seat::Type seat;
	// status of the booking
	BookingStatus::Type status;
};
#endif /* BOOKING_H_ */
