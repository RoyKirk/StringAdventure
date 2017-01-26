#include "Ruins.h"

Ruins::Ruins()
{
	this->RoomType = "Ruins";
}

Ruins::Ruins(int Seed)
{
	this->RoomType = "Ruins";
	if (Seed == 1)
	{
		this->RoomDescription = "The echoes of a long dead civilisation still ring out through the piles of rubble and precarious stone walls.";
	}
	else if (Seed == 2)
	{
		this->RoomDescription = "Vines grow thick out of the rubble and stretch up what is left of long abandoned buildings.";
	}
	else if (Seed == 3)
	{
		this->RoomDescription = "The thick creepers prying apart the stones of the stone buildings is paradoxically the only thing holding them up.";
	}
	else
	{
		this->RoomDescription = "The echoes of a long dead civilisation still ring out through the piles of rubble and precarious stone walls.";
	}
}


Ruins::~Ruins()
{
}
