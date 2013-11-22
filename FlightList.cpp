//
//  FlightList.cpp
//  list
//
//  Created by wsr on 13-11-21.
//  Copyright (c) 2013年 wsr. All rights reserved.
//

#include "FlightList.h"

FlightList::FlightList(){}



void FlightList::addFlight(Flight& flight)  //add flight to flightlist
{
    //string code;
    //for(vector<Flight>::iterator it = list.begin(); it != list.end(); ++it)
    //{
      //  if(it->getFlightNumber() == code)
        //{
          //  cout<<"This flight has existed."<<endl;
        //}
        list.push_back(flight);
    //}
    
    
}

