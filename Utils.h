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

using namespace std;

namespace Utils
{
	string toUppercase(string& str);
	bool validateFlightNumber(string& flightNumber);
	bool validateCapacity(string& capacity);
	bool validateTime(string& time);
	bool validateDate(string& date);
	bool validateName(string& name);
	bool checkStringLength(string& str, int min, int max);
	bool stringIsDigit(string& str);
	bool stringIsAlpha(string& str);
	bool stringIsAlphaBlank(string& str);
	bool stringIsAlNum(string& str);
	vector<int> splitDateString(string& str);
	pair<int, int> splitTimeString(string& str);
}


#endif /* UTILS_H_ */
