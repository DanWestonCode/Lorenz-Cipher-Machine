/*This class sets up the wheels for the lorenz cipher. As well as this the program sets up the pins on the wheels and carrys out the encyrption process*/
#ifndef _lorenzWheel_H_
#define _lorenzWheel_H_
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class lorenzWheel
{
public:
	/*constructor and deconstructor*/
	lorenzWheel();
	~lorenzWheel();

	/*public functions*/
	void loadPins(); 
	void setWheels(int pins[], int size);
	int rotateWheel(int, int, int);
	vector<string> encyrptMessage(string input, vector<string>baudotMessage, int psiPins[], int chiPins[], int muPins[]);
	
private:
	/*private variables*/
	string pinSettings;
	/*multidimensional vectors for psi, chi wheels*/
	vector< vector<char> > lorenzWheels;
	/*store current position in string*/
	int fileCounter;
	vector<char> tempVect;	
	vector <string> encryptionMessage;
};

#endif