#ifndef _CREATURES_H_
#define _CREATURES_H_
#include <iostream>
#include "String.h"
class Creatures
{
public:
	Creatures();
	~Creatures();
	void PrintDescription();
	void SetDescription(String &Description);
	String ReturnDescription();
protected:
	String CreaturesDescription;
};

#endif