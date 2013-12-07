/*
 * View.cpp
 *
 *  Created on: Dec 3, 2013
 *      Author: RAKEL
 */

#include "View.h"


namespace View {
    
	void printmenu(){
        
        cout<< "*****************************************************"<< endl<< endl;
        cout<< "**********************MAIN MENU *********************" << endl;
        cout << "\t* 1. Reservation             ****************" << endl;
        cout << "\t* 2. Cancellation            ****************" << endl;
        cout << "\t* 3. Flight Inquiry          ****************"<< endl;
        cout << "\t* 4. Passenger Inquiry       ****************" << endl;
        cout << "\t* 5. Help                    ****************" << endl;
        cout << "\t* 6. Quit                    ****************" <<endl;
        cout << "\t*Please enter your menu choice [1-6]:********" << endl;
        cout<< "*****************************************************"<< endl;
        
        
	}
	void displayError(string& str){
        cout << "  Invalid  "+ str << endl;
	}
    
    
	void displayQuestion(string& str){
        cout <<"Please Enter :"+ str << endl;
	}
    
	void displayHeLPIntructions(){
        
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
    
    
    
	void displayFlightHeads(){
        
        cout << "\t*********Displaying the List of Flights*****"<<endl;
        cout << "\t Flight Number \t Capacity \t Time  \t Date-"<<endl;
    }
	
	void displayPassengerHeads(string& str){
        
        cout << "\t*********List of Passengers on Flight"+ str +" ****"<< endl;
        cout << "\tFirstName \t LastName"<<endl;
    }
	
	void displayByeMessage(){
        
        cout <<""<< endl;
        cout <<"\t***********************************"<< endl;
        cout <<"\t************** GOODBYE************* " << endl;
        cout <<"\t***********************************"<< endl;
    }
	void FlightReserved(const string& str1,const  string& str2){
        
		cout <<str1+ " has Been Reserved on the Flight "+str2<< endl;
	}
	void FLightNotReserved(string& str){
        
        cout<<"Flight with seat preference"+str+" is not available"<<endl;
        cout<<"Change seat Preference  "<<endl;
    }
	void ADDToWaitingList(){
        cout<<"Do You want to change seat Preference ?"<< endl;
        cout<<"OR Do you want to add passenger to passenger list"<< endl;
    }
	void ListFirstWaiting(const string& str1, const string& str2, const string& str3){
        cout<<str1 + " Passenger Has Been Added to First waiting List of flight " +str2 << endl;
	}
	void ListEconomyWaiting(const string& str1, const string& str2, const string& str3){
        cout<<str1 + " Passenger Has Been Added to Economy waiting List of flight " +str2 << endl;
    }
	void CancelPassenger(string str){
        cout<<"Passenger"+str+" Has Been removed from flight"<< endl;
        cout<<" Waiting List has been updated "<<endl;
    }
    
}
//cout << "!!!\tPassenger already booked on flight. Double booking not allowed.

//"!!!\tDate is cannot be on same day as another booked flight.

//cout << "date same" << endl;

//cout << "Flight does not exist!" << endl;


