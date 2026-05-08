#include "Player.h"
#include <iostream>

void Player::init()
{

	std::string input;
	std::cout << "Enter your name: ";
	std::cin >> input;
	name = input;
	std::cout << "Welcome, " << name << "! You wake up in a dark dungeon...\n\n";
}

bool Player::hasItem(std::string itemName)
{
	for (std::string item : inventory)
	{
		if (item == itemName)
		{
			return true;
		}
	}

	return false;
}