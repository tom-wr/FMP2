/*
 * UI.cpp
 *
 *  Created on: 3 Dec 2013
 *      Author: tomto
 */

#include "UI.h"
#define stringify( name ) # name
namespace UI
{

	string in()
	{
		string input;
		getline(cin, input);
		input = Utils::toUppercase(input);
		return input;
	}

	bool inputYesNo(string& question)
	{
		string answer;
        
		while((answer != "Y") && (answer != "N"))
		{
			cout << question << endl;
			cout << "Please enter Yes or No [Y/N]" << endl;
			answer = in();
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
				else
					View::error(View::invalidMenuChoice);
			}
		}
		return ianswer;
	}

    Seat::Type inputSeatType()
	{
		string seat;
		bool passed = false;
		Seat::Type seatType;
		while(!passed)
		{
			seat = in();
			if(seat == "FIRST")
			{
				seatType = Seat::FIRST;
				passed = true;
			}
			else if(seat == "ECONOMY")
			{
				seatType = Seat::ECONOMY;
				passed = true;
			}
			else
				View::error(View::invalidSeatType);
		}
		return seatType;
	}

    void outputMainMenu()
	{
		View::printmenu();
	}

	void outputAskPassengerName()
	{
		string name = "Please enter full name of the passenger:";
		View::question(name);
	}

	void outputAskSeatType()
    {
        string seat = "Please enter the seat class [First or Economy]:";
        View::question(seat);
    }
    
	void outputAskFlightNumber()
	{
		string flightNumber = "Please enter the flight number:";
		View::question(flightNumber);
	}

    void outputError(string& errorMessage)
    {
        View::error(errorMessage);
    }

    void outputSuccess(string& successMessage)
    {
    	View::success(successMessage);
    }

   /* void outputFlightNotification(string& c, string& s1, string& s2 , string& s3){
        
        if(c == "1") {
            View:: FlightReserved(s1,s2);
        }else if (c == "2"){
            View::ListFirstWaiting(s1,s2,s3);
        }
        else
            View::ListEconomyWaiting(s1,s2,s3);
    }*/

    void successAddedToBookedList(const string& passengerName, const string& flightNumber, const string& seat)
	{
		cout << "\t+ Passenger " << passengerName
				<< " has booked a " << seat
				<< " class seat for flight " << flightNumber << endl;
	}

	void successAddedToWaitingList(const string& passengerName, const string& flightNumber, const string& seat)
	{
		cout << "\t+ Passenger " << passengerName
				<< " has been added to the " << seat
				<< " class waiting list for flight " << flightNumber << endl;
	}

	void successCancelledPassenger(string& passengerName)
	{
		cout<<"\t+ Passenger " << passengerName << " has been removed from flight" << endl;
	}

	void successTransferedPassenger(string& passengerName, string& seat)
	{
		cout<<"\t+ Passenger " << passengerName << " has been transfered from the " << seat << " waiting list to the booked list" << endl;
	}
}



