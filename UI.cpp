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
	bool inputYesNo(string& question)
	{
		string answer;
        
		while((answer != "Y") && (answer != "N"))
		{
			cout << question << endl;
			cout << "Please enter Yes or No [Y/N]" << endl;
			cin >> answer;
			answer = Utils::toUppercase(answer);
            //	cout << "You entered " << answer << endl;
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
		string firstname,lastname;
		cin >> firstname >>lastname;
        //	cout << "entered: " << firstname <<" " <<lastname <<endl;
		return firstname+ ""+lastname;
	}
    
	string inputFlightNumber()
	{
		string flightNumber;
		cin >> flightNumber;
        //	cout << "entered " << flightNumber;
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
        View::printmenu();
	}
    Seat::Type inputseatType()
	{
		string seatType;
		cin >> seatType;
		if(seatType =="FIRST"){
			return Seat ::FIRST;
		}else{
			return Seat ::ECONOMY;
		}
	}
	void outputAskPassengerName()
	{
		string name = "Firstname and Lastname";
		View::displayQuestion(name);
	}
	void outputAskSeatType()
    {
        string seat = "Seat Type";
        View::displayQuestion(seat);
    }
    
	void outputAskFlightNumber()
	{
		string fn ="Flight Number";
		View::displayQuestion(fn);
	}
    void outputInvalid(string& s){
        View::displayError(s);
    }
    void outputFlightNotification(string& c, const string& s1, const string& s2 , const string& s3){
        
        if(c == "1") {
            View:: FlightReserved(s1,s2);
        }else if (c == "2"){
            View::ListFirstWaiting(s1,s2,s3);
        }
        else
            View::ListEconomyWaiting(s1,s2,s3);
    }
    
    
}



