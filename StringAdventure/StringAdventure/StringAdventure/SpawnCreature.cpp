#include "SpawnCreature.h"


void SpawnCreature(String &RoomType, Player &player)
{
	Enemy enemy;
	srand((unsigned)time(0));
	int rnd = rand() % 2 + 1;
	if (rnd == 1)
	{

		EnemySpawn(RoomType, enemy);
		for (int i = 0; i < 1; i++)
		{
			std::cout << "Do you want to stay and FIGHT or RUN.\n";
			String Move = "temp";
			Move.ReadFromConsole();
			Move.ToLower();
			if (Move == "fight")
			{
				Fight(player, enemy);
			}
			else if (Move == "run")
			{
				Run(player);
			}
			else
			{
				std::cout << "Invalid move.\n";
				i--;
			}
		}
	}
	else if (rnd == 2)
	{
		FriendlySpawn(RoomType);
		for (int i = 0; i < 1; i++)
		{
			std::cout << "Do you want APPROACH it or LEAVE it alone.\n";
			String Move = "temp";
			Move.ReadFromConsole();
			Move.ToLower();
			if (Move == "approach")
			{
				Approach(player);
			}
			else if (Move == "leave")
			{
				Leave();
			}
			else
			{
				std::cout << "Invalid move.\n";
				i--;
			}
		}
	}
	else
	{

	}
}
void FriendlySpawn(String &RoomType)
{
	Cat cat;
	Deer deer;
	Nymph nymph;
	GiantGrub giantGrub;
	if (RoomType == "DemonNest")
	{
		giantGrub.PrintDescription();
	}
	else if (RoomType == "Forest")
	{
		deer.PrintDescription();
	}
	else if (RoomType == "Ruins")
	{
		cat.PrintDescription();
	}
	else if (RoomType == "Grotto")
	{
		nymph.PrintDescription();
	}
	else
	{
		cat.PrintDescription();
	}

}
void EnemySpawn(String &RoomType, Enemy &enemy)
{
	int rnd = rand() % 3 + 1;
	Spawn spawn;
	BroodMother broodMother;
	Incubus incubus;
	Goblin goblin;
	Centaur centaur;
	Troll troll;
	Imp imp;
	WaterSerpent waterSerpent;
	ClayGolem clayGolem;
	StoneGargoyle stoneGargoyle;
	Skeleton skeleton;
	Drake drake;
	if (RoomType == "DemonNest")
	{
		if (rnd == 1)
		{
			enemy = spawn;
			spawn.PrintDescription();
		}
		else if (rnd == 2)
		{
			enemy = broodMother;
			broodMother.PrintDescription();
		}
		else if (rnd == 3)
		{
			enemy = incubus;
			incubus.PrintDescription();
		}
		else
		{
			enemy = spawn;
			spawn.PrintDescription();
		}
	}
	else if (RoomType == "Forest")
	{
		if (rnd == 1)
		{
			enemy = goblin;
			goblin.PrintDescription();
		}
		else if (rnd == 2)
		{
			enemy = centaur;
			centaur.PrintDescription();
		}
		else if (rnd == 3)
		{
			enemy = troll;
			troll.PrintDescription();
		}
		else
		{
			enemy = goblin;
			goblin.PrintDescription();
		}
	}
	else if (RoomType == "Ruins")
	{
		if (rnd == 1)
		{
			enemy = stoneGargoyle;
			stoneGargoyle.PrintDescription();
		}
		else if (rnd == 2)
		{
			enemy = skeleton;
			skeleton.PrintDescription();
		}
		else if (rnd == 3)
		{
			enemy = drake;
			drake.PrintDescription();
		}
		else
		{
			enemy = stoneGargoyle;
			stoneGargoyle.PrintDescription();
		}
	}
	else if (RoomType == "Grotto")
	{
		if (rnd == 1)
		{
			enemy = imp;
			imp.PrintDescription();
		}
		else if (rnd == 2)
		{
			enemy = waterSerpent;
			waterSerpent.PrintDescription();
		}
		else if (rnd == 3)
		{
			enemy = clayGolem;
			clayGolem.PrintDescription();
		}
		else
		{
			enemy = imp;
			imp.PrintDescription();
		}
	}
	else
	{
		if (rnd == 1)
		{
			enemy = spawn;
			spawn.PrintDescription();
		}
		else if (rnd == 2)
		{
			enemy = broodMother;
			broodMother.PrintDescription();
		}
		else if (rnd == 3)
		{
			enemy = incubus;
			incubus.PrintDescription();
		}
		else
		{
			enemy = spawn;
			spawn.PrintDescription();
		}
	}
}
void Approach(Player &player)
{
	int PlayerStrength = player.ReturnStrength();
	int PlayerSpeed = player.ReturnSpeed();
	int PlayerHealth = player.ReturnHealth();
	int rnd = rand() % 3 + 1;
	int mod = (rand() % 20 + 1) - 10;
	PlayerStrength += mod;
	PlayerSpeed += mod;
	if (PlayerStrength >= 23)
	{
		if (rnd == 1)
		{
			std::cout << "It notices your approach and is frightened away by your imposing presence.\n";
		}
		else if (rnd == 2)
		{
			std::cout << "Your towering figure startles it from its curiosity, leaving behind a glowing blue stone that it was investigating. You pick up the stone and it melts away, its glow flowing into you and you feel stronger.\n";
			PlayerStrength -= mod;
			player.SetStrength(PlayerStrength + 2);
		}
		else
		{
			std::cout << "Your immense stature frightens it away from its curiosity, leaving behind a glowing red stone that it was investigating. You pick up the stone and it melts away, its glow flowing into you and you feel faster.\n";
			PlayerSpeed -= mod;
			player.SetSpeed(PlayerSpeed + 2);
		}
	}
	else if (PlayerSpeed >= 23)
	{
		if (rnd == 1)
		{
			std::cout << "You rush at the creature, startling it into a frantic escape.\n";
		}
		else if (rnd == 2)
		{
			std::cout << "You notice it is mesmerised by a glowing blue stone. You dart in and snatch the stone, frightening away the creature. The stone starts to melt away, its glow flowing into you and you feel stronger.\n";
			PlayerStrength -= mod;
			player.SetStrength(PlayerStrength + 2);
		}
		else
		{
			std::cout << "You notice it is examining a glowing red stone. You quickly dash in and pluck the stone out from under it. As the creature scurries away, the stone and melts away its glow flowing into you and you feel faster.\n";
			PlayerSpeed -= mod;
			player.SetSpeed(PlayerSpeed + 2);
		}
	}
	else
	{
		std::cout << "It notices you and strikes out before you can react. It overwhelms you, lowering your health.\n";
		player.SetHealth(PlayerHealth - 1);
		PlayerHealth = player.ReturnHealth();
		if (PlayerHealth<= 0)
		{
			std::cout << "You are weak from your wounds and collapse to the ground.\n";
			Run(player);
		}
	}

}
void Leave()
{
	std::cout << "You leave it be and move on.\n";
}
void Fight(Player &player, Enemy &enemy)
{

	int PlayerStrength = player.ReturnStrength();
	int PlayerSpeed = player.ReturnSpeed();
	int PlayerHealth = player.ReturnHealth();
	int EnemyStrength = enemy.ReturnStrength();
	int EnemySpeed = enemy.ReturnSpeed();
	int mod = (rand() % 10 + 1) - 5;
	for (int i = 0; i < 1; i++)
	{
		std::cout << "Do you want to overwhelm the creature in a FRONTAL ASSAULT, do you wish to outmaneuvre it and attempt a swift PRECISION STRIKE, or do you want to try and ESCAPE.\n";
		String Move = "temp";
		Move.ReadFromConsole();
		Move.ToLower();
		if (Move == "frontal assault")
		{
			PlayerStrength += mod;
			if ((PlayerStrength) >= EnemyStrength)
			{
				std::cout << "You crush your enemy with pure strength.\nYou gain experience from your conflict.\n";
				PlayerStrength -= mod;
				player.SetStrength(PlayerStrength + 4);
				player.SetSpeed(PlayerSpeed + 1);
			}
			else
			{
				std::cout << "The creature shrugs off your blow and hits you to the ground. As you struggle to your feet it comes charging in for another attack.\n";
				PlayerStrength -= mod;
				player.SetHealth(PlayerHealth - 1);
				PlayerHealth = player.ReturnHealth();
				std::cout << "Health: " << PlayerHealth << std::endl;
				if (PlayerHealth <= 0)
				{
					break;
				}
				else
				{
					i--;
				}
			}
		}
		else if (Move == "precision strike")
		{
			PlayerSpeed += mod;
			if ((PlayerSpeed) >= EnemySpeed)
			{
				std::cout << "You slay the creature with a cirtical blow\nYou gain experience from your conflict.\n";
				PlayerSpeed -= mod;
				player.SetSpeed(PlayerSpeed + 4);
				player.SetStrength(PlayerStrength + 1);
			}
			else
			{
				std::cout << "Your enemy dodges your strike and jumps on top of you. You struggle out from underneath it and it leaps towards you again.\n";
				PlayerSpeed -= mod;
				player.SetHealth(PlayerHealth - 1);
				PlayerHealth = player.ReturnHealth();
				std::cout << "Health: " << PlayerHealth << std::endl;
				if (PlayerHealth <= 0)
				{
					break;
				}
				else
				{
					i--;
				}
			}
		}
		else if (Move == "escape")
		{
			Run(player);
		}
		else
		{
			std::cout << "Invalid move.\n";
			i--;
		}
	}
	PlayerHealth = player.ReturnHealth();
	if (PlayerHealth <= 0)
	{
		std::cout << "You are weak from your wounds and collapse to the ground.\n";
		Run(player);
	}
}
void Run(Player &player)
{
	int PlayerStrength = player.ReturnStrength();
	int PlayerSpeed = player.ReturnSpeed();
	int PlayerHealth = player.ReturnHealth();
	if (PlayerHealth <= 0)
	{
		std::cout << "You awake, your enemy has left for a new quarry. You lay awhile to recover from your wounds, your defeat and time away from combat leaves you nervous for your next fight. You have lost experience.\n";
		PlayerStrength = 0.75*PlayerStrength;
		PlayerSpeed = 0.75*PlayerSpeed;
		player.SetHealth(10);
		player.SetStrength(PlayerStrength);
		player.SetSpeed(PlayerSpeed);
	}
	else
	{
		std::cout << "You quickly make your escape before your enemy can lock you in combat.\n";
	}
}