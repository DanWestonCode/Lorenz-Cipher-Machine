#ifndef _lorenzMachie_H_
#define _lorenzMachine_H_

#include "lorenzWheel.h"

class baudotEncoding;

class lorenzMachine {
public:
	lorenzMachine();
	~lorenzMachine();
	
	void process(std::string);

private:
	lorenzWheel psi[5];
	lorenzWheel mu[2];
	lorenzWheel chi[5];
	baudotEncoding* encoding;

	std::string pinSettings = "";
	int fileOffset = 0;

	std::string* encrypt(std::string*, int);
	void configureWheel(lorenzWheel wheel[], int wheelSize[], int size);		
};

#endif