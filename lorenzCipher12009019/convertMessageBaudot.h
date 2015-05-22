/*This class takes the ascii input and converts it into 5 bit baudot, as well as this, this class sets up the data structures for the qwerty and baudot.
	Another important function within this class is printing the encyrpted message*/
#ifndef _convertMessageBaudot_H_
#define _convertMessageBaudot_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;
class convertMessageBaudot
{
public:
	/*constructor and deconstructor*/
	convertMessageBaudot();
	~convertMessageBaudot();

	/*setters*/
	void setMessage(string input)
	{
		message = input;
	}

	/*public functions*/
	void setUpBaudot();
	vector<string> createBaudot(vector<string> & baudotString);
	void printEncryption(vector<string> baudotToEncryption);

	/*Public variables*/
	vector<string> baudotMessage;
	
protected:
	string message;
	vector<char> qwerty; 
	vector<string> baudot;
};


#endif