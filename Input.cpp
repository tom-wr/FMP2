#include "Input.h"

bool Input::checkStringLength(string& str, int& min, int& max) const
{
	int len = str.length();
	if( len < min || len > max )
	{
		cout << "Error: string length is out of bounds" << endl;
		return false;
	}
	return true;
}

bool Input::stringIsDigit(string& str) const
{
   for (int i=0; i<str.length(); i++)
   {
	   if(!isdigit(str[i]))
	   {
		   cout<<"Error:string is not digit"<<endl;
		   return false;
	   }
   }
   return true;
}

bool Input::stringIsAlpha(string& str) const
{
	for (int i = 0; i < str.length(); i++)
	{
		if(!isalpha(str[i]))
		{
			cout << "Error: string is not alpha" << endl;
			return false;
		}
	}
	return true;
}
