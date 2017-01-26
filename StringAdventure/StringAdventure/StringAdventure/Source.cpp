#include <iostream>
#include "String.h"
#include "Player.h"
#include "Map.h"
#include "Room.h"
#include "Enemy.h"
#include "SpawnCreature.h"

void AskForMove(Player &player);
void CharacterCreation(Player &player);
void Boss(Player &player);


int MapSize = 100;



int main()
{
	Player player(MapSize / 2, MapSize / 2);
	CharacterCreation(player);
	String playerStatChoices[3];
	playerStatChoices[0] = player.ReturnStats(0);
	playerStatChoices[1] = player.ReturnStats(1);
	playerStatChoices[2] = player.ReturnStats(2);


	Map map(MapSize);

	while (true)
	{
		int PlayerHealth = player.ReturnHealth();
		int PlayerStrength = player.ReturnStrength();
		int PlayerSpeed = player.ReturnSpeed();
		if (PlayerSpeed > 60 && PlayerStrength > 60)
		{
			std::cout << "You are so adapt at combat that this realm no longer holds any challenge worthy of your skill. You meditate on your trials.\n";
			system("pause");
			Boss(player);
			system("pause");
			break;
		}
		system("cls");
		std::cout << "Health: " << PlayerHealth << std::endl;
		std::cout << "Strength: " << PlayerStrength << std::endl;
		std::cout << "Speed: " << PlayerSpeed << std::endl;
		std::cout << "Weapon: "; 
		playerStatChoices[0].WriteToConsole();
		std::cout << std::endl;
		std::cout << "Class: ";
		playerStatChoices[1].WriteToConsole();
		std::cout << std::endl;
		std::cout << "Perk: ";
		playerStatChoices[2].WriteToConsole();
		std::cout << "--------------------------------------------------------------------------------";
		std::cout << "\n";
		int PlayerPosX = player.ReturnPos()[0];
		int PlayerPosY = player.ReturnPos()[1];
		Room* CurrentRoom = map.ReturnRoom(PlayerPosX, PlayerPosY);
		std::cout << "You have entered a ";
		String* RoomType = CurrentRoom->ReturnRoomType();
		RoomType->WriteToConsole();
		std::cout << std::endl;
		CurrentRoom->PrintDescription();
		SpawnCreature(*RoomType, player);
		AskForMove(player);
	}
	return 0;
}

void AskForMove(Player &player)
{
	for (int i = 0; i < 1; i++)
	{
		std::cout << "Do you want to move North, East, South or West.\n";
		String Move = "temp";
		Move.ReadFromConsole();
		Move.ToLower();
		int PlayerPosX = player.ReturnPos()[0];
		int PlayerPosY = player.ReturnPos()[1];
		if (Move == "north")
		{
			player.SetPos(PlayerPosX, PlayerPosY + 1);
		}
		else if (Move == "east")
		{
			player.SetPos(PlayerPosX + 1, PlayerPosY);
		}
		else if (Move == "south")
		{
			player.SetPos(PlayerPosX, PlayerPosY - 1);
		}
		else if (Move == "west")
		{
			player.SetPos(PlayerPosX - 1, PlayerPosY);
		}
		else
		{
			std::cout << "Invalid move.\n";
			i--;
		}

		PlayerPosX = player.ReturnPos()[0];
		PlayerPosY = player.ReturnPos()[1];

		if (PlayerPosX > MapSize-1)
		{ 
			std::cout << "You cannot go further.\n";
			player.SetPos(PlayerPosX - 1, PlayerPosY);
			i--;
		}
		else if (PlayerPosY > MapSize-1)
		{ 
			std::cout << "You cannot go further.\n";
			player.SetPos(PlayerPosX, PlayerPosY -1);
			i--;
		}
		else if (PlayerPosX < 0)
		{
			std::cout << "You cannot go further.\n";
			player.SetPos(PlayerPosX + 1, PlayerPosY);
			i--;
		}
		else if (PlayerPosY < 0)
		{
			std::cout << "You cannot go further.\n";
			player.SetPos(PlayerPosX, PlayerPosY + 1);
			i--;
		}
		else
		{
		}
	}
}

void CharacterCreation(Player &player)
{
	std::cout << "Character Creation\n";
	for (int i = 0; i < 1; i++)
	{
		std::cout << "What class would you like to be: WARRIOR, CRUSADER, RANGER, THIEF or ASSASSIN.\n";
		String Class;
		String Warrior = "warrior";
		String Crusader = "crusader";
		String Ranger = "ranger";
		String Thief = "thief";
		String Assassin = "assassin";
		int PlayerStrength = player.ReturnStrength();
		int PlayerSpeed = player.ReturnSpeed();
		Class.ReadFromConsole();
		Class.ToLower();
		if (Class == Warrior)
		{
			player.SetStats(Warrior, 1);
			player.SetSpeed(PlayerSpeed - 4);
			player.SetStrength(PlayerStrength + 12);
		}
		else if (Class == Crusader)
		{
			player.SetStats(Crusader, 1);
			player.SetStrength(PlayerStrength + 8);
		}
		else if (Class == Ranger)
		{
			player.SetStats(Ranger, 1);
			player.SetSpeed(PlayerSpeed + 4);
			player.SetStrength(PlayerStrength + 4);
		}
		else if (Class == Thief)
		{
			player.SetStats(Thief, 1);
			player.SetSpeed(PlayerSpeed + 8);
		}
		else if (Class == Assassin)
		{
			player.SetStats(Assassin, 1);
			player.SetSpeed(PlayerSpeed + 12);
			player.SetStrength(PlayerStrength - 4);
		}
		else
		{
			std::cout << "Invalid choice\n";
			i--;
		}
	}
	
	for (int i = 0; i < 1; i++)
	{
		std::cout << "What perk would you like: superior REFLEXES, brute STRENGTH, FOCUS, DIVERSE.\n";
		String Perk;
		String Reflexes = "reflexes";
		String Strength = "strength";
		String Focus = "focus";
		String Diverse = "diverse";
		int PlayerStrength = player.ReturnStrength();
		int PlayerSpeed = player.ReturnSpeed();
		Perk.ReadFromConsole();
		Perk.ToLower();
		if (Perk == Reflexes)
		{
			player.SetStats(Reflexes, 2);
			player.SetSpeed(PlayerSpeed + 15);
		}
		else if (Perk == Strength)
		{
			player.SetStats(Strength, 2);
			player.SetStrength(PlayerStrength + 15);
		}
		else if (Perk == Focus)
		{
			player.SetStats(Focus, 2);
			player.SetSpeed(PlayerSpeed * 1.5);
			player.SetStrength(PlayerStrength * 1.5);
		}
		else if (Perk == Diverse)
		{
			player.SetStats(Diverse, 2);
			player.SetSpeed(PlayerSpeed + 7);
			player.SetStrength(PlayerStrength + 7);
		}
		else
		{
			std::cout << "Invalid choice\n";
			i--;
		}
	}
	for (int i = 0; i < 1; i++)
	{
		std::cout << "What weapon would you like: WARHAMMER, WARAXE, SWORD, DAGGER or BOW.\n";
		String Weapon;
		String Warhammer = "warhammer";
		String Waraxe = "waraxe";
		String Sword = "sword";
		String Dagger = "dagger";
		String Bow = "bow";
		int PlayerStrength = player.ReturnStrength();
		int PlayerSpeed = player.ReturnSpeed();
		Weapon.ReadFromConsole();
		Weapon.ToLower();
		if (Weapon == Warhammer)
		{
			player.SetStats(Warhammer, 0);
			player.SetSpeed(PlayerSpeed - 4);
			player.SetStrength(PlayerStrength + 8);
		}
		else if (Weapon == Waraxe)
		{
			player.SetStats(Waraxe, 0);
			player.SetStrength(PlayerStrength + 4);
		}
		else if (Weapon == Sword)
		{
			player.SetStats(Sword, 0);
			player.SetSpeed(PlayerSpeed + 2);
			player.SetStrength(PlayerStrength + 2);
		}
		else if (Weapon == Dagger)
		{
			player.SetStats(Dagger, 0);
			player.SetSpeed(PlayerSpeed + 4);
		}
		else if (Weapon == Bow)
		{
			player.SetStats(Bow, 0);
			player.SetSpeed(PlayerSpeed + 8);
			player.SetStrength(PlayerStrength - 4);
		}
		else
		{
			std::cout << "Invalid choice\n";
			i--;
		}
	}
	int PlayerSpeed = player.ReturnSpeed();
	if (PlayerSpeed < 2)
	{
		player.SetSpeed(2);
	}
	int PlayerStrength = player.ReturnStrength();
	if (PlayerStrength < 2)
	{
		player.SetStrength(2);
	}
	system("pause");
	system("cls");

}

void Boss(Player &player)
{
	std::cout << "And as in uffish thought, the ground starts to shake as in fornt of you a swirl of purple smoke grows out of thin air. A dark figure steps forward from the smoke. " <<
		"As the smoke dissipates the figure clarifies in a tall figure prickling with with bladed edges and needle points.\nIt exclaims 'I have waited a long time for an adversary worthy of my power'.\n" <<
		"You stare at it bemused and then it starts walking towards you.\n";
	int PlayerStrength = player.ReturnStrength();
	int PlayerSpeed = player.ReturnSpeed();
	int PlayerHealth = player.ReturnHealth();
	int EnemyStrength = 70;
	int EnemySpeed = 70;
	int mod = (rand() % 20 + 1) - 5;
	for (int i = 0; i < 1; i++)
	{
		std::cout << "Do you want to overwhelm the monster in a FRONTAL ASSAULT or do you wish to outmaneuvre it and attempt a swift PRECISION STRIKE.\n";
		String Move = "temp";
		Move.ReadFromConsole();
		Move.ToLower();
		if (Move == "frontal assault")
		{
			PlayerStrength += mod;
			if ((PlayerStrength) >= EnemyStrength)
			{
				PlayerStrength -= mod;
				std::cout << "You crush your enemy with pure strength.\n";
			}
			else
			{
				std::cout << "The creature shrugs off your blow and hits you to the ground. As you struggle to your feet it comes charging in for another attack.\n";
				PlayerStrength -= mod;
				player.SetHealth(PlayerHealth - 1);
				PlayerHealth = player.ReturnHealth();
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
				PlayerSpeed -= mod;
				std::cout << "You slay the creature with a cirtical blow\n";
			}
			else
			{
				std::cout << "Your enemy dodges your strike and jumps on top of you. You struggle out from underneath it and it leaps towards you again.\n";
				PlayerSpeed -= mod;
				player.SetHealth(PlayerHealth - 1);
				PlayerHealth = player.ReturnHealth();
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
		else
		{
			std::cout << "Invalid move.\n";
			i--;
		}
	}
	PlayerHealth = player.ReturnHealth();
	if (PlayerHealth <= 0)
	{
		std::cout << "\n\nThe mysterious figure has triumphed and your journey has ended.\n";
	}
	else
	{
		std::cout << "\n\nYou set off to find a new journey.\n";
	}
}