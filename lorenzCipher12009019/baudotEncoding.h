#ifndef _baudotEncoding_H_
#define _baudotEncoding_H_

#include <string>
#include <map>

using namespace std;
class baudotEncoding
{
public:
	
	baudotEncoding();
	~baudotEncoding();

	// convert ascii into 5bit baudot
	string* encode(string);

	// convert 5bit baudot into ascii
	string decode(string*, int size);
	
protected:
	map<char, string> encoding;	
	map<string, char> decoding;
};


#endif