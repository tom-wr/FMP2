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
							flight.setFlightCapacity(capacity);
							flight.setFlightTime(times);
							flight.setFlightDate(date);
							fl.addFlight(flight);
						}
					}
				}




				file.close();
			}
