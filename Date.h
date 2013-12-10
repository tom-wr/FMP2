/** Date class to hold time, day, month and year.
 */

#ifndef DATE_H_
#define DATE_H_

#include <utility> // pair
#include <string>
#include <stdlib.h> // itoa
#include <sstream>

using namespace std;

class Date
{
public:
	/**
	 * Date constructor.
	 * @param time a pair of integers representing time containing the hours as the first and minutes as the second.
	 * @param day a constant integer
	 * @param month a constant integer
	 * @param year a constant integer
	 */
	Date(pair<int, int>& time, const int& day, const int& month, const int& year);
	/**
	 * gets the date's year
	 * @return int - the date's year
	 */
	int getYear() const;
	/**
	 * gets the date's month
	 * @return int - the date's month
	 */
	int getMonth() const;
	/**
	 * gets the date's day
	 * @return int - the date's day
	 */
	int getDay() const;
	/**
	 * gets the date's time
	 * @return pair<int, int> - the date's time
	 */
	pair<int, int> getTime() const;

	string toString();
	string intToString(int number);
	string timeString();

private:
	pair<int, int> time;
	int day;
	int month;
	int year;
};
#endif /* DATE_H_ */
