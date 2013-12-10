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

string Date::toString(){
	string s_day, s_month, s_year;

	s_day = intToString(day);
	s_month = intToString(month);
	s_year = intToString(year);

	string out = s_day + "/" + s_month + "/"+ s_year;
	return out;
}

string Date::timeString()
{
	string s_time_hour, s_time_minutes;
	s_time_hour = intToString(time.first);
	s_time_minutes = intToString(time.second);
	if(time.first < 10)
	{
		s_time_hour = "0" + s_time_hour;
	}
	if(time.second < 10)
	{
		s_time_minutes = "0" + s_time_minutes;
	}
	string out = s_time_hour + ":" + s_time_minutes;
	return out;
}

string Date::intToString(int number)
{
	ostringstream ss;
	ss << number;
	return ss.str();
}
