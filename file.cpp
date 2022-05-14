#include <bits/stdc++.h>
#include <unistd.h>
#include "Classes.h"
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
#include "sender.cpp"
#include "receiver.cpp"

int main()
{
    char cipher[] = "c4c4c4c4c4c0_0t0f0d0m4c2c2c2c2c0c4_0_0_0w0p4c0c0c2c2c2c4_0_0_2_0_4c0c0c0c0c0c4_0_0_0_0_4c0c2c2c2c0c4_0_0_0_0_4c4c4c4c4c4c";
	char level1[] = "c4c4c4c4c4c0_0_0_0_0_4c2c0c2c0c0c4p2_0w0_2m4c0c4c2c0c0c4_0t0m2_0m4c0c4c0c0c2c4_2f0_0_0p4c0c0c0c0c0c4_0_0m2w0p4c4c4c4c4c4c";
    char level2[] = "c4c4c4c4c4c0_0_0_0_0m4c0c0c0c0c0c4m0m0m2_0m4c2c2c2c0c0c4p4_0_0_0m4c0c0c0c0c4c4w4d4p0p0f4c0c0c2c2c0c4w0_0_0_0t4c4c4c4c4c4c";
	char level3[] = "c4c4c4c4c4c0_0_0f0p0m4c2c2c0c2c2c4m0m0_0_0m4c4c2c4c0c4c4w4m4w4_0_4c4c0c4c2c0c4_0p0p0p0_4c0c0c0c0c4c4m2p2t2p4d4c4c4c4c4c4c";

    Map map(cipher);
    GameVisual gv(&map);
    Player player(&gv, 1, 1);
    
    player.inventory[0] = std::make_pair(HAMMER, 1);
    player.inventory[1] = std::make_pair(CROSSBOW, 3);
    player.inventory[2] = std::make_pair(GRENADE, 1);
    player.inventory[3] = std::make_pair(ROCKET, 1);
    player.inventory[4] = std::make_pair(POTION, 3);
    player.inventory[5] = std::make_pair(BAIT, 3);

    while (player.isPlaying())
    {
        gv.draw();
        int c = getch();
        player.move(c);
    }
    gv.draw();
    std::cout << ((player.isAlive()) ? "WIN" : "DEFEAT") << endl;

    //char* cipher_ = map.encode();
    sender(level1);
    //free(cipher_);
}