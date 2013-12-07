
#ifndef UI_H_
#define UI_H_

#include <string>
#include <iostream>

#include "Utils.h"
#include "View.h"
#include "Seat.h"


using namespace std;
using namespace Utils;
using namespace View;

namespace UI
{
	string inputName();
	string inputFlightNumber();
	int inputMenuOption();
	bool inputYesNo(string& question);
	
	void outputMainMenu();
	void outputAskPassengerName();
	void outputAskFlightNumber();
	void seatType();
	void outputFlightNotification(string& s, const string& s1, const string& s2, const string& str3);
	void ListFirstWaiting(const string& s1, const string& s2, const string& str3);
	void ListEconomyWaiting(const string& s1, const string& s2, const string& str3);
}

#endif