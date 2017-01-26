#include "Creatures.h"


Creatures::Creatures()
{
}


Creatures::~Creatures()
{
}

void Creatures::PrintDescription()
{
	this->CreaturesDescription.WriteToConsole();
}

void Creatures::SetDescription(String &Description)
{

	this->CreaturesDescription = Description;
}

String Creatures::ReturnDescription()
{
	return this->CreaturesDescription;
}