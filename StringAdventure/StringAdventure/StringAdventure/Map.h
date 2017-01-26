#ifndef _MAP_H_
#define _MAP_H_
#include "Room.h"

class Map
{
public:
	Map();
	Map(int Size);
	~Map();
	int ReturnMapSize();
	Room* ReturnRoom(int x, int y);
protected:
	int MapSize;
	Room** map;
};

#endif