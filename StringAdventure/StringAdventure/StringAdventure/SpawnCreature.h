#ifndef _SPAWNCREATURE_H_
#define _SPAWNCREATURE_H_
#include <ctime> 
#include <iostream>
#include "Player.h"
#include "Creatures.h"
#include "Enemy.h"
#include "Friendly.h"
#include "Spawn.h"
#include "BroodMother.h"
#include "Incubus.h"
#include "Goblin.h";
#include "Centaur.h";
#include "Troll.h";
#include "Imp.h";
#include "WaterSerpent.h";
#include "ClayGolem.h";
#include "StoneGargoyle.h"
#include "Skeleton.h";
#include "Drake.h";
#include "Cat.h"
#include "Deer.h"
#include "GiantGrub.h"
#include "Nymph.h"
#include "String.h"

void SpawnCreature(String &RoomType, Player &player);
void EnemySpawn(String &RoomType, Enemy &enemy);
void FriendlySpawn(String &RoomType);
void Approach(Player &player);
void Leave();
void Fight(Player &player, Enemy &enemy);
void Run(Player &player);

#endif