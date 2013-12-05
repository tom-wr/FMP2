/*
 * View.cpp
 *
 *  Created on: Dec 3, 2013
 *      Author: RAKEL
 */

#include "View.h"


View::View() {
	// TODO Auto-generated constructor stub

}

void View :: printmenu(){

    std::cout<< "************************************************************"<< endl;
    std::cout<< "******************************************************** "<< endl;
    std::cout<< "***************** THIS IS YOUR MENU*********"<< endl;
    std::cout<< "*************************************"<< endl;
    
    std::cout<<" Main MENU" << endl;
    std::cout << "1. Reservation             ----- *********************" << endl;
    std::cout << "2. Cancellation            ----- *********************" << endl;
    std::cout << "3. Print Flight List       ----- *********************"<< endl;
    std::cout << "4. Print Passenger List    ----- *********************" << endl;
    std::cout << "5. Help                    ----- ********************* " << endl;
    std::cout << "6. Quit                    ----- *********************" <<endl;
    
    cout<< "***********************************************"<< endl;
    cout<< "*************************************************************** "<< endl;
    cout<< "*********************************************************************"<< endl;
    cout<< "****************************************************************************"<<endl;

}
void View ::displayError(string& str){
	cout << str  +" is not valid  Please REnter:"+ str << endl;
}




void View ::displayView(string& str){
	cout <<"Please Enter :"+ str << endl;
}

void View ::displayIntructions(char& str){
	if(str == "R"){
        // display reservation instructions
		cout <<"[1] -- Enter : <Passengername>"<< endl;
		cout <<"[2] -- Enter : <Passenger Lastname>"<< endl;
		cout <<"[3] -- Enter : <Seat>"<< endl;
	}
    if(str =="C"){
		cout <<"[1] --- Enter : <Passengername>" << endl;
		cout <<"[2] --- Enter : <Flight Number>" << endl;
	}
    
	if(str =="P"){
		cout <<"[1] --- Enter : <Flight Number>" <<endl;
        
	}
    
    
}
void View ::displayHeads(char& str){
    if (str == "H"){
        cout << "-----Displaying Help----"<<endl;
        cout << "---------"<<endl;
    }
    if(str == "F"){
        cout << "-----Displaying the List of Flights----"<<endl;
        cout << "---------"<<endl;
    }
    if (str=="Q"){
        cout <<"---------------- GOODBYE---------- :" << endl;
    }
}

