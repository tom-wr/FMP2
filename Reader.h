/** Reader class reads in text files for use in the system.
 *
 */

#ifndef READER_H_
#define READER_H_

#include "Flight.h"
#include "FlightList.h"
#include "Date.h"
#include "Utils.h"
#include "UI.h"
#include "View.h"

#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
class Reader {
public:
	/**
	 * Reader constructor.
	 * @param flightList FlightList& - reference to the main flight list.
	 */
	Reader(FlightList& flightList);

	/**
	 * reads a file into the flight list.
	 * @param filename string& - name of file to be read.
	 */
	void readFlightData(string& filename);

//private:
	// Reference to the main flight list.
	FlightList& flightList;

	bool validateLine(string& flightNumber, string& capacity, string& time, string& date);

	/**
	 * validates a date to see if its not in the past.
	 * @param date Date* - pointer to date object to be tested.
	 * @return bool - true if valid / false if not valid.
	 */
	bool validateDateIsFuture(Date* date);

	/**
	 * validates a date to see if it's in the correct format dd/mm/yyyy.
	 * @param date Date* - pointer to date object to be tested.
	 * @return bool - true if valid / false if not valid.
	 */
	bool validateDateFormat(Date* date);

	/**
	 * gets maximum number of days in a given month.
	 * @param month int - month of year that is being tested.
	 * @return leapYear bool - true if year being tested is a leap year.
	 */
	int getMaxDayForMonth(int month, bool leapYear);

	/**
	 * splits time and date strings to create a date object.
	 * @param time string& - time string to be split.
	 * @param date string& - date string to be split.
	 * @return Date* - pointer to created date object.
	 */
	Date* createFlightDate(string& time, string& date);
};

#endif
