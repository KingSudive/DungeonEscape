#pragma once

#include <string>
#include <vector>

class Player
{
public:
	std::string name;
	int health = 100;
	std::vector<std::string> inventory;
	
	void init();

	bool hasItem(const std::string& itemName);
};
