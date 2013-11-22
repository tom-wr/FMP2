//
//  FlightList.h
//  list
//
//  Created by wsr on 13-11-21.
//  Copyright (c) 2013年 wsr. All rights reserved.
//

#ifndef list_flighlist_h
#define list_flighlist_h


#include <string>
#include <vector>
#include <iostream>

#include "Flight.h"
using namespace std;

class FlightList
{
  public:
	FlightList();
    void addFlight(Flight& flight);
    vector<Flight> list;

};


#endif
