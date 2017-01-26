#include "CurrentRoom.h"
#include <iostream>
#include <time.h>
#include "Map.h"
#include "Grotto.h"
#include "DemonNest.h"
#include "Forest.h"
#include "Ruins.h"

CurrentRoom::CurrentRoom()
{
	srand(time(0));
	int rnd = rand() % 4 + 1;

	Room temp;
	if (rnd == 1)
	{
		Grotto Gr;
		temp = Gr;
	}
	else if (rnd == 2)
	{
		Forest Fr;
		temp = Fr;
	}
	else if (rnd == 3)
	{
		DemonNest Dem;
		temp = Dem;
	}
	else if (rnd == 4)
	{
		Ruins Rui;
		temp = Rui;
	}
	else
	{
		Forest Fr;
		temp = Fr;
	}
}


CurrentRoom::~CurrentRoom()
{
}
