#include "Date.h"

Date::Date(const int& _time, const int& _day, const int& _month, const int& _year)
: time(_time), day(_day), month(_month), year(_year)
{
}

Date::Date() : year(0), month(0), day(0), time(0)
{

}


int Date::getYear() const
{
	return year;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

int Date::getTime() const
{
	return time;
}

void Date::setDay(int day)
{
	this->day = day;
}

void Date::setMonth(int month)
{
	this->month = month;
}

void Date::setTime(int time)
{
	this->time = time;
}

void Date::setYear(int year)
{
	this->year = year;
}
