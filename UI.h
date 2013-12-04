
#ifndef UI_H_
#define UI_H_

#include <string>
#include <iostream>

#include "Utils.h"

using namespace std;
using namespace Utils;

namespace UI
{
	string inputName();
	string inputFlightNumber();
	int inputMenuOption();
	bool inputYesNo(string& question);
	
	void outputMainMenu();
	void outputAskPassengerName();
	void outputAskFlightNumber();
}

#endif
