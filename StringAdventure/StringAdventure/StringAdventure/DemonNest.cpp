#include "DemonNest.h"


DemonNest::DemonNest()
{
	this->RoomType = "DemonNest";
}

DemonNest::DemonNest(int Seed)
{
	this->RoomType = "DemonNest";
	if (Seed == 1)
	{
		this->RoomDescription = "The smell of rotting flesh and the sound of it tearing pervades the air.";
	}
	else if (Seed == 2)
	{
		this->RoomDescription = "Tall jagged rocks jut out in all directions. The cackles of demons and the screams of their victims enmesh into a frightening cacophany that shakes the ground.";
	}
	else if (Seed == 3)
	{
		this->RoomDescription = "A schorched and tortured land stretches ahead of you. Shadows move across the ground, scurrying out from under your steps.";
	}
	else
	{
		this->RoomDescription = "The smell of rotting flesh and sound of flesh tearing pervades the air.";
	}
}


DemonNest::~DemonNest()
{
}

