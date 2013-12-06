/*
 * Utils.h
 *
 *  Created on: 3 Dec 2013
 *      Author: tomto
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

using namespace std;

namespace Utils
{
	string toUppercase(string& str);
	bool validateLine(string& flightNumber, string& capacity, string time);
	bool validateFlightNumber(string& flightNumber);
	bool validateCapacity(string& capacity);
	bool validateTime(string& time);
	bool checkStringLength(string& str, int min, int max);
	bool stringIsDigit(string& str);
	bool stringIsAlpha(string& str);
	vector<int> splitDateString(string& str);
	pair<int, int> splitTimeString(string& str);
}


#endif /* UTILS_H_ */
