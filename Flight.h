/** Flight class holds it's own flight information and passenger lists.
 */
#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <string>
#include <vector>
#include <iostream>

#include "WaitingList.h"
#include "BookedList.h"
#include "Date.h"

using namespace std;

class Flight {
public:
	/**
	 * Flight constructor.
	 * @param flightNumber string& - flight number.
	 * @param capacity int - capacity of flight.
	 * @param date Date& - date of flight.
	 */
	Flight(string& _flightNumber, int _capacity, Date& _date);

	/**
	 * adds a passenger to the booked list given the required seat type.
	 * @param passenger Passenger* - pointer to passenger to add.
	 * @param seat const Seat::Type - seat type indicating which list to add passenger to.
	 */
	void addPassengerToBookedList(Passenger* passenger, const Seat::Type seat);

	/**
	 * adds a passenger to the waiting list given the required seat type.
	 * @param passenger Passenger* - pointer to passenger to add.
	 * @param seat const Seat::Type - seat type indicating which list to add passenger to.
	 */
	void addPassengerToWaitingList(Passenger* passenger, const Seat::Type seat);

	/**
	 * remove passenger from flight.
	 * @param name string& - name of passenger to remove.
	 */
	void removePassenger(string& name);

	/**
	 * checks seat is available in booked list for given seat type.
	 * @param seat Seat::Type - seat type to be check if available.
	 */
	bool checkSeatIsAvailable(Seat::Type seat);

	/**
	 * searches for a passenger on the flight based on their name.
	 * @param passengerName string& - name of passenger to be searched for.
	 */
	bool searchForPassenger(string& passengerName);

	/**
	 * getter for flight number.
	 * @return const string& - flight number of flight.
	 */
	string& getFlightNumber(void);

	/**
	 * getter for flight capacity.
	 * @return const int - capacity of flight.
	 */
	const int getCapacity(void) const;

	/**
	 * getter for flight date.
	 * @return Date& - date of flight.
	 */
	Date& getDate(void);

	/**
	 * getter for waiting list.
	 * @return WaitingList* - pointer to waiting list of flight.
	 */
	WaitingList* getWaitingList(void);

	/**
	 * getter for booked list.
	 * @return BookedList* - pointer to booked list of flight.
	 */
	BookedList* getBookedList(void);

private:
	// flight number
	string flightNumber;
	// flight capacity
	int capacity;
	// flight date
	Date date;

	WaitingList waitingList;
	BookedList bookedList;

	// checks if first class booked list is full.
	bool firstIsFull(void);
	// checks if economy class booked list is full.
	bool economyIsFull(void);
};
#endif /* FLIGHT_H_ */
