/*
 * Date.h
 *
 *  Created on: 21 Nov 2013
 *      Author: tomto
 */

#ifndef DATE_H_
#define DATE_H_

class Date
{
public:

	Date(const int& time, const int& day, const int& month, const int& year);
	Date();

	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getTime() const;

	void setDay(int day);
	void setMonth(int month);
	void setTime(int time);
	void setYear(int year);

private:
	int time;
	int day;
	int month;
	int year;
};
#endif /* DATE_H_ */
