#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include "Map.h"
#include "Grotto.h"
#include "DemonNest.h"
#include "Forest.h"
#include "Ruins.h"


Map::Map()
{
}

Map::Map(int Size)
{
	srand((unsigned)time(0));
	this->MapSize = Size;
	this->map = new Room*[this->MapSize];
	for (int i = 0; i < this->MapSize; i++)
		map[i] = new Room[this->MapSize];
	for (int i = 0; i < this->MapSize; i++)
	{
		for (int j = 0; j < this->MapSize; j++)
		{
			int room = rand() % 4 + 1;
			int roomSeed = rand() % 3 + 1;

			Room temp;

			if (room == 1)
			{
				Grotto Gr(roomSeed);
				temp = Gr;
			}
			else if (room == 2)
			{
				Forest Fr(roomSeed);
				temp = Fr;
			}
			else if (room == 3)
			{
				DemonNest Dem(roomSeed);
				temp = Dem;
			}
			else if (room == 4)
			{
				Ruins Rui(roomSeed);
				temp = Rui;
			}
			else
			{
				Forest Fr(roomSeed);
				temp = Fr;
			}

			this->map[i][j] = temp;
		}
	}
}


Map::~Map()
{
	for (int i = 0; i < this->MapSize; ++i)
	{
		delete[] map[i];
	}
	delete[] map;
}

int Map::ReturnMapSize()
{
	return this->MapSize;
}

Room* Map::ReturnRoom(int x, int y)
{
	Room* CurrentRoom = &this->map[x][y];
	return CurrentRoom;
}
