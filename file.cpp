#include <bits/stdc++.h>
#include <unistd.h>
class Field;
class Player;
class Map;
class GameVisual;
class MapObject;
#include "another.cpp"
#include "Item.h"
#include "Map.h"
#include "GameVisual.cpp"
#include "Player.h"
#include "Player.cpp"
#include "Item.cpp"
#include "MapObject.cpp"
#include "Field.cpp"
#include "Wall.cpp"
#include "Column.cpp"
#include "Map.cpp"

int main()
{
	//Map edit;
	//edit_map
    //encrypt() decipher()
    char cipher[] = "c4c4c4c4c4c0 0t0f0d0m4c2c2c2c2c0c4 0 0 0w0p4c0c0c2c2c2c4 0 0 2 0 4c0c0c0c0c0c4 0 0 0 0 4c0c2c2c2c0c4 0 0 0 0 4c4c4c4c4c4c";
    Map map(cipher);
    GameVisual gv(&map);
    Player player(&gv, 1, 1);
    
    player.inventory[0] = std::make_pair(HAMMER, 1);
    player.inventory[1] = std::make_pair(CROSSBOW, 100);
    player.inventory[2] = std::make_pair(GRENADE, 100);
    player.inventory[3] = std::make_pair(ROCKET, 100);
    player.inventory[4] = std::make_pair(POTION, 100);

    while (player.isPlaying())
    {
        gv.draw();
        int c = getch();
        player.move(c);
    }
    gv.draw();
    std::cout << ((player.isAlive()) ? "WIN" : "DEFEAT") << endl;




        /////////////////////////////
        char* cipher_ = map.encode();
        for (int i = 0; i < MAP_SIZE * MAP_SIZE; i++)
        	std::cout << cipher_[i];
        std::cout << std::endl;
       	delete[] cipher_;
}