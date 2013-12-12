/** Utils namespace to hold utility functions such as validation and string checking.
 *
 */
#ifndef UTILS_H_
#define UTILS_H_

#include <algorithm>
#include <ctype.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <math.h>
#include <sstream>

using namespace std;

namespace Utils
{
	/*
	 * converts a string into uppercase
	 * @param str string& to be converted to uppercase
	 * @return string - uppercase string
	 */
	string toUppercase(string& str);

	/*
	 * validates a flight number string.
	 * must contain alphanumeric only and be 5 characters long.
	 * @param flightNumber string& - flight number to test.
	 * @return bool - true if valid / false if not valid.
	 */
	bool validateFlightNumber(string& flightNumber);

	/*
	 * validates capacity string.
	 * must contain digits only and be higher than 10.
	 * @param capacity string& - capacity string to check
	 * @return bool - true if valid / false if invalid
	 */
	bool validateCapacity(string& capacity);

	/*
	 * validates time string.
	 * must be 4 characters in length and only digits.
	 * validates hours and minutes are within 24h clock range.
	 * @param time string& - time string to be checked.
	 * @return bool - true if valid / false if invalid
	 */
	bool validateTime(string& time);

	/*
	 * validates date string.
	 * must be 8 characters in length and all digits.
	 * @param date string& - date string to be checked.
	 * @return bool - true if valid / false if invalid.
	 */
	bool validateDate(string& date);

	/*
	 * validates name string.
	 * must be less than 30 characters in length and all alpha characters.
	 * @param name string& name string to be checked.
	 * @return bool - true if valid / false if invalid.
	 */
	bool validateName(string& name);

	/*
	 * checks a string length is within the boundaries set.
	 * @param str string& - string to be checked.
	 * @param min int - the minimum length of the string.
	 * @param max int - the maximum length of the string.
	 * @return bool - true if valid / false if invalid.
	 */
	bool checkStringLength(string& str, int min, int max);

	/*
	 * checks a string contains only digits.
	 * @param str string& - string to be checked.
	 * @return bool.
	 */
	bool stringIsDigit(string& str);

	/*
	 * checks a string contains only alphabetical characters.
	 * @param str string& - string to be checked.
	 * @return bool.
	 */
	bool stringIsAlpha(string& str);

	/*
	 * checks a string contains only alphabetical characters and blank spaces.
	 * @param str string& - string to be checked.
	 * @return bool.
	 */
	bool stringIsAlphaSpace(string& str);

	/*
	 * checks a string contains only alphanumeric characters.
	 * @param str string& - string to be checked.
	 * @return bool.
	 */
	bool stringIsAlNum(string& str);

	/*
	 * splits date string into component parts day, month and year.
	 * returns a vector in the following format {day, month, year}
	 * @param str string& - date string to be split.
	 * @return vector<int> - vector of date components. {day, month, year}
	 */
	vector<int> splitDateString(string& date);

	/*
	 * splits time string into hours and minutes and creates a pair<int, int>
	 * the pair first is the hours and the pair second is the minutes.
	 * @param time string& - time string to be split.
	 * @return pair<int, int> - pair containing the hours as the first and minutes as the second.
	 */
	pair<int, int> splitTimeString(string& time);

	/*
	 * converts an integer to a string.
	 * @param number int - the number to be converted.
	 * @return string -
	 */
	string intToString(int number);
}


#endif /* UTILS_H_ */
