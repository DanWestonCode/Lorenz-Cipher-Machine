#include "stdafx.h"
#include "input.h"
#include "baudotEncoding.h"
#include "lorenzMachine.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	lorenzMachine* machine = new lorenzMachine();	
	input* keyin = new input();

	char menuOption;

	do 
	{
		cout << "Lorenz Cipher Machine v1.1" << endl;
		cout <<"\t1. Encrypt/Decrypt message" <<endl;
		cout <<"\t2. Exit" <<endl;			

		string in = keyin->get();
		menuOption = in[0];

		switch (menuOption)
		{				
		case '1':
			cout << "Enter message for encyrption (\"a-z *,-!.\"): ";
			machine->process(keyin->get());
			break;
		case '2':
			cout << "Bye!" << endl;
			break;
		default:			
			cout << "\"" << in << "\" is not a valid option" << endl;
			break;
		}
	
	}while(menuOption != '2');

	return 0; 
}

