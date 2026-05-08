#include "Combat.h"
#include <iostream>
#include <vector>
#include <string>


bool combat(Player& player, Enemy& enemy)
{
	system("cls");
	
	int input;
	bool combatState;
	while (true)
	{
		std::cout << "\n-----------------------------\n";
		std::cout << "What do you want to do?  \n";

		std::cout << "1. Attack \t 2. Defend\n";

	
		std::cin >> input;
		
		if (input == 1)
		{

			int attackDamage = player.hasItem("Iron Sword") ? 30 : 20;
			std::cout << "\n" << player.name << " attacks the enemy!\n\n";
			enemy.health -= attackDamage;

			std::cout << "The enemy returns the attack!\n\n";
			player.health -= enemy.damage;
		}

		else if (input == 2)
		{
			std::cout << "The enemy attacks you, but too weak to hurt you ;)\n\n";
			player.health -= enemy.damage / 2;
		}


		std::cout << enemy.name << " HP: " << enemy.health << "\n";
		std::cout << player.name << " HP: " << player.health << "\n";
		
		if (enemy.health <= 0)
		{
			std::cout << "You win.\n";
			combatState = true;
			break;
		}
		else if (player.health <= 0)
		{
			std::cout << "You are dead!.\n";
			combatState = false;
			break;
		}
	}

	std::cout << "\n\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	return combatState;
}

bool startCombat(Player& player)
{
	Enemy enemy{ "Skeleton", 100, 20 };
	bool survived = combat(player, enemy);

	if (!survived)
	{
		std::cout << "Game Over...\n";
		return true;
	}

	return false;
}
