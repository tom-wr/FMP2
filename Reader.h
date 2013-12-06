/*

 * Reader.h
 *
 *  Created on: Nov 23, 2013
 *      Author: RAKEL


#ifndef READER_H_
#define READER_H_

#include "Flight.h"
#include "FlightList.h"
#include "Date.h"
#include <stdlib.h> // atoi();

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Reader
{
public:
	Reader(FlightList& flightList);
	void read(string fileName);
private:
	FlightList& flightList;
};
#endif  READER_H_
*/


/*
* Reader.h
*
* Created on: Nov 23, 2013
* Author: RAKEL
*/

#ifndef READER_H_
#define READER_H_



#include "Flight.h"
#include "FlightList.h"
#include "Date.h"
#include "Utils.h"
#include <time.h>

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
class Reader {
public:
        Reader(FlightList& fl);
        void read(string& filename);

private:
         FlightList& flightList;
         bool validateDateIsFuture(Date& date);
         bool validateDateFormat(Date& date);
         int getMaxDayForMonth(int month, bool leapYear);
};

#endif
