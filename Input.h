/*
 * Input.h
 *
 *  Created on: 20 Nov 2013
 *      Author: tomto
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Input
{
public:
	bool checkStringLength(string& date1, int& min, int& max) const;
	bool stringIsDigit(string& str) const;
	bool stringIsAlpha(string& str) const;
};


#endif /* INPUT_H_ */
