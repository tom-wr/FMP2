/*
 * Utils.cpp
 *
 *  Created on: 3 Dec 2013
 *      Author: tomto
 */

#include "Utils.h"

namespace Utils
{
	string toUppercase(string& str)
	{
		string out;
		std::transform(str.begin(), str.end(), std::back_inserter(out),(int (*)(int))std::toupper);
		return out;
	}

	bool checkStringLength(string& str, int min, int max)
	{
		int len = str.length();
		if( len < min || len > max )
		{
			cout << "Error: string length is out of bounds" << endl;
			return false;
		}
		return true;
	}

	bool stringIsDigit(string& str)
	{
	   for (int i=0; i < str.length(); i++)
	   {
			if(!isdigit(str[i]))
			{
				 cout<<"Error:string is not digit"<<endl;
				 return false;
			}
	   }
	   return true;
	}

	bool stringIsAlNum(string& str)
	{
	   for (int i=0; i < str.length(); i++)
	   {
			if(!isalnum(str[i]))
			{
				 cout<<"Error:string is not alphanumeric"<<endl;
				 return false;
			}
	   }
	   return true;
	}

	bool stringIsAlpha(string& str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if(!isalpha(str[i]))
			{
				cout << "Error: string is not alpha" << endl;
				return false;
			}
		}
		return true;
	}

	bool stringIsAlphaSpace(string& str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if(!isspace(str[i]))
			{
				if(!isalpha(str[i]))
				{
					cout << "Error: string is not alpha or space" << endl;
					return false;
				}
			}
		}
		return true;
	}


	bool validateFlightNumber(string& flightNumber)
	{
		if(checkStringLength(flightNumber, 5, 5) && stringIsAlNum(flightNumber))
			return true;
		return false;
	}

	bool validateCapacity(string& capacity)
	{
		if(stringIsDigit(capacity))
		{
			int icapacity = atoi(capacity.c_str());
			if(icapacity >= 10)
			{
				return true;
			}
		}
		return false;
	}

	bool validateTime(string& time)
	{
		if(checkStringLength(time, 4, 4) && stringIsDigit(time))
		{
			int itime = atoi(time.c_str());
			cout << itime << endl;
			cout << floor(itime/1000) << " " << ((itime%100)/10) << endl;
			int hours = (int)floor(itime/1000);
			int minutes = (int)floor((itime%100))/10;
			if((hours < 3) && (minutes < 6))
				return true;
		}
		return false;
	}

	bool validateDate(string& date)
	{
		if(checkStringLength(date, 8, 8) && stringIsDigit(date))
		{
			return true;
		}
		return false;
	}


	bool validateName(string& name)
	{
		if(stringIsAlphaSpace(name) && checkStringLength(name, 1, 30))
			return true;
		else
			return false;
	}

	vector<int> splitDateString(string& str)
	{
		vector<int> date;
		string day = str.substr(0,2);
		string month = str.substr(2,2);
		string year = str.substr(4,4);
		cout << day << " " << month << " " << year << endl;
		date.push_back(atoi(day.c_str()));
		date.push_back(atoi(month.c_str()));
		date.push_back(atoi(year.c_str()));

		return date;
	}

	pair<int, int> splitTimeString(string& str)
	{
		pair<int, int> timePair;
		string hours = str.substr(0,2);
		string minutes = str.substr(2,2);
		cout << hours << ":" << minutes << endl;
		timePair.first = atoi(hours.c_str());
		timePair.second = atoi(minutes.c_str());
		return timePair;
	}

}


