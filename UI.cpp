/*
 * UI.cpp
 *
 *  Created on: 3 Dec 2013
 *      Author: tomto
 */

#include "UI.h"

namespace UI
{
	bool inputYesNo(string& question)
	{
		string answer;

		while((answer != "Y") && (answer != "N"))
		{
			cout << question << endl;
			cout << "Please enter Yes or No [Y/N]" << endl;
			cin >> answer;
			answer = Utils::toUppercase(answer);
			cout << "You entered " << answer << endl;
			cout << answer << " Y "<< endl;
			cout << endl;
		}
		if(answer == "Y")
			return true;
		else
			return false;
	}

	string inputName()
	{
		string name;
		cin >> name;
		cout << "entered: " << name;
		return name;
	}

	string inputFlightNumber()
	{
		string flightNumber;
		cin >> flightNumber;
		cout << "entered " << flightNumber;
		return flightNumber;
	}

	int inputMenuOption()
	{
		string answer;
		cin >> answer;
		int ianswer = atoi(answer.c_str());
		return ianswer;
	}

	void outputMainMenu()
	{
		cout << endl;
		cout << "\t***************************" << endl;
		cout << "\t******** MAIN MENU ********" << endl;
		cout << "\t***************************" << endl;
		cout << "\t* [1] Make Reservation    *" << endl;
		cout << "\t* [2] Make Cancellation   *" << endl;
		cout << "\t* [3] Flight Enquiry      *" << endl;
		cout << "\t* [4] Passenger Enquiry   *" << endl;
		cout << "\t* [5] Quit                *" << endl;
		cout << "\t***************************" << endl;
		cout << endl;
		cout << "Please enter your menu choice [1-5]:" << endl;
	}

	void outputAskPassengerName()
	{
		cout << endl;
		cout << "Please enter passenger name: [A-Z]" << endl;
	}

	void outputAskFlightNumber()
	{
		cout << endl;
		cout << "Please enter flight number:" << endl;
	}

}




