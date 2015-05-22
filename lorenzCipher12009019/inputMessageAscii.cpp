/*This class gets the input string from the user which will be encrypted*/
#include "stdafx.h"
#include "inputMessageAscii.h"

/*define the lenght of the input ascii */
#define strLength 600

inputMessageAscii::inputMessageAscii ()
{
	
}

inputMessageAscii::~inputMessageAscii ()
{

}

/*This function takes in the user input and assigns it to a string, as well as this it converts all input to uppercase characters*/
void inputMessageAscii::inputMessage ()
{
	char tempInput[strLength];	

	/*Reset values*/
	input.clear();
	/*end reset values*/

	/*ignore menu press*/
	cin.ignore(1);
	/*get message for encryption*/
	cout << "Enter message for encryption: " << endl;
	cin.getline(tempInput,strLength);

	/*Copy character array into string*/
	for(int i = 0;i < strLength;i++)
	{
		if (tempInput[i] != 0)
		{
			input += tempInput[i];
		}
		else if (tempInput[i] == 0)
		{
			break;
		}
		
	}

	/*convert user input to uppercase characters*/
	int tempLength = input.size();
	for (int i = 0; i < tempLength; i++)
	{
		input[i] = toupper(input[i]);
	}

	/*set the string*/
	setMessage(input);
}

