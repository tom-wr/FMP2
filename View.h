/*
 * View.h
 *
 *  Created on: Dec 3, 2013
 *      Author: RAKEL
 */

#ifndef VIEW_H_
#define VIEW_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;


namespace View {
    
	void printmenu();
	void question(string& str);
	void displayView(string& str);
    void help(void);

    void error(const string& errorMessage);
    const string invalidFlight = "Invalid flight number. Please re-enter flightNumber [5 characters EXACTLY]:";
    const string invalidName("Invalid name. Please re-enter name [A-Z] [30 characters MAX]:");
    const string invalidSeatType("Invalid seat class. Please re-enter [FIRST or ECONOMY]");
    const string invalidMenuChoice("Invalid menu choice. Please re-enter [1-6]:");

    void flightEnquiryHeader(string& flightNumber, string& date, string& time);
    void flightEnquirySubHeader(string& title);
    void flightEnquiryEntry(string& passengerName);

    void passengerEnquiryHeader(string& passengerName);
    void passengerEnquiryEntry(string& flightNumber, string& seat, string& status);
    
    void success(const string& successMessage);
    void successAddedToBookedList(const string& passengerName, const string& flightNumber, const string& seat);
    void successAddedToWaitingList(const string& passengerName, const string& flightNumber, const string& seat);
    void successCancelledPassenger(string& passengerName);
    void successTransferedPassenger(const string& passengerName, const string& seat);

    void FlightReserved(const string& str1, const string& str2);
    void ListFirstWaiting(const string& str1, const string& str2, const string& str3);
    void ListEconomyWaiting(const string& str1, const string& str2, const string& str3);
};
#endif
