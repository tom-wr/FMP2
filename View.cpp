/*
 * View.cpp
 *
 *  Created on: Dec 3, 2013
 *      Author: RAKEL
 */

#include "View.h"

namespace veiw {
    
	void printmenu(){
        
        cout<< "*****************************************************"<< endl<< endl;
        cout<< "**********************MAIN MENU *********************" << endl;
        cout << "\t* 1. Reservation             *********************" << endl;
        cout << "\t* 2. Cancellation            *********************" << endl;
        cout << "\t* 3. Flight Inquiry          *********************"<< endl;
        cout << "\t* 4. Passenger Inquiry       *********************" << endl;
        cout << "\t* 5. Help                    ********************* " << endl;
        cout << "\t* 6. Quit                    *********************" <<endl;
        cout << "Please enter your menu choice [1-6]:" << endl;
        cout<< "*****************************************************"<< endl;
        
        
	}
	void displayError(string& str){
        cout << str  +" is not valid  Please REnter:"+ str << endl;
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
	void FlightReserved(string& str){
        
		cout << "Passenger Has Been Reserved on the Flight"<< endl;
	}
	void FLightNotReserved(string& str){
        
        cout<<"Flight with seat preference"+str+" Full"<<endl;
        cout<<"FLight Not Reserved Add to waitingList? "<<endl;
    }
	void WaitingList(){
        cout<<"Passenger Has Been Added to waiting List"<< endl;
	}
	void CancelPassenger(string str){
        cout<<"Passenger"+str+" Has Been removed from flight"<< endl;
        cout<<" Waiting List has been updated "<<endl;
    }
}



