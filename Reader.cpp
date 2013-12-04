/*
 * Reader.cpp
 *
 *  Created on: Nov 23, 2013
 *      Author: RAKEL
 */

#include "Reader.h"


		void Reader::readInFile(){


			file.open ("FCGDATA.txt");

				if (file.is_open()){
					if (file.eof()){
						cout << "Error: the file is empty" << endl;
					}
					else{
						while (getline (file,line)){
							file >> flightNumber >> capacity >>times >> date;

							flight.setFlightNumber(flightNumber);
                            theCapacity = atoi(capacity);
                            flight.setFlightCapacity(theCapacity);
                            theTimes = atoi(times);
							_date.setTime(theTimes);
							flight.setFlightDate(_date);
							fl.addFlight(flight);
						}
					}
				}




				file.close();
			}
