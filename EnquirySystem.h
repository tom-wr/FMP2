/** EnquirySystem class controls queries for passenger and flight information.
 */

#ifndef ENQUIRYSYSTEM_H_
#define ENQUIRYSYSTEM_H_

#include <string>
#include <deque>
#include <map>

#include "FlightList.h"
#include "PassengerList.h"
#include "Passenger.h"
#include "BookedList.h"
#include "WaitingList.h"
#include "UI.h"

using namespace std;

class EnquirySystem
{
public:
	/**
	 * EnquirySystem constructor.
	 * @param flightList FlightList- reference to the flight list.
	 * @param passengerList PassengerList - reference to the passenger list.
	 */
	EnquirySystem(FlightList& flightList, PassengerList& passengerList);

	/**
	 * queries flight information based on user input
	 * and displays information.
	 */
	void enquireFlightInformation(void);

	/**
	 * queries passenger information based on user input
	 * and displays information.
	 */
	void enquirePassengerInformation(void);
private:
	// reference to the flight list.
	FlightList& flightList;
	// reference to the passenger list.
	PassengerList& passengerList;

	/*
	 * displays details of passengers by looping through a given
	 * deque of passengers.
	 * @param list deque<Passenger*> - deque of Passengers to be enquired
	 */
	void enquireFlightPassengers(deque<Passenger*> list);
};
#endif /* ENQUIRYSYSTEM_H_ */
