/*

 * Reader.cpp
 *
 *  Created on: Nov 23, 2013
 *  Author: RAKEL
 *  */


#include "Reader.h"

Reader::Reader(FlightList& _fl)
:fl(_fl)
{

}


void Reader::readInFile(){

		ifstream file ;

		file.open ("FCGDATA.txt");

				if (file.is_open()){
						if (file.eof()){
								cout << "Error: the file is empty" << endl;
						}
						else{
								string flightNumber, capacity, times, sdate, line;
								while (!file.eof()){
										file >> flightNumber >> capacity >>times >> sdate;

										// bool Utils::validateLine(flightNumber, capacity, times)
										// vector<int> splitDate = Utils::splitDate(sdate)
										// bool Utils::validateDate(splitDate);
										//getline(file, line);
										cout << flightNumber << " " << capacity << " " << times << " " << sdate << endl;
										//cout << line << endl;

										Date date(1,1,1,1);
										int icapacity = atoi(capacity.c_str());
										Flight flight(flightNumber, icapacity, date);

										fl.addFlight(flight);
								}
						}
				}

				file.close();
		}
/*

#include "Reader.h"

Reader::Reader(FlightList& _flightList)
: flightList(_flightList)
{
}

void Reader::read(string fileName)
{
	ifstream file(fileName.c_str());

	if (file.is_open())
	{
		cout<<"file is open" << endl;
		if (file.eof())
		{
			cout << "Error: the file is empty" << endl;
		}
		else
		{
			string line;
			while (!file.eof())
			{
				string s_flightNumber, s_capacity, s_time, s_date, buff;
				//getline(file, line);
				file >> s_flightNumber >> s_capacity >> s_time >> s_date;
				// print out to test
				cout << s_flightNumber << " " << s_capacity << " " << s_time << " " << s_date << endl;
				//cout << line << endl;

				//input.splitline(line)
				//input.validateLine(s_flightNumber, s_capacity, s_timeString, s_dateString);
				//input.separateDate(dateString);
				int i_Capacity = atoi(s_capacity.c_str()); // temp convert to integer
				Date date(1000, 1, 1, 2014);

				Flight flight(s_flightNumber, i_Capacity, date);
				flightList.addFlight(flight);
			}
		}
		file.close();
	}
}
*/
