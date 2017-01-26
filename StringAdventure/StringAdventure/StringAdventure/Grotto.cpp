#include "Grotto.h"


Grotto::Grotto()
{
	this->RoomType = "Grotto";
}

Grotto::Grotto(int Seed)
{
	this->RoomType = "Grotto";
	if (Seed == 1)
	{
		this->RoomDescription = "You step carefully between the big jagged rocks and see Nymphs frolicking in the hotspring. They notice you watching and quickly fade into the haze rising off the water.";
	}
	else if (Seed == 2)
	{
		this->RoomDescription = "You come across a large pool of crytal clear water. You decide to have a rest and fill your canteen.";
	}
	else if (Seed == 3)
	{
		this->RoomDescription = "You step through the water-worn entrance in the rock face. The rock pool inside is cool and inviting. You take off your shoes and soak your feet.";
	}
	else
	{
		this->RoomDescription = "You step carefully between the big jagged rocks and see Nymphs frolicking in the hotspring. They notice you watching and quickly fade into the haze rising off the water.";
	}
}


Grotto::~Grotto()
{
}
