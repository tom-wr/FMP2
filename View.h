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


class View {
public:
	View();
	void printmenu();
	void displayError(string& str);
	void displayView(string& str);
  void displayIntructions(char& str);
};

#endif /* VIEW_H_ */
