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

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Reader {
public:
	Reader();
            ifstream file ;
			string line;
			//vector <FlightList> fl;
			Flight flight;
	        string flightNumber;
	        int capacity;
	        string times;
	        string date;
	        FlightList fl;
	void readInFile();
private:
};
#endif /* READER_H_ */
