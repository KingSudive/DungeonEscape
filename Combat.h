#pragma once
#include "Player.h"

class Enemy
{
public:
	std::string name;
	int health = 100;
	int damage;
	
};
	
bool combat(Player& player, Enemy& enemy);
bool startCombat(Player& player);
