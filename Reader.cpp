/*

 * Reader.cpp
 *
 *  Created on: Nov 23, 2013
 *  Author: RAKEL
 *  */

#include "Reader.h"

Reader::Reader(FlightList& _flightList)
: flightList(_flightList)
{
}

void Reader::readFlightData(string& fileName)
{
	ifstream file(fileName.c_str());
	cout << "reading file!" << endl;
	if (file.is_open())
	{
		cout<<"file is open" << endl;
		if (file.eof())
		{
			cout << "Error: the file is empty" << endl;
		}
		else
		{
			string line;
			while (!file.eof())
			{
				string s_flightNumber, s_capacity, s_time, s_date;
				int i_Capacity;
				//getline(file, line);
				file >> s_flightNumber >> s_capacity >> s_time >> s_date;
				// print out to test
				cout << s_flightNumber << " " << s_capacity << " " << s_time << " " << s_date << endl;

				if(validateLine(s_flightNumber, s_capacity, s_time, s_date))
				{

					i_Capacity = atoi(s_capacity.c_str());
					Date* date = createFlightDate(s_time, s_date);
					if(validateDateIsFuture(date) && validateDateFormat(date))
					{
						Flight flight(s_flightNumber, i_Capacity, *date);
						flightList.addFlight(flight);
					}
					else
					{
						cout << "Date not valid!" << endl;
					}
				}
				else
				{
					cout << "line not valid" << endl;
				}
			}
		}
		file.close();
	}
}



Date* Reader::createFlightDate(string& time, string& date)
{
	pair<int, int> timep = Utils::splitTimeString(time);
	vector<int> splitDate = Utils::splitDateString(date);
	Date* dateObj = new Date(timep, splitDate[0], splitDate[1], splitDate[2]);
	return dateObj;
}

bool Reader::validateLine(string& flightNumber, string& capacity, string& time, string& date)
{
	if(!Utils::validateFlightNumber(flightNumber))
	{
		cout << "Flight number is invalid" << endl;
		return false;
	}
	else if(!Utils::validateCapacity(capacity))
	{
		cout << "Capacity is invalid" << endl;
		return false;
	}
	else if(!Utils::validateTime(time))
	{
		cout << "Time is invalid" << endl;
		return false;
	}
	else if(!Utils::validateDate(date))
	{
		cout << "Date is invalid" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

bool Reader::validateDateIsFuture(Date* date)
{
	time_t t = time(0);
	struct tm * now = localtime(&t);
	int nowYear = now->tm_year + 1900;
	int nowMonth = now->tm_mon + 1;
	int nowDay = now->tm_mday;
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
