#ifndef _ROOM_H_
#define _ROOM_H_
#include "String.h"
class Room
{
public:
	Room();
	~Room();
	void PrintDescription();
	String* ReturnRoomType();
//	void SetPos(int x, int y);
//	int* ReturnPos();
protected:
//	int PosX;
//	int PosY;
	String RoomDescription;
	String RoomType;
};

#endif