#include "Combat.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

int randomInt(int min, int max)
{
	static std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(rng);
}

bool playerChoices(Player& player, Enemy& enemy, int input)
{
	if (input == 1)
	{
		int attackDamage = player.hasItem("Iron Sword") ? randomInt(25, 40) : randomInt(15, 25);
		std::cout << "\n" "You strike for " << attackDamage << " damage!\n\n";
		enemy.health -= attackDamage;

		int enemyDamage = randomInt(5, enemy.damage);
		std::cout << "\nThe skeleton hits you for " << enemyDamage << "!\n";
		player.health -= enemyDamage;
	}

	else if (input == 2)
	{
		std::cout << "\nThe enemy attacks you, but too weak to hurt you ;)\n\n";
		int enemyDamage = randomInt(5, enemy.damage);
		player.health -= enemyDamage / 2;
	}
	else if (input == 3)
	{
		if (player.hasItem("Health Potion"))
		{
			if (player.health + 40 > 100)
			{
				player.health = 100;
			}
			else
			{
				player.health += 40;
			}

			auto item = std::find(player.inventory.begin(), player.inventory.end(), "Health Potion");
			if (item != player.inventory.end()) {
				player.inventory.erase(item);
			}
		}
		std::cout << "You don't have any potions!\n";
		return false;
	}
}


bool combat(Player& player, Enemy& enemy)
{
	system("cls");
	
	int input;
	bool combatState;
	while (true)
	{
		std::cout << "\n-----------------------------\n";
		std::cout << "What do you want to do?  \n";

		std::cout << "1. Attack \t 2. Defend \t 3. Use Potion\n";

	
		std::cin >> input;
		
		bool whatPlayerDecided = playerChoices(player, enemy, input);

		if (!whatPlayerDecided)
		{
			continue;
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
