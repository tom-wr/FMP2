#include "Date.h"

Date::Date(pair<int, int>& _time, const int& _day, const int& _month, const int& _year)
: time(_time), day(_day), month(_month), year(_year)
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

pair<int, int> Date::getTime() const
{
	return time;
}
