#include "stdafx.h"
#include "baudotEncoding.h"
#include <iostream>

baudotEncoding::baudotEncoding ()
{	
	// TODO: think of a better solution for this...
	encoding['*'] = "00000";
	encoding[' '] = "00100";
	encoding['Q'] = "10111";
	encoding['W'] = "10011";
	encoding['E'] = "00001";
	encoding['R'] = "01010";
	encoding['T'] = "10000";
	encoding['Y'] = "10101";
	encoding['U'] = "00111";
	encoding['I'] = "00110";
	encoding['O'] = "11000";
	encoding['P'] = "10110";
	encoding['A'] = "00011";
	encoding['S'] = "00101";
	encoding['D'] = "01001";
	encoding['F'] = "01101";
	encoding['G'] = "11010";
	encoding['H'] = "10100";
	encoding['J'] = "01011";
	encoding['K'] = "01111";
	encoding['L'] = "10010";
	encoding['Z'] = "10001";
	encoding['X'] = "11101";
	encoding['C'] = "01110";
	encoding['V'] = "11110";
	encoding['B'] = "11001";
	encoding['N'] = "01100";
	encoding['M'] = "11100";
	encoding[','] = "01000";
	encoding['-'] = "00010";
	encoding['!'] = "11011";
	encoding['.'] = "11111";	
	
	decoding["00000"] = '*';
	decoding["00100"] = ' ';
	decoding["10111"] = 'Q';
	decoding["10011"] = 'W';
	decoding["00001"] = 'E';
	decoding["01010"] = 'R';
	decoding["10000"] = 'T';
	decoding["10101"] = 'Y';
	decoding["00111"] = 'U';
	decoding["00110"] = 'I';
	decoding["11000"] = 'O';
	decoding["10110"] = 'P';
	decoding["00011"] = 'A';
	decoding["00101"] = 'S';
	decoding["01001"] = 'D';
	decoding["01101"] = 'F';
	decoding["11010"] = 'G';
	decoding["10100"] = 'H';
	decoding["01011"] = 'J';
	decoding["01111"] = 'K';
	decoding["10010"] = 'L';
	decoding["10001"] = 'Z';
	decoding["11101"] = 'X';
	decoding["01110"] = 'C';
	decoding["11110"] = 'V';
	decoding["11001"] = 'B';
	decoding["01100"] = 'N';
	decoding["11100"] = 'M';
	decoding["01000"] = ',';
	decoding["00010"] = '-';
	decoding["11011"] = '!';
	decoding["11111"] = '.';
}

baudotEncoding::~baudotEncoding ()
{
}

/**
 * Take input and convert each character into 5 bit baudot code
 */
void baudotEncoding::encode(const std::string& in, std::vector<std::string>& out)
{	
	for (int i = 0, counti = in.length(); i < counti; ++i)
	{
		if (encoding.count(in[i]))
		{
			out.push_back(encoding[in[i]]);
		}
		else
		{
			std::cout << in[i] << " is an invalid key" << std::endl;
			out.push_back(encoding['*']);
		}
	}
}

/**
 * Take input and convert each character 
  (5 bit baudot code) back into alphabetical representation 
 */
void baudotEncoding::decode(const std::vector<std::string>& input, std::string& const out)
{
	for (int i = 0, counti = input.size(); i < counti; ++i)
	{		
		out += decoding[input[i]];
	}
}