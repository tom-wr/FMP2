/** Utils namespace to hold utility functions such as validation and string checking.
 *
 */

#include "Utils.h"

namespace Utils
{
	/*
	 * converts a string into uppercase
	 * @param str string& to be converted to uppercase
	 * @return string - uppercase string
	 */
	string toUppercase(string& str)
	{
		string out;
		std::transform(str.begin(), str.end(), std::back_inserter(out),(int (*)(int))::toupper);
		return out;
	}

	/*
	 * checks a string length is within the boundaries set.
	 * @param str string& - string to be checked.
	 * @param min int - the minimum length of the string.
	 * @param max int - the maximum length of the string.
	 * @return bool - true if valid / false if invalid.
	 */
	bool checkStringLength(string& str, int min, int max)
	{
		int len = str.length();
		if( len < min || len > max )
		{
			return false;
		}
		return true;
	}

	/*
	 * checks a string contains only digits.
	 * @param str string& - string to be checked.
	 * @return bool.
	 */
	bool stringIsDigit(string& str)
	{
	   for (int i = 0; i < str.length(); i++)
	   {
			if(!isdigit(str[i]))
			{
				 return false;
			}
	   }
	   return true;
	}

	/*
	 * checks a string contains only alphanumeric characters.
	 * @param str string& - string to be checked.
	 * @return bool.
	 */
	bool stringIsAlNum(string& str)
	{
	   for (int i=0; i < str.length(); i++)
	   {
			if(!isalnum(str[i]))
			{
				 return false;
			}
	   }
	   return true;
	}

	/*
	 * checks a string contains only alphabetical characters.
	 * @param str string& - string to be checked.
	 * @return bool.
	 */
	bool stringIsAlpha(string& str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if(!isalpha(str[i]))
			{
				return false;
			}
		}
		return true;
	}

	/*
	 * checks a string contains only alphabetical characters and blank spaces.
	 * @param str string& - string to be checked.
	 * @return bool.
	 */
	bool stringIsAlphaSpace(string& str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if(!isspace(str[i]))
			{
				if(!isalpha(str[i]))
				{
					return false;
				}
			}
		}
		return true;
	}

	/*
	 * validates a flight number string.
	 * must contain alphanumeric only and be 5 characters long.
	 * @param flightNumber string& - flight number to test.
	 * @return bool - true if valid / false if not valid.
	 */
	bool validateFlightNumber(string& flightNumber)
	{
		if(checkStringLength(flightNumber, 5, 5) && stringIsAlNum(flightNumber))
			return true;
		return false;
	}

	/*
	 * validates capacity string.
	 * must contain digits only and be higher than 10.
	 * @param capacity string& - capacity string to check
	 * @return bool - true if valid / false if invalid
	 */
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

	/*
	 * validates time string.
	 * must be 4 characters in length and only digits.
	 * validates hours and minutes are within 24h clock range.
	 * @param time string& - time string to be checked.
	 * @return bool - true if valid / false if invalid
	 */
	bool validateTime(string& time)
	{
		if(checkStringLength(time, 4, 4) && stringIsDigit(time))
		{
			int itime = atoi(time.c_str());
			int hours = (int)floor(itime/1000);
			int minutes = (int)floor((itime%100))/10;
			if((hours < 3) && (minutes < 6))
				return true;
		}
		return false;
	}

	/*
	 * validates date string.
	 * must be 8 characters in length and all digits.
	 * @param date string& - date string to be checked.
	 * @return bool - true if valid / false if invalid.
	 */
	bool validateDate(string& date)
	{
		if(checkStringLength(date, 8, 8) && stringIsDigit(date))
		{
			return true;
		}
		return false;
	}

	/*
	 * validates name string.
	 * must be less than 30 characters in length and all alpha characters.
	 * @param name string& name string to be checked.
	 * @return bool - true if valid / false if invalid.
	 */
	bool validateName(string& name)
	{
		if(stringIsAlphaSpace(name) && checkStringLength(name, 1, 30))
			return true;
		else
			return false;
	}

	/*
	 * splits date string into component parts day, month and year.
	 * returns a vector in the following format {day, month, year}
	 * @param str string& - date string to be split.
	 * @return vector<int> - vector of date components. {day, month, year}
	 */
	vector<int> splitDateString(string& str)
	{
		vector<int> date;
		string day = str.substr(0,2);
		string month = str.substr(2,2);
		string year = str.substr(4,4);
		date.push_back(atoi(day.c_str()));
		date.push_back(atoi(month.c_str()));
		date.push_back(atoi(year.c_str()));

		return date;
	}

	/*
	 * splits time string into hours and minutes and creates a pair<int, int>
	 * the pair first is the hours and the pair second is the minutes.
	 * @param time string& - time string to be split.
	 * @return pair<int, int> - pair containing the hours as the first and minutes as the second.
	 */
	pair<int, int> splitTimeString(string& str)
	{
		pair<int, int> timePair;
		string hours = str.substr(0,2);
		string minutes = str.substr(2,2);
		timePair.first = atoi(hours.c_str());
		timePair.second = atoi(minutes.c_str());
		return timePair;
	}

	/*
	 * converts an integer to a string.
	 * @param number int - the number to be converted.
	 * @return string -
	 */
	string intToString(int number)
	{
		ostringstream ss;
		ss << number;
		return ss.str();
	}

}


