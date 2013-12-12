/** Date class to hold time, day, month and year.
 */

#include "Date.h"

/**
 * Date constructor.
 * @param time a pair of integers representing time containing the hours as the first and minutes as the second.
 * @param day a constant integer
 * @param month a constant integer
 * @param year a constant integer
 */
Date::Date(pair<int, int>& _time, const int& _day, const int& _month, const int& _year)
: time(_time), day(_day), month(_month), year(_year)
{
}

/**
 * gets the date's year
 * @return int - the date's year
 */
int Date::getYear() const
{
	return year;
}

/**
 * gets the date's month
 * @return int - the date's month
 */
int Date::getMonth() const
{
	return month;
}

/**
 * gets the date's day
 * @return int - the date's day
 */
int Date::getDay() const
{
	return day;
}

/**
 * gets the date's time
 * @return pair<int, int> - the date's time
 */
pair<int, int> Date::getTime() const
{
	return time;
}

/*
 * converts the date to a string in the form dd/mm/yyyy.
 * @return string - date string dd/mm/yyyy.
 */
string Date::toString(){
	string s_day, s_month, s_year;

	s_day = Utils::intToString(day);
	s_month = Utils::intToString(month);
	s_year = Utils::intToString(year);

	string out = s_day + "/" + s_month + "/"+ s_year;
	return out;
}

/*
 * converts the time into a string in the form hh:mm.
 * @return string - time string hh:mm.
 */
string Date::timeString()
{
	string s_time_hour, s_time_minutes;
	s_time_hour = Utils::intToString(time.first);
	s_time_minutes = Utils::intToString(time.second);
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
