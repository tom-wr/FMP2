/**
 * UI class handles user input and output.
 * It controls how information is displayed and performs validation checks on input.
 */

#include "UI.h"

namespace UI
{

	/**
	 * gets input string from the user and returns as a string.
	 * the string is always converted to uppercase letters.
	 * @return string - input string from the user.
	 */
	string in()
	{
		string input;
		getline(cin, input);
		input = Utils::toUppercase(input);
		return input;
	}

	/**
	 * get user input for a yes or no question.
	 * The user can reply either 'y' or 'n'.
	 * @return string true for yes / false for no.
	 */
	bool inputYesNo()
	{
		string answer;
		while((answer != "Y") && (answer != "N"))
		{
			View::question(View::q_yesOrNo);
			answer = in();
			cout << endl;
		}
		if(answer == "Y")
			return true;
		else
			return false;
	}
    
	/**
	 * gets user input for a name and validates it.
	 * @return string - name from user input.
	 */
	string inputName()
	{
		string name;
		bool passed = false;
		while(!passed)
		{
			name = in();
			passed = Utils::validateName(name);
			if(!passed)
				View::error(View::invalidName);
		}
		return name;
	}
    
	/**
	 * gets user input for a flight number and validates it.
	 * @return string - flight number from user input.
	 */
	string inputFlightNumber()
	{
		string flightNumber;
		bool passed = false;
		while(!passed)
		{
			flightNumber = in();
			passed = Utils::validateFlightNumber(flightNumber);
			if(!passed)
				View::error(View::invalidFlight);
		}
		return flightNumber;
	}
    
	/**
	 * gets user input for a menu choice and validates it.
	 * @return string - menu choice from user input.
	 */
	int inputMenuOption()
	{
		string answer;
		int ianswer;
		bool passed = false;
		while(!passed)
		{
			answer = in();
			if(Utils::stringIsDigit(answer))
			{
				ianswer = atoi(answer.c_str());
				if(ianswer > 0 && ianswer <= 6)
					passed = true;
			}
			if(!passed)
				View::error(View::invalidMenuChoice);
		}
		return ianswer;
	}

	/**
	 * get user input for a seat type.
	 * @return Seat::Type - seat type specified by user input.
	 */
    Seat::Type inputSeatType()
	{
		string seat;
		bool passed = false;
		Seat::Type seatType;
		while(!passed)
		{
			seat = in();
			if(seat == "FIRST" || seat == "F")
			{
				seatType = Seat::FIRST;
				passed = true;
			}
			else if(seat == "ECONOMY" || seat == "E")
			{
				seatType = Seat::ECONOMY;
				passed = true;
			}
			else
				View::error(View::invalidSeatType);
		}
		return seatType;
	}

	void enterToContinue()
	{
		cout << endl;
		View::question(View::q_pressEnter);
		in();
	}

    /**
	 * displays the main menu.
	 */
    void outputMainMenu()
	{
		View::printmenu();
	}

    /**
	 * displays question for passenger name.
	 */
	void outputAskPassengerName()
	{
		View::question(View::q_passengerName);
	}

	/**
	 * displays question for seat type.
	 */
	void outputAskSeatType()
    {
        View::question(View::q_seatType);
    }
    
	/**
	 * displays question for flight number.
	 */
	void outputAskFlightNumber()
	{
		View::question(View::q_flightNumber);
	}

	/**
	 * formats a string as an error output message
	 * @param errorMessage const string& - string to be output.
	 */
    void outputError(const string& errorMessage)
    {
        View::error(errorMessage);
    }

	/**
	 * formats a string as an output message
	 * @param message string& - string to be output.
	 */
	void outputs(string& message)
	{
		cout << "\t " << message << endl;
	}

}



