/*
 * Reader.h
 *
 *  Created on: Nov 23, 2013
 *      Author: RAKEL
 */

#ifndef READER_H_
#define READER_H_



#include "Flight.h"
#include "FlightList.h"
#include "Date.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
class Reader {
public:
	Reader();
            ifstream file ;
			string line;
			//vector <FlightList> fl;
			Flight flight;
            Date _date;
	        string flightNumber;
            string capacity;
            int theCapacity;
	        string times;
            int theTimes;
	        string date;
            int theDate;
	        FlightList fl;
	        void readInFile();
            int atoi(string varName);
    
private:
};
#endif /* READER_H_ */
