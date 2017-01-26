#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "String.h"

class Player
{
public:
	Player();
	Player(int x,int y);
	~Player();
	void SetPos(int x, int y);
	void SetHealth(int health);
	void SetSpeed(int speed);
	void SetStrength(int strength);
	void SetStats(String &stat, int pos);

	int* ReturnPos();
	int ReturnHealth();
	int ReturnSpeed();
	int ReturnStrength();
	String ReturnStats(int index);
protected:
	int PosX;
	int PosY;
	int Health;
	int Speed;
	int Strength;
	String StatChoices[3];
};

#endif