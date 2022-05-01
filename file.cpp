#include <bits/stdc++.h>
#include <unistd.h>
#include "Map.h"
#include "MapObject.cpp"
#include "Field.cpp"
#include "Wall.cpp"
#include "Column.cpp"
#include "Map.cpp"

using namespace std;

class GameVisual
{
private:
        char ch[42][21];
        Map* map;
public:
        GameVisual(Map* map /*mo[11][11]*/) : map(map)
        {
                for(int i = 0; i < 42; i++)
                {
                        for(int j = 0; j < 21; j++)
                        {
                                ch[i][j] = ' ';
                        }
                }

        }
        void draw()
        {
                system("clear");
                for(int i = 0; i < 11; i++)
                {
                        for(int j = 0; j < 11; j++)
                        {
                                if(map->mo[i][j]->whoami() == COLUMN)
                                {
                                        ch[4*i][2*j] = 'I';
                                        ch[4*i+1][2*j] = 'I';
                                }
                                if(map->mo[i][j]->whoami() == FIELD)
                                {
                                        /*for(int ki = 2; ki < 8; ki++)
                                        {
                                                for(int kj = 1; kj < 4; kj++)
                                                {
                                                        ch[(i-1)*4+ki][(j-1)*2+kj] = '+';
                                                }
                                        }*/
                                        if(map->mo[i][j]->is_player_here == 1)
                                        {
                                            ch[(i-1)*4+3][(j-1)*2+1] = 'P';
                                            ch[(i-1)*4+2][(j-1)*2+2] = '/';
                                            ch[(i-1)*4+3][(j-1)*2+2] = 'W';
                                            ch[(i-1)*4+4][(j-1)*2+2] = '\\';
                                            ch[(i-1)*4+3][(j-1)*2+3] = 'P';
                                        }


                                }
                                if(map->mo[i][j]->whoami() == WALL)
                                {
                                        if(map->mo[i][j]->getCT() == IRON_WALL)
                                        {
                                            if(i % 2 == 1)
                                            {
                                                    for(int ki = 2; ki < 8; ki++)
                                                    {
                                                            ch[(i-1)*4+ki][2*j] = '#'; //ch for col
                                                    }
                                            }
                                            else
                                            {
                                                    for(int kj = 1; kj < 4;kj++)
                                                    {
                                                            ch[i*4][2*(j-1)+kj] = '#';
                                                            ch[i*4+1][2*(j-1)+kj] = '#';
                                                    }
                                            }
                                        }
                                }
                        }
                }
                for(int j = 0; j < 21; j++)
                {
                        for(int i = 0; i < 42; i++)
                        {
                                cout << ch[i][j];
                        }
                        cout << endl;
                }
                sleep(10);
        }
};
int main()
{
        Map map;
        GameVisual v(&map);
        v.draw();
}