/*This class takes the ascii input and converts it into 5 bit baudot, as well as this, this class sets up the data structures for the qwerty and baudot.
	Another important function within this class is printing the encyrpted message*/
#include "stdafx.h"
#include "convertMessageBaudot.h"

/*the constructor function will create the baudot message */
convertMessageBaudot::convertMessageBaudot ()
{	
	
}
convertMessageBaudot::~convertMessageBaudot ()
{
}

/*set up baudot, sets up the data stuctures for the baudot and qwerty keyboard*/
void convertMessageBaudot:: setUpBaudot()
{
	

	/*SET UP QWERTY KEYBOARD*/
	qwerty.push_back('*');
	qwerty.push_back(' ');
	qwerty.push_back('Q');
	qwerty.push_back('W');
	qwerty.push_back('E');
	qwerty.push_back('R');
	qwerty.push_back('T');
	qwerty.push_back('Y');
	qwerty.push_back('U');
	qwerty.push_back('I');
	qwerty.push_back('O');
	qwerty.push_back('P');
	qwerty.push_back('A');
	qwerty.push_back('S');
	qwerty.push_back('D');
	qwerty.push_back('F');
	qwerty.push_back('G');
	qwerty.push_back('H');
	qwerty.push_back('J');
	qwerty.push_back('K');
	qwerty.push_back('L');
	qwerty.push_back('Z');
	qwerty.push_back('X');
	qwerty.push_back('C');
	qwerty.push_back('V');
	qwerty.push_back('B');
	qwerty.push_back('N');
	qwerty.push_back('M');
	qwerty.push_back(',');
	qwerty.push_back('-');
	qwerty.push_back('!');
	qwerty.push_back('.');

	/*qwertyBaudot['*']="00000";
	qwertyBaudot[' ']="00000";
	qwertyBaudot['Q']="10111";
	qwertyBaudot['W']="10011";
	qwertyBaudot['E']="00001";
	qwertyBaudot['R']="01010";
	qwertyBaudot['T']="10000";
	qwertyBaudot['Y']="10101";
	qwertyBaudot['U']="00111";
	qwertyBaudot['I']="00110";
	qwertyBaudot['O']="11000";
	qwertyBaudot['P']="10110";
	qwertyBaudot['A']="00011";
	qwertyBaudot['S']="00101";
	qwertyBaudot['D']="01001";
	qwertyBaudot['F']="01101";
	qwertyBaudot['G']="11010";
	qwertyBaudot['H']="10100";
	qwertyBaudot['J']="01011";
	qwertyBaudot['K']="01111";
	qwertyBaudot['L']="10010";
	qwertyBaudot['Z']="10001";
	qwertyBaudot['X']="11101";
	qwertyBaudot['C']="01110";
	qwertyBaudot['V']="11110";
	qwertyBaudot['B']="11001";
	qwertyBaudot['N']="01100";
	qwertyBaudot['M']="11100";
	qwertyBaudot[',']="01000";
	qwertyBaudot['-']="00010";
	qwertyBaudot['!']="11011";
	qwertyBaudot['.']="11111";*/


	/*SET UP BAUDOT CODE*/
	baudot.push_back("00000");//null
	baudot.push_back("00100");//space
	baudot.push_back("10111");//q
	baudot.push_back("10011");//w
	baudot.push_back("00001");//e
	baudot.push_back("01010");//r
	baudot.push_back("10000");//t
	baudot.push_back("10101");//y
	baudot.push_back("00111");//u
	baudot.push_back("00110");//i
	baudot.push_back("11000");//o
	baudot.push_back("10110");//p
	baudot.push_back("00011");//a
	baudot.push_back("00101");//s
	baudot.push_back("01001");//d
	baudot.push_back("01101");//f
	baudot.push_back("11010");//g
	baudot.push_back("10100");//h
	baudot.push_back("01011");//j
	baudot.push_back("01111");//k
	baudot.push_back("10010");//l
	baudot.push_back("10001");//z
	baudot.push_back("11101");//x
	baudot.push_back("01110");//c
	baudot.push_back("11110");//v
	baudot.push_back("11001");//b
	baudot.push_back("01100");//n
	baudot.push_back("11100");//m
	baudot.push_back("01000");//carriage return
	baudot.push_back("00010");//line feed
	baudot.push_back("11011");//shift to fig
	baudot.push_back("11111");//shift to letters


}

/*This function takes the input ascii string and converts each letter of that string to its baudot equivilant*/
vector<string> convertMessageBaudot:: createBaudot(vector<string> & baudotString)
{ 
	/*get the length of the users message*/
	int messageLength = message.length();

	/*loop for length of message*/
	for (int i = 0; i <= messageLength; i++)
	{
		/*loop through qwerty alphabet*/
		for (int x = 0; x < 32; x ++)
		{
			/*if the current qwerty pos == the current message pos*/
			if (qwerty[x] == message[i])
			{
				baudotString.push_back(baudot[x]);					
			}		
		}
	}

	/*return the now converted message*/
	return baudotString; 
}

/*This function takes the encyrted baudot message and prints out the encryption*/
void convertMessageBaudot :: printEncryption(vector<string> baudotToEncryption)
{

	int size =  baudotToEncryption.size();
	int baudoSize = baudot.size();

	string test;
	/*loop through message*/
	for (int i = 0; i < size; i++)
	{
		/*loop through baudot alphabet*/
		for (int x = 0; x < baudoSize; x++)
		{
			if (baudot[x] == baudotToEncryption[i])
			{
				cout << qwerty[x];
				test += qwerty[x];
			}
		}
	}
	
	/*clear line*/
	cout << endl;	
}
