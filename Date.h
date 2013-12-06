/*
 * Date.h
 *
 *  Created on: 21 Nov 2013
 *      Author: tomto
 */

#ifndef DATE_H_
#define DATE_H_

#include <utility>

using namespace std;

class Date
{
public:

	Date(pair<int, int>& time, const int& day, const int& month, const int& year);

	int getYear() const;
	int getMonth() const;
	int getDay() const;
	pair<int, int> getTime() const;

private:
	pair<int, int> time;
	int day;
	int month;
	int year;
};
#endif /* DATE_H_ */
