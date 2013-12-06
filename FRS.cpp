//============================================================================
// Name        : FMP2_GO.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "ReservationSystem.h"
#include "CancellationSystem.h"
#include "EnquirySystem.h"
#include "FlightList.h"
#include "PassengerList.h"
#include "Reader.h"
#include "UI.h"

using namespace std;

void systemsGo()
{
	FlightList fl;
	PassengerList pl;

	Reader reader(fl);
	string filename("FCGDATA.txt");
	reader.read(filename);
	ReservationSystem rsv(fl, pl);
	CancellationSystem cnl(fl, pl);
	EnquirySystem enq(fl, pl);

	int choice = 0;
	while(choice != 5)
	{
		UI::outputMainMenu();
		choice = UI::inputMenuOption();
		switch(choice)
		{
		case 1:
			rsv.makeReservation();
			break;
		case 2:
			cnl.makeCancellation();
			break;
		case 3:
			enq.enquireFlightInformation();
			break;
		case 4:
			enq.enquirePassengerInformation();
			break;
		default:
			break;
		}
	}
}

int main() {

	systemsGo();
	return 0;
}
