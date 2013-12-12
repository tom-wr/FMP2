/** Reader class reads in text files for use in the system.
 * Validation of file input is done as the file is read line by line.
 */

#include "Reader.h"

/**
 * Reader constructor.
 * @param flightList FlightList& - reference to the main flight list.
 */
Reader::Reader(FlightList& _flightList)
: flightList(_flightList)
{
}

/**
 * reads a file into the flight list.
 * @param filename string& - name of file to be read.
 */
void Reader::readFlightData(string& fileName)
{
	/*string fnum("FLYER");
	pair<int, int> testt(10,01);
	Date testDate(testt,10,10,2020);
	Flight testFlight(fnum, 10, testDate);
	flightList.addFlight(testFlight);*/
	ifstream file("FCGDATA.txt", ios::in);
	if (file.is_open())
	{
		if (file.eof())
		{
			UI::outputError(View::errorFileEmpty);
		}
		else
		{
			int flightCount = 0;
			while (!file.eof())
			{
				string s_flightNumber, s_capacity, s_time, s_date;
				int i_Capacity;
				// get strings from file
				file >> s_flightNumber >> s_capacity >> s_time >> s_date;
				// validate line
				if(validateLine(s_flightNumber, s_capacity, s_time, s_date))
				{
					i_Capacity = atoi(s_capacity.c_str());
					// create and validate date
					Date* date = createFlightDate(s_time, s_date);
					if(validateDateIsFuture(date) && validateDateFormat(date))
					{
						// create and add flight
						Flight flight(s_flightNumber, i_Capacity, *date);
						flightList.addFlight(flight);
						flightCount++;
					}
					else
						UI::outputError(View::errorFileDate);
				}
				else
				{
					UI::outputError(View::errorFileLine);
					string entryline(s_flightNumber + " " + s_capacity + " " + s_time + " " + s_date);
					UI::outputs(entryline);
				}
			}
		}
		file.close();
	}
	else
		UI::outputError(View::errorFile);
}

/**
 * splits time and date strings to create a date object.
 * @param time string& - time string to be split.
 * @param date string& - date string to be split.
 * @return Date* - pointer to created date object.
 */
Date* Reader::createFlightDate(string& time, string& date)
{
	pair<int, int> timep = Utils::splitTimeString(time);
	vector<int> splitDate = Utils::splitDateString(date);
	Date* dateObj = new Date(timep, splitDate[0], splitDate[1], splitDate[2]);
	return dateObj;
}

/**
 * validates a date to see if its not in the past.
 * @param date Date* - pointer to date object to be tested.
 * @return bool - true if valid / false if not valid.
 */
bool Reader::validateLine(string& flightNumber, string& capacity, string& time, string& date)
{
	if(!Utils::validateFlightNumber(flightNumber))
	{
		return false;
	}
	else if(!Utils::validateCapacity(capacity))
	{
		return false;
	}
	else if(!Utils::validateTime(time))
	{
		return false;
	}
	else if(!Utils::validateDate(date))
	{
		return false;
	}
	else
	{
		return true;
	}
}

/**
 * validates a date to see if it's in the correct format dd/mm/yyyy.
 * @param date Date* - pointer to date object to be tested.
 * @return bool - true if valid / false if not valid.
 */
bool Reader::validateDateIsFuture(Date* date)
{
	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);
	int nowYear = now.tm_year + 1900;
	int nowMonth = now.tm_mon + 1;
	int nowDay = now.tm_mday;
	int flightYear = date->getYear();
	int flightMonth = date->getMonth();
	int flightDay = date->getDay();

	if(flightYear < nowYear)
	{
		return false;
	}
	else if(flightYear == nowYear)
	{
		if(flightMonth < nowMonth)
		{
			return false;
		}
		else if(flightMonth == nowMonth && flightDay <= nowDay)
		{
			return false;
		}
	}
	return true;
}

/**
 * validates a date to see if it's in the correct format dd/mm/yyyy.
 * @param date Date* - pointer to date object to be tested.
 * @return bool - true if valid / false if not valid.
 */
bool Reader::validateDateFormat(Date* date)
{
	int year = date->getYear();
	int month = date->getMonth();
	int day = date->getDay();
	bool leapYear = false;

	if( (year%4 == 0 && !(year%100 == 0)) || year%400 == 0 )
		leapYear = true;

	if(month > 12 || month < 1)
		return false;

	if(day > getMaxDayForMonth(month, leapYear) || day < 1)
	{
		return false;
	}

	return true;
}

/**
 * gets maximum number of days in a given month.
 * @param month int - month of year that is being tested.
 * @return leapYear bool - true if year being tested is a leap year.
 */
int Reader::getMaxDayForMonth(int month, bool leapYear)
{
	switch(month)
	{
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if(leapYear)
			return 29;
		else
			return 28;
	default:
		return 31;
	}
}
