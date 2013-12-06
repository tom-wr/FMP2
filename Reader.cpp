/*

 * Reader.cpp
 *
 *  Created on: Nov 23, 2013
 *  Author: RAKEL
 *  */

#include "Reader.h"

Reader::Reader(FlightList& _flightList)
: flightList(_flightList)
{
}

void Reader::read(string& fileName)
{
	ifstream file(fileName.c_str());
	cout << "reading file!" << endl;
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
				string s_flightNumber, s_capacity, s_time, s_date;
				int i_Capacity;
				//getline(file, line);
				file >> s_flightNumber >> s_capacity >> s_time >> s_date;
				// print out to test
				cout << s_flightNumber << " " << s_capacity << " " << s_time << " " << s_date << endl;
				//cout << line << endl;

				//input.splitline(line)
				//input.validateLine(s_flightNumber, s_capacity, s_timeString, s_dateString);
				//input.separateDate(dateString);
				cout << "string capacity: " << s_capacity << endl;
				i_Capacity = atoi(s_capacity.c_str()); // temp convert to integer
				cout << "icapacity: " << i_Capacity << endl;
				pair<int, int> timep = Utils::splitTimeString(s_time);
				vector<int> splitDate = Utils::splitDateString(s_date);
				Date date(timep, splitDate[0], splitDate[1], splitDate[2]);

				Flight flight(s_flightNumber, i_Capacity, date);
				flightList.addFlight(flight);
			}
		}
		file.close();
	}
}
