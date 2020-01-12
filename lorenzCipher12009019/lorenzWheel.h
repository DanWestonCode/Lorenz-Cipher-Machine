#ifndef _lorenzWheel_H_
#define _lorenzWheel_H_

#include <string>
class lorenzWheel
{
public:
	lorenzWheel();
	lorenzWheel(std::string pins);
	~lorenzWheel();
	
	void rotate();
	void reset();	
	char current();
private:	
	int m_pos;
	std::string m_pins;
};

#endif