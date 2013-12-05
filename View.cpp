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

		std::cout<< "************************************************************"<< std::endl<< std::endl;
	    std::cout<< "******************************************************** "<< std::endl<< std::endl;
	    std::cout<< "***************** THIS IS YOUR MENU*********"<< std::endl<< std::endl;
	    std::cout<< "*************************************"<< std::endl<< std::endl;

	    std::cout<<" Main MENU"<<std::endl<<std::endl;
	    std::cout << "1. Reservation             ----- Reserve <name> <status> <flightNO>" << std::endl<< std::endl;
	    std::cout << "2. Cancellation            ----- Cancel <Passengername>" << std::endl<< std::endl;
	    std::cout << "3. Print Flight List       ----- Display F"<< std::endl<< std::endl;
	    std::cout << "4. Print Passenger List    ----- Display P <flight Number>" << std::endl<< std::endl;
	    std::cout << "5. Help                    ----- Help " << std::endl<< std::endl;
	    std::cout << "6. Quit                    ----- Quit" << std::endl<< std::endl;

	    std::cout<< "***********************************************"<< std::endl<< std::endl;
	    std::cout<< "*************************************************************** "<< std::endl<< std::endl;
	    std::cout<< "*********************************************************************"<< std::endl<< std::endl;
	    std::cout<< "****************************************************************************"<< std::endl<< std::endl;


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
	}
    if(str =="C"){
		cout <<"Please Enter :"+ str << endl;
	}
    if (str == "D"){
        
	}
    if(str == "F"){
        
	}if(str =="P"){
        
	}if (str=="Q"){
		cout <<"---------------- GOODBYE---------- :" << endl;
	}
}
