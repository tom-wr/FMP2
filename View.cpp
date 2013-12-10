/*
 * View.cpp
 *
 *  Created on: Dec 3, 2013
 *      Author: RAKEL
 */

#include "View.h"


namespace View {
    
	void printmenu()
	{
		cout << endl;
        cout << "\t**************************************" << endl;
        cout << "\t******************* MAIN MENU ********" << endl;
        cout << "\t* 1. Reservation              ********" << endl;
        cout << "\t* 2. Cancellation             ********" << endl;
        cout << "\t* 3. Flight Inquiry           ********" << endl;
        cout << "\t* 4. Passenger Inquiry        ********" << endl;
        cout << "\t* 5. Help                     ********" << endl;
        cout << "\t* 6. Quit                     ********" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t*Please enter your menu choice [1-6]:*" << endl;
        cout << endl;
	}
	void error(const string& errorMessage)
	{
        cout << "\t!!!\tERROR: " << errorMessage << endl;
	}

	void success(const string& successMessage)
	{
		cout <<"\t+ " << successMessage << endl;
	}
    
	void question(string& question)
	{
        cout <<"Please Enter :"+ question << endl;
	}
    
	void help()
	{
	    cout <<" RESERVATION "<<endl;
		cout <<"[1] -- Enter : <Passengername>"<< endl;
		cout <<"[2] -- Enter : <Passenger Lastname>"<< endl;
		cout <<"[3] -- Enter : <Seat>"<< endl;
        
		cout <<"Cancellation"<<endl;
		cout <<"[1] --- Enter : <Passengername>" << endl;
		cout <<"[2] --- Enter : <Flight Number>" << endl;
        
        
		cout <<"PASSENGER ENQUIRY"<<endl;
		cout <<"[1] --- Enter : <Flight Number>" <<endl;
	}
    
	void flightEnquiryHeader(string& flightNumber, string& date, string& time)
	{
		cout << endl;
        cout << "\t----------------------------------" << endl;
        cout << "\t| FLIGHT ENQUIRY FOR " << flightNumber << " Date: " << date << " Time: " << time << endl;
        cout << "\t----------------------------------" << endl;
        cout << endl;
    }
	
	void flightEnquirySubHeader(string& listTitle)
	{
		cout << endl;
		cout << "\t| " << listTitle << endl;
		cout << "\t----------------------------------" << endl;
	}

	void flightEnquiryEntry(string& passengerName)
	{
		cout << "\t  " << passengerName << endl;
	}

	void passengerEnquiryHeader(string& passengerName)
	{
		cout << endl;
		cout << "\t-------------------------------------------------" << endl;
		cout << "\t| PASSENGER ENQUIRY FOR " << passengerName <<  "\t\t|" << endl;
		cout << "\t-------------------------------------------------" << endl;
		cout << "\t| FLIGHT\t| STATUS\t| SEAT CLASS\t|" << endl;
		cout << "\t-------------------------------------------------" << endl;
		cout << endl;
    }
	
	void passengerEnquiryEntry(string& flightNumber, string& seat, string& status)
	{
		cout << "\t|  " << flightNumber << "\t  " << status << "\t  " << seat << endl;
	}

	void goodbyeMessage()
	{
        cout <<""<< endl;
        cout <<"\t***********************************"<< endl;
        cout <<"\t************** GOODBYE************* " << endl;
        cout <<"\t***********************************"<< endl;
    }

	void FlightReserved(const string& str1,const  string& str2)
	{
		cout <<str1+ " has Been Reserved on the Flight "+str2<< endl;
	}

	void FlightNotReserved(string& str)
	{
        cout<<"Flight with seat preference"+str+" is not available"<<endl;
        cout<<"Change seat Preference  "<<endl;
    }

	void ADDToWaitingList()
	{
		cout<<"Do You want to change seat Preference ?"<< endl;
        cout<<"OR Do you want to add passenger to passenger list"<< endl;
    }

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

	void successTransferedPassenger(const string& passengerName, const string& seat)
	{
		cout<<"\t+ Passenger " << passengerName << " has been transfered from the " << seat << " waiting list to the booked list" << endl;
	}
    
}
//cout << "!!!\tPassenger already booked on flight. Double booking not allowed.

//"!!!\tDate is cannot be on same day as another booked flight.

//cout << "date same" << endl;

//cout << "Flight does not exist!" << endl;


