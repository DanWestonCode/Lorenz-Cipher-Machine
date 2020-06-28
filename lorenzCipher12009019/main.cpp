#include "stdafx.h"
#include "input.h"
#include "baudotEncoding.h"
#include "lorenzMachine.h"

#include <iostream>
#include <vector>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	lorenzMachine machine;
	input keyin;

	char menuOption;

	do 
	{
		std::cout << "Lorenz Cipher Machine v1.1" << std::endl;
		std::cout <<"\t1. Encrypt/Decrypt message" <<std::endl;
		std::cout <<"\t2. Exit" <<std::endl;			

		std::string in = keyin.get();
		menuOption = in[0];

		switch (menuOption)
		{				
		case '1':
			std::cout << "Enter message for encyrption (\"a-z *,-!.\"): ";
			machine.process(keyin.get());
			break;
		case '2':
			std::cout << "Bye!" << std::endl;
			break;
		default:			
			std::cout << "\"" << in << "\" is not a valid option" << std::endl;
			break;
		}
	
	} while(menuOption != '2');

	return 0; 
}

