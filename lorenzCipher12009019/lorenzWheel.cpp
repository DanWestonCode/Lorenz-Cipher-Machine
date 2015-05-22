#include "stdafx.h"
#include "lorenzWheel.h"

lorenzWheel::lorenzWheel()
{
	/*set file counter to begining of string*/
	fileCounter = 0;
}
lorenzWheel::~lorenzWheel()
{
}

/*this function reads in the pin data stored in the pinsettings.dat file*/
void lorenzWheel::loadPins()
{
	/*create file object*/
	ifstream infile;
	/*open text file*/
	infile.open("pinsettings.dat");
	/*read file, store contense to pinSettings string*/
	getline(infile,pinSettings);
	/*close file*/
	infile.close();

	/*test if pins load*/
	//cout << pinSettings << endl;
}

/*This function sets up the pin values for the psi, chi and mu wheels*/
void lorenzWheel::setWheels(int pins[], int size)
{
	
	/*loop around wheel size*/
	for (int i = 0; i < size; i++)
	{
		/*loop around each wheel length*/
		for (int y = 0; y < pins[i]; y ++)
		{
			/*push current string pos onto temp vect*/
			tempVect.push_back(pinSettings[fileCounter]);
			/*increment up the string*/
			fileCounter++;
		}
		/*push tempVect onto the lorenz wheel structure*/
		lorenzWheels.push_back(tempVect);
		/*clear temp vect for next wheel*/
		tempVect.clear();
	}

}

/*This function performs the encryption operations on the message and creates an encrypted version of the message */
vector<string> lorenzWheel::encyrptMessage(string input, vector <string> baudotMessage, int psiPins[], int chiPins[], int muPins[])
{
	/*variables*/
	int fiveBitKey[5];
	int length = baudotMessage.size();

	
	/*arrays hold current pin pos during encyrption for all wheels*/
	int psiCounter[] = {0,0,0,0,0};
	int chiCounter[] = {0,0,0,0,0};
	int muCounter[] = {0,0};

	char encryption[5];
	string tempLetter, push;

	/*reset values*/
	encryptionMessage.clear();
	tempLetter.clear();
	push.clear();

	/*Message encryption*/
	for (int counter = 0; counter < length; counter++)//keep going for input ASCII message length
	{	
		/*generate 5 bit key*/
		/*get current pin setting for chi and psi*/
		for (int i = 0; i < 5; i++)
		{
			/*XOR the current psi and chi wheels for 5 bit key*/
			fiveBitKey[i] = lorenzWheels[i][psiCounter[i]] ^ lorenzWheels[i+7][chiCounter[i]]; //i+7 to reach chi pos in vector

		}

		/*store current position in baudot code to tempLetter for XOR operation*/
		tempLetter = baudotMessage[counter];

		/*empty string*/
		push.clear();

		/*XOR 5 bit key with baudot*/
		for(int i = 0; i <= 4; i++)
		{
			/*stores the current letter of the input message in temp char array*/
			encryption[i] = tempLetter[i] ^ fiveBitKey[i]; 

			/*copy the encryption array into string(avoid null character)*/
			if (encryption[i] != 0)
			{
				push+=encryption[i];
			}

		}
		encryptionMessage.push_back(push);
		
		/*Wheel rotations*/
		/*chi rotates everytime*/
		for (int i = 0; i < 5; i++)
		{
			/*call rotate wheel function*/
			chiCounter[i] = rotateWheel(chiCounter[i], chiPins[i]-1, i);	
		}
		/*psi rotates if m37 = 1*/
		if(lorenzWheels[5][muCounter[0]] == '1')
		{
			for (int i = 0; i < 5; i++)
			{
				psiCounter[i] = rotateWheel(psiCounter[i], psiPins[i]-1, i);	
			}		
		}
		/*if current m61 == 1 rotate m37*/
		if(lorenzWheels[6][muCounter[1]] == '1')
		{
			muCounter[0] = rotateWheel(muCounter[0], 36, 1);	
		}
		/*m61 is always rotated*/
		muCounter[1] = rotateWheel(muCounter[1], 60, 1);	
	}
	return encryptionMessage;	
}

/*This function rotates a given lorenz wheel. As well as rotating the wheel this function ensures that a wheel does not step over its data structure bounds*/
int lorenzWheel:: rotateWheel(int wheel, int pinMax, int pos)
{
	/*is current wheel pos greater than or equal to max pins*/
	if (wheel >= pinMax)
	{
			/*set wheel pos back to one*/
			wheel = 0;
	}
	else
	{
			/*move wheel pos up one*/
			wheel++;
	}

	return wheel;

}