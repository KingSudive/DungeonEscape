#include <iostream>
#include "Player.h"
#include "Room.h"
#include "Combat.h"

int main()
{
	Player player;
	player.init();

	std::vector<Room> dungeon = {
		{"Dark Cell", "A cold, damp cell. There's a door to the north.", "Rusty key", {1}, false},
		{"Hallway", "A long stone hallway. Doors left and right", "", {0, 2, 3, 4, 6}, true},
		{"Armory", "Old weapons line the walls.", "Iron Sword", {1}, false},
		{"Exit Gate", "A massive iron gate. Freedom is close", "", {1, 6}, false},
		{"Guard Room", "A torch-lit room. Bones are scattered across the floor.", "Health Potion", {1, 5}, true},
		{"Treasure Vault", "Gold glimmers in the dim light. A chest sits in the corner.", "Gold Coint", {4}, false},
		{"Collapsed Tunnel", "Rubble blocks most of the path. You squeeze through a gap.", "", {1, 3}, false },
	};

	int currentRoom = 0;
	int input;
	while (currentRoom != 3)
	{
		system("cls");
		std::cout << "\n--- " << dungeon[currentRoom].roomName << " ---\n" << dungeon[currentRoom].roomDesc << "\n\n";
		std::cout << "You can go to: \n";

		getAllRooms(dungeon[currentRoom].connections, dungeon);

		giveItem(player, dungeon[currentRoom].item);

		std::cout << "\nWhere do you go? ";
		std::cin >> input;

		if (input == 3 && !player.hasItem("Rusty Key"))
		{
			std::cout << "\nThe gate is locked. You need a key...";
			std::cout << "\n\nPress Enter to return...";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
			continue;
		}

		playerMovement(dungeon[currentRoom].connections, input, currentRoom);

		if (dungeon[currentRoom].hasEnemy)
		{
			dungeon[currentRoom].hasEnemy = startCombat(player);
			if (player.health <= 0)
			{
				return 0;
			}
		}
		
	}

	std::cout << "Finnaly you got freedom!... Here is your items: \n";
	for (std::string items : player.inventory)
	{
		std::cout << items << "\n";
	}

	return 0;
}
