// lorenzCipher12009019.cpp : Defines the entry point for the console application.
#include "stdafx.h"

#include "inputMessageAscii.h"
#include "convertMessageBaudot.h"
#include "lorenzWheel.h"
#include <iostream>
#include <vector>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{

	/*local variables*/
	string message;
	bool programLoop = true;
	int menuOption;
	int psiPins[] = {43,47,51,53,59};
	int chiPins [] = {41,31,29,26,23};
	int mu[] = {37,61};
	vector<string> asciiToBaudot;
	vector<string> baudotToEncyrption;

	/*set up objects*/
	convertMessageBaudot * baudotConversion = new convertMessageBaudot;
	lorenzWheel * wheel = new lorenzWheel;
	inputMessageAscii * asciiInput = new inputMessageAscii;	
	
	
	/*set up baudot table*/
	baudotConversion->setUpBaudot();
	/*load pin settings*/
	wheel->loadPins();
	/*set up wheels with pin settings*/
	wheel->setWheels(psiPins, 5); // set up psi wheels
	wheel->setWheels(mu, 2); // set up mu wheels
	wheel->setWheels(chiPins, 5); // set up chi wheels

	/*program loop*/
	do 
	{
		/*user menu*/
		cout << "Lorenz Cipher Machine v1.1" << endl;
		cout <<"\t1. Encrypt/Decrypt message" <<endl;
		cout <<"\t2. Exit" <<endl;

		/*menu choice*/
		cin >> menuOption;
		
		/*switch case from menu options*/
		switch (menuOption)
		{
			/*encryption*/
			case 1:
				/*Reset values to default*/
				asciiToBaudot.clear();
				baudotToEncyrption.clear();
				message.clear();
				/*end reset values to default*/

				/*ASCII INPUT*/
				asciiInput->inputMessage();
				message = asciiInput->getMessage();

				/*BAUDOT CONVERSION*/					
				/*send input message to baudot class*/
				baudotConversion->setMessage(message);
				/*create baudot version of message*/
				baudotConversion->createBaudot(asciiToBaudot);/*asciiToBaudot will hold baudot rep of message*/

				/*ENCRYPTION*/
				/*start encryption*/
				baudotToEncyrption = wheel->encyrptMessage(message, asciiToBaudot, psiPins, chiPins, mu);/*baudotToEncyrption will hold encyrpted rep of message*/

				/*PRINT ENCRYPTION*/
				baudotConversion->printEncryption(baudotToEncyrption);
				break;
				/*exit*/
				case 2:
					programLoop = false;
				break;
				/*wrong input*/
				default:
						cout << "Error!" << endl; 
				break;
			}
	
	}while(programLoop);

	return 0; 
}

