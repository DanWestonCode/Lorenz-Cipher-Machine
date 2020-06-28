#ifndef _lorenzMachie_H_
#define _lorenzMachine_H_

#include "lorenzWheel.h"

class baudotEncoding;

class lorenzMachine {
public:
	lorenzMachine();
	~lorenzMachine();
	
	void process(const std::string&);

private:
	lorenzWheel psi[5];
	lorenzWheel mu[2];
	lorenzWheel chi[5];
	baudotEncoding* encoding;

	std::string pinSettings = "";
	int fileOffset = 0;

	void encrypt(const std::vector<std::string>&, std::vector<std::string>&);
	void configureWheel(lorenzWheel wheel[], int wheelSize[], int size);		
};

#endif