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

	bool validateLine(string& flightNumber, string& capacity, string& time)
	{
		validateFlightNumber(flightNumber);
		validateCapacity(capacity);
		validateTime(time);

		return false;
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

	bool validateFlightNumber(string& flightNumber)
	{
		if(checkStringLength(flightNumber, 1, 30))
			return true;
		return false;
	}

	bool stringIsDigit(string& str)
	{
	   for (int i=0; i<str.length(); i++)
	   {
	         if(!isdigit(str[i]))
	         {
	                 cout<<"Error:string is not digit"<<endl;
	                 return false;
	         }
	   }
	   return true;
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
			cout << (itime/1000) << " " << ((itime%100)/10) << endl;
			if((itime/1000 < 3) && ((itime%100)/10 < 6))
				return true;
		}
		return false;
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

}


