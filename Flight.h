#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <string>
#include "Date.h"

using namespace std;

class Flight
{
public:
	Flight(string code, int capacity, string date);

	string getFlightNumber() const;
	int getFlightCapacity() const;
	string getFlightDate() const;

private:
	string code;
	int capacity;
	string date;
};

#endif