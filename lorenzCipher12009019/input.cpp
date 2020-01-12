#include "stdafx.h"
#include "input.h"

#include <algorithm>
#include <iostream>

/**
 * input string length used for cin.getLine
 */
#define strLength 600

using namespace std;
input::input ()
{
	
}

input::~input ()
{

}

/**
 * Parses keyboard input and returns back as capatalised string
 */
string input::get (){
	char charIn [strLength];	
	cin.getline(charIn,strLength);

	string strIn = charIn;
	transform(strIn.begin(), strIn.end(), strIn.begin(), ::toupper);

	return strIn;
}

