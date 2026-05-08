#pragma once

#include <string>
#include <vector>
#include "Player.h"

struct Room
{
	std::string roomName;
	std::string roomDesc;
	std::string item;
	std::vector<int> connections;
	bool hasEnemy;
};

void getAllRooms(std::vector<int>& connections, std::vector<Room>& dungeon);
void giveItem(Player& player, std::string& item);
void playerMovement(std::vector<int>& connections, int input, int& currentRoom);
