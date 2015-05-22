/*This class gets the input string from the user which will be encrypted*/
#ifndef _inputMessageAscii_H_
#define _inputMessageAscii_H_
#include <string>
#include <iostream>

using namespace std;
class inputMessageAscii  
{
public:	
	/*constructor and deconstructor*/
	inputMessageAscii ();
	~inputMessageAscii ();

	/*public functions*/
	void inputMessage();

	/*Getters/Setters*/
	string getMessage()	{
		return encryptionString;
	}
	void setMessage(string input)
	{
		encryptionString = input;
	}

protected:
	/*protected variables*/
	string encryptionString;
	string input;
		
};
#endif