#ifndef _DEMONNEST_H_
#define _DEMONNEST_H_
#include "Room.h"

class DemonNest :
	public Room
{
public:
	DemonNest();
	DemonNest(int Seed);
	~DemonNest();
};

#endif