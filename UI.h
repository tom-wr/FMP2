/**
 * UI class handles user input and output.
 * It controls how information is displayed and performs validation checks on input.
 */

#ifndef UI_H_
#define UI_H_

#include <string>
#include <iostream>

#include "Utils.h"
#include "View.h"
#include "Seat.h"


using namespace std;

namespace UI
{
	/**
	 * gets input string from the user and returns as a string.
	 * the string is always converted to uppercase letters.
	 * @return string - input string from the user.
	 */
	string in(void);

	/*
	 * gets user input for a name and validates it.
	 * @return string - name from user input.
	 */
	string inputName(void);

	/**
	 * gets user input for a flight number and validates it.
	 * @return string - flight number from user input.
	 */
	string inputFlightNumber(void);

	/**
	 * gets user input for a menu choice and validates it.
	 * @return string - menu choice from user input.
	 */
	int inputMenuOption(void);

	/**
	 * get user input for a yes or no question.
	 * The user can reply either 'y' or 'n'.
	 * @return string true for yes / false for no.
	 */
	bool inputYesNo(void);

	/**
	 * get user input for a seat type.
	 * @return Seat::Type - seat type specified by user input.
	 */
	Seat::Type inputSeatType(void);

	/**
	* asks user to press enter to continue.
	*/
	void enterToContinue(void);
	
	/**
	 * formats a string as an output message
	 * @param errorMessage const string& - string to be output.
	 */
	void outputError(const string& errorMessage);

	/**
	 * displays the main menu.
	 */
	void outputMainMenu(void);

	/**
	 * displays question for passenger name.
	 */
	void outputAskPassengerName(void);

	/**
	 * displays question for flight number.
	 */
	void outputAskFlightNumber(void);

	/**
	 * displays question for seat type.
	 */
	void outputAskSeatType(void);

	/**
	 * formats a string as an output message
	 * @param message string& - string to be output.
	 */
	void outputs(string& message);

}

#endif
