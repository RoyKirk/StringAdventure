#include "Room.h"

Room::Room()
{
	//this->RoomDescription = "";
	//this->PosX = 0;
	//this->PosY = 0;
}


Room::~Room()
{
}

void Room::PrintDescription()
{
	this->RoomDescription.WriteToConsole();
}

String* Room::ReturnRoomType()
{
	return &this->RoomType;
}
//void Room::SetPos(int X, int Y)
//{
//	this->PosX = X;
//	this->PosY = Y;
//}
//
//int* Room::ReturnPos()
//{
//	int Pos[2] = { this->PosX, this->PosY };
//	return Pos;
//}
