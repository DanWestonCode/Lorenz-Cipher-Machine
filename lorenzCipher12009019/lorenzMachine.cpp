#include "stdafx.h"
#include "lorenzMachine.h"
#include "baudotEncoding.h"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

lorenzMachine::lorenzMachine() 
{
	// read pinsettings file
	ifstream infile;
	infile.open("pinsettings.dat");
	getline(infile, pinSettings);	
	infile.close();

	// setup the machine wheels 
	configureWheel(psi, new int[5]{43,47,51,53,59}, 5);
	configureWheel(mu, new int[2]{37, 61}, 2);
	configureWheel(chi, new int[5]{ 41,31,29,26,23}, 5);

	encoding = new baudotEncoding();
}

lorenzMachine::~lorenzMachine()
{
}

/**
 * Sets up the passed wheel using pinsettings from parsed pinsettings.dat file
 */
void lorenzMachine::configureWheel(lorenzWheel wheel[], int wheelSize[], int size)
{
	// iterate over each wheel in this section
	for (int i = 0, counti = size; i < counti; i++)
	{
		// setup 
		string pins = pinSettings.substr(fileOffset, wheelSize[i]);
		fileOffset += wheelSize[i];
		wheel[i] = *new lorenzWheel(pins);
	}
}

/**
 * Encyrpts passed in message using the Lorenz machine algiorithm
 */
string* lorenzMachine::encrypt(string* input, int length)
{
	// reset all the wheels
	for (int i = 0, counti = 5; i < counti; i++)
	{
		psi[i].reset();
		chi[i].reset();
	}
	mu[0].reset();
	mu[1].reset();

	int fiveBitKey[5];	
	string tempLetter, push;

	string* encryptedMessage;
	encryptedMessage = new string[length];
	
	for (int i = 0, counti = length; i < counti; i++) 
	{

		// XOR the current psi and chi wheels for 5 bit key
		for (int y = 0, county = 5; y < county; y++)
		{
			fiveBitKey[y] = psi[y].current() ^ chi[y].current();
		}

		string encryted = "";

		// XOR the generated 5 bit key with the current encoded character 
		for (int y = 0, county = 5; y < county; y++)
		{
			char c = input[i][y] ^ fiveBitKey[y];
			// avoid null
			if (c != 0)
			{
				encryted += c;
			}
		}

		encryptedMessage[i] = encryted;

		// Wheel rotations
		for (int y = 0, county = 5; y < county; y++)
		{
			// always rotate chi 
			chi[y].rotate();

			// psi rotates if m37 == 1
			if (mu[0].current() == '1')
			{
				psi[y].rotate();
			}
		}

		// if current m61 == 1 rotate m37
		if (mu[1].current() == '1')
		{
			mu[1].rotate();
		}

		// m61 is always rotated
		mu[0].rotate();
	}

	return encryptedMessage;
}

/**
 * Process and output the input message through the lorenz machine
 */
void lorenzMachine::process(string in)
{
	cout << "Output: \"" << encoding->decode(encrypt(encoding->encode(in), in.length()), in.length()) << "\"" << endl;
}
