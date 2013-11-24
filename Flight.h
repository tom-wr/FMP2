#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <string>
#include "Date.h"
#include "FlightPassengerList.h"
#include "PassengerList.h"

using namespace std;

class Flight
{
public:


	Flight(string flightNumber, int capacity, Date& date);

	void addPassenger(Passenger& passenger);
	string getFlightNumber() const;
	int getFlightCapacity() const;
	Date getFlightDate() const;

	PassengerList& getWaitingList();
	FlightPassengerList& getFlightPassengerList();

private:
	string flightNumber;
	int capacity;
	Date date;
	FlightPassengerList flightPassengerList;
	PassengerList waitingList;
};
#endif
