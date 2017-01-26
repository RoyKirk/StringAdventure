#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "Creatures.h"
#include <iostream>
#include "String.h"

class Enemy:
	public Creatures
{
public:
	Enemy();
	~Enemy();
	int ReturnSpeed();
	int ReturnStrength();
protected:
	int Strength;
	int Speed;
};

#endif