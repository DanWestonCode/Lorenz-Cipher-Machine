#ifndef _baudotEncoding_H_
#define _baudotEncoding_H_
#include "stdafx.h"
#include <string>
#include <map>
class baudotEncoding
{
public:
	
	baudotEncoding();
	~baudotEncoding();

	// convert ascii into 5bit baudot
	void encode(const std::string& in, std::vector<std::string>&);

	// convert 5bit baudot into ascii
	void decode(const std::vector<std::string>& in, std::string& out);
	
protected:
	std::map<char, std::string> encoding;	
	std::map<std::string, char> decoding;
};


#endif