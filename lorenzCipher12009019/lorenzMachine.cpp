#include "stdafx.h"
#include "lorenzMachine.h"
#include "baudotEncoding.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

lorenzMachine::lorenzMachine() 
{
	// read pinsettings file
	std::ifstream infile;
	infile.open("pinsettings.dat");
	getline(infile, pinSettings);	
	infile.close();

	// setup the machine wheels 
	int psiPins[5]{ 43,47,51,53,59 };
	int muPins[2]{ 37, 61 };
	int chiPins[5]{ 41,31,29,26,23 };

	configureWheel(psi, psiPins, 5);
	configureWheel(mu, muPins, 2);
	configureWheel(chi, chiPins, 5);

	encoding = new baudotEncoding();
}

lorenzMachine::~lorenzMachine()
{
	delete encoding;
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
		std::string pins = pinSettings.substr(fileOffset, wheelSize[i]);
		fileOffset += wheelSize[i];
		wheel[i] = *new lorenzWheel(pins);
	}
}

/**
 * Encyrpts passed in message using the Lorenz machine algiorithm
 */
void lorenzMachine::encrypt(const std::vector<std::string>& in, std::vector<std::string>& out)
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
	std::string tempLetter, push;
	
	for (int i = 0, counti = in.size(); i < counti; ++i) 
	{
		out.push_back("");
		// XOR the current psi and chi wheels for 5 bit key
		for (int y = 0, county = 5; y < county; y++)
		{
			fiveBitKey[y] = psi[y].current() ^ chi[y].current();
		}

		// XOR the generated 5 bit key with the current encoded character 
		for (int y = 0, county = 5; y < county; ++y)
		{
			char c = in[i][y] ^ fiveBitKey[y];
			// avoid null
			if (c != 0)
			{
				out[i] += c;
			}
		}

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
}

/**
 * Process and output the input message through the lorenz machine
 */
void lorenzMachine::process(const std::string& in)
{
	std::vector<std::string> encoded;
	std::vector<std::string> encrypted;
	std::string decoded = "";

	encoding->encode(in, encoded);
	encrypt(encoded, encrypted);
	encoding->decode(encrypted, decoded);

	std::cout << "Output: \"" << decoded << "\"" << std::endl;
}
