#include "EnemySpawn.h"

void EnemySpawn(String RoomType)
{
	srand((unsigned)time(0));
	int rnd = rand() % 3 + 1;
	Enemy enemy;
	if (RoomType == "DemonNest")
	{
		if (rnd == 1)
		{
			Spawn spawn;
			enemy = spawn;
		}
		else if (rnd == 2)
		{
			BroodMother broodMother;
			enemy = broodMother;
		}
		else if (rnd == 3)
		{
			Incubus incubus;
			enemy = incubus;
		}
		else
		{
			Spawn spawn;
			enemy = spawn;
		}
	}
	else if (RoomType == "Forest")
	{
		if (rnd == 1)
		{
			Spawn spawn;
			enemy = spawn;
		}
		else if (rnd == 2)
		{
			BroodMother broodMother;
			enemy = broodMother;
		}
		else if (rnd == 3)
		{
			Incubus incubus;
			enemy = incubus;
		}
		else
		{
			Spawn spawn;
			enemy = spawn;
		}
	}
	else if (RoomType == "Ruins")
	{
		if (rnd == 1)
		{
			Spawn spawn;
			enemy = spawn;
		}
		else if (rnd == 2)
		{
			BroodMother broodMother;
			enemy = broodMother;
		}
		else if (rnd == 3)
		{
			Incubus incubus;
			enemy = incubus;
		}
		else
		{
			Spawn spawn;
			enemy = spawn;
		}
	}
	else if (RoomType == "Grotto")
	{
		if (rnd == 1)
		{
			Spawn spawn;
			enemy = spawn;
		}
		else if (rnd == 2)
		{
			BroodMother broodMother;
			enemy = broodMother;
		}
		else if (rnd == 3)
		{
			Incubus incubus;
			enemy = incubus;
		}
		else
		{
			Spawn spawn;
			enemy = spawn;
		}
	}
	else
	{
		if (rnd == 1)
		{
			Spawn spawn;
			enemy = spawn;
		}
		else if (rnd == 2)
		{
			BroodMother broodMother;
			enemy = broodMother;
		}
		else if (rnd == 3)
		{
			Incubus incubus;
			enemy = incubus;
		}
		else
		{
			Spawn spawn;
			enemy = spawn;
		}
	}
	enemy.PrintDescription();
}
