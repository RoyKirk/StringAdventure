#include "Player.h"


Player::Player()
{
	this->PosX = 0;
	this->PosY = 0;
	this->Health = 10;
	this->Speed = 10;
	this->Strength = 10;
}

Player::Player(int x, int y)
{
	this->PosX = x;
	this->PosY = y;
	this->Health = 10;
	this->Speed = 10;
	this->Strength = 10;
}


Player::~Player()
{
}

void Player::SetPos(int X, int Y)
{
	this->PosX = X;
	this->PosY = Y;
}

int* Player::ReturnPos()
{
	int Pos[2] = { this->PosX, this->PosY };
	return Pos;
}

void Player::SetHealth(int health)
{
	this->Health = health;
}
void Player::SetSpeed(int speed)
{
	this->Speed = speed;
}
void Player::SetStrength(int strength)
{
	this->Strength = strength;
}
void Player::SetStats(String &stat, int pos)
{
	if (pos <= 2 && pos >= 0)
	{
		this->StatChoices[pos] = stat;
	}
}

int Player::ReturnHealth()
{
	return this->Health;
}
int Player::ReturnSpeed()
{
	return this->Speed;
}
int Player::ReturnStrength()
{
	return this->Strength;
}
String Player::ReturnStats(int index)
{
	return this->StatChoices[index];
}