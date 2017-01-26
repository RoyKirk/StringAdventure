#include "Forest.h"

Forest::Forest()
{
	this->RoomType = "Forest";
}

Forest::Forest(int Seed)
{
	this->RoomType = "Forest";
	if (Seed == 1)
	{
		this->RoomDescription = "Massive trees tangled and twisted by darkness stretch up to the sky. Creatures jump and glide from the branches screeching and squawking at your presence.";
	}
	else if (Seed == 2)
	{
		this->RoomDescription = "Trees have grown thick and tight against each other, you can barely squeeze between them. However, You can feel hungry eyes on your back and rush in to the maze of trunks.";
	}
	else if (Seed == 3)
	{
		this->RoomDescription = "Verdant foliage covers the bushes along the path you are following. Wildlife graze around you only giving a curious glance or two before going back to masticating.";
	}
	else
	{
		this->RoomDescription = "Verdant foliage covers the bushes along the path you are following. Wildlife graze around you only giving a curious glance or two before going back to masticating.";
	}
}


Forest::~Forest()
{
}
