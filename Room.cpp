#include <iostream>
#include "Room.h"

void getAllRooms(std::vector<int>& connections, std::vector<Room>& dungeon)
{
	for (int conn : connections)
	{
		std::cout << "  " << conn << " - " << dungeon[conn].roomName << "\n";
	}
}

void giveItem(Player& player, std::string& item)
{
	if (!item.empty())
	{
		std::cout << "\nYou found: " << item << "!\n";
		player.inventory.push_back(item);
		item = "";
	}
}

void playerMovement(std::vector<int>& connections, int input, int& currentRoom)
{
	bool valid = false;
	for (int conn : connections)
	{
		if (input == conn)
		{
			valid = true;
			break;
		}
	}

	if (valid)
	{
		currentRoom = input;
	}
	else
	{
		std::cout << "You can't go there!\n";
	}
}
