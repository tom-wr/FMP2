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
	void displayError(string& str);
	void displayQuestion(string& str);
	void displayView(string& str);
    void displayIntructions(char& str);
    void displayHeads(char& str);
    
    void FlightReserved(const string& str1, const string& str2);
    void ListFirstWaiting(const string& str1, const string& str2, const string& str3);
    void ListEconomyWaiting(const string& str1, const string& str2, const string& str3);
};
