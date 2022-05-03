#include <bits/stdc++.h>
#include <unistd.h>
#include "Item.h"
#include "Map.h"
#include "Item.cpp"
#include "MapObject.cpp"
#include "Field.cpp"
#include "Wall.cpp"
#include "Column.cpp"
#include "Map.cpp"
#include "GameVisual.cpp"
#include "Player.h"
#include "Player.cpp"
#include "another.cpp"

int main()
{
        char code[] = "c4c4c4c4c4c0 0t0f0d0m4c1c3c1c3c0c4 0 0 0w0p4c0c2c2c2c2c4 0 0 2 0 4c2c2c0c0c0c4 0 2 0 2 4c0c2c2c2c0c4 0 0 0 0 4c4c4c4c4c4c";
        Map map(code);
        GameVisual visual(&map);
        Player player(&map, &visual, 1, 1);
        
        while (1)
        {
            visual.draw();
            int c = getch();
            player.move(c);
        }
}
