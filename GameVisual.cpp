using namespace std;
class GameVisual
{
private:
        char ch[60][21];
        Map* map;
public:
        GameVisual(Map* map /*mo[11][11]*/) : map(map)
        {
                for(int i = 0; i < 60; i++)
                {
                        for(int j = 0; j < 21; j++)
                        {
                                ch[i][j] = ' ';
                        }
                }
                ch[43][0] = 'T';
                ch[44][0] = 'u';
                ch[45][0] = 'r';
                ch[46][0] = 'n';
                ch[47][0] = 's';
                ch[48][0] = ':';
                ch[43][2] = 'H';
                ch[44][2] = 'P';
                ch[45][2] = ':';
                ch[43][4] = 'A';
                ch[44][4] = 'r';
                ch[45][4] = 'm';
                ch[46][4] = 'o';
                ch[47][4] = 'r';
                ch[48][4] = ':';

        }
        Map * getMap()
        {
                return map;
        }
        void draw_all_content(int i, int j, int t, int tr)
        {
            string s;
            if(t == HAMMER * 1000)
            {
                    s = " P    /M\\-I  M    ";
            }
            if(t == HAMMER * 1000 + 1)
            {
                    s = " P/-I /W     M    ";
            }
            if(t == HAMMER * 1000 + 2)
            {
                   s = " P    /M\\-I  M    ";
            }
            if(t == BAIT * 1000)
            {
                    s = " P    /M\\,   M    ";
            }
            if(t == BAIT * 1000 + 1)
            {
                    s = " P/ ' /W     M    ";
            }
            if(t == BAIT * 1000 + 2)
            {
                    s = " P    /M\\    M    ";
            }
            if(t == GRENADE * 1000)
            {
                    s = " P    /M\\o   M    ";
            }
            if(t == GRENADE * 1000 + 1)
            {
                    s = " P/ o /W     M    ";
            }
            if(t == GRENADE * 1000 + 2)
            {
                    s = " P    /M\\    M    ";
            }
            if(t == GRENADE * 1000 + 102)
            {
                    s = "******************";
            }
            if(t == ROCKET * 1000)
            {
                    s = "* * * * * * * * * ";
            }
            if(t == ROCKET * 1000 + 1)
            {
                    s = " * * * * * * * * *";
            }
            if(t == ROCKET * 1000 + 2)
            {
                    s = "* * * * * * * * * ";
            }
            if(tr == 1)
            {
                    s[16] = '[';
                    s[17] = ']';
            }
                
            ch[(i-1)*4+2][(j-1)*2+1] = s[0];
            ch[(i-1)*4+3][(j-1)*2+1] = s[1];
            ch[(i-1)*4+4][(j-1)*2+1] = s[2];
            ch[(i-1)*4+5][(j-1)*2+1] = s[3];
            ch[(i-1)*4+6][(j-1)*2+1] = s[4];
            ch[(i-1)*4+7][(j-1)*2+1] = s[5];
            ch[(i-1)*4+2][(j-1)*2+2] = s[6];
            ch[(i-1)*4+3][(j-1)*2+2] = s[7];
            ch[(i-1)*4+4][(j-1)*2+2] = s[8];                
            
            ch[(i-1)*4+5][(j-1)*2+2] = s[9];
            ch[(i-1)*4+6][(j-1)*2+2] = s[10];
            ch[(i-1)*4+7][(j-1)*2+2] = s[11];
            ch[(i-1)*4+2][(j-1)*2+3] = s[12];
            ch[(i-1)*4+3][(j-1)*2+3] = s[13];
            ch[(i-1)*4+4][(j-1)*2+3] = s[14];
            ch[(i-1)*4+5][(j-1)*2+3] = s[15];
            ch[(i-1)*4+6][(j-1)*2+3] = s[16];
            ch[(i-1)*4+7][(j-1)*2+3] = s[17];
                
        }
        void draw_content(int i, int j, int t)
        {
            string s;
            if(t == 0)
                s = "         ";
            if(t == 1)
                s = "   ___[_]";
            if(t == 2)
                s = "   ___[_]";
            if(t == 3)
                s = "   ___[_]";
            if(t == 4)
                s = "    _ CID";
            if(t == 5)
                s = "      \\ /";
            if(t == 6)
                s = "/X\\XXX\\X/";
                
                
                
            if(t == 1000)
                s = "===$$$==="; 
            if(t == 1001)
                s = "^ ^ _    ";
            if(t == 1002)
                s = "YouWon!!!";
             
                
                
            if(t == 2000)
                s = "         ";
            if(t == 2001)
                s = "   ???   ";
            if(t == 2002)
                s = "         ";
            
            if(t == 3000)
                s = "****!****";
            if(t == 3001)
                s = "   -2!   ";
            if(t == 3002)
                s = "         ";
                
            if(t == 4000)
                s = "    _ CID";
            if(t == 4001)
                s = "****!****";
            if(t == 4002)
                s = "   -2!   ";
            if(t == 5000)
                s = "   -1!\\P/";
            if(t == 5001)
                s = "    P \\W/";
            if(t == 5002)
                s = " P /W\\_M/";
            if(t == 6000)
                s = "/X\\XXX\\X/";
            if(t == 6001)
                s = "   XXX\\X/";
            if(t == 6002)
                s = "      \\X/";
                //so on


            ch[(i-1)*4+5][(j-1)*2+1] = s[0];
            ch[(i-1)*4+6][(j-1)*2+1] = s[1];
            ch[(i-1)*4+7][(j-1)*2+1] = s[2];
            ch[(i-1)*4+5][(j-1)*2+2] = s[3];
            ch[(i-1)*4+6][(j-1)*2+2] = s[4];
            ch[(i-1)*4+7][(j-1)*2+2] = s[5];
            ch[(i-1)*4+5][(j-1)*2+3] = s[6];
            ch[(i-1)*4+6][(j-1)*2+3] = s[7];
            ch[(i-1)*4+7][(j-1)*2+3] = s[8];

        }
        void draw()
        {
                map->transpose();
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
                                            ch[(i-1)*4+2][(j-1)*2+1] = ' ';
                                            ch[(i-1)*4+4][(j-1)*2+1] = ' ';
                                            ch[(i-1)*4+2][(j-1)*2+3] = ' ';
                                            ch[(i-1)*4+4][(j-1)*2+3] = ' ';
                                            ch[(i-1)*4+3][(j-1)*2+1] = 'P';
                                            ch[(i-1)*4+2][(j-1)*2+2] = '/';
                                            ch[(i-1)*4+3][(j-1)*2+2] = 'W';
                                            ch[(i-1)*4+4][(j-1)*2+2] = '\\';
                                            ch[(i-1)*4+3][(j-1)*2+3] = 'M';
                                        }
                                        else
                                        {
                                            ch[(i-1)*4+2][(j-1)*2+1] = ' ';
                                            ch[(i-1)*4+4][(j-1)*2+1] = ' ';
                                            ch[(i-1)*4+2][(j-1)*2+3] = ' ';
                                            ch[(i-1)*4+4][(j-1)*2+3] = ' ';
                                            ch[(i-1)*4+3][(j-1)*2+1] = ' ';
                                            ch[(i-1)*4+2][(j-1)*2+2] = ' ';
                                            ch[(i-1)*4+3][(j-1)*2+2] = ' ';
                                            ch[(i-1)*4+4][(j-1)*2+2] = ' ';
                                            ch[(i-1)*4+3][(j-1)*2+3] = ' ';
                                        }

                                        if(map->mo[i][j]->vision() == 0)
                                        {
                                            ch[(i-1)*4+6][(j-1)*2+2] = '?';
                                        }
                                        if(map->mo[i][j]->vision() == 1)
                                        {
                                            draw_content(i, j, map->mo[i][j]->getCT());
                                        }

                                }
                                if(map->mo[i][j]->whoami() == WALL && map->mo[i][j]->vision() == 1)
                                {
                                        if(map->mo[i][j]->getCT() == IRON_WALL)
                                        {
                                            if(i % 2 == 1)
                                            {
                                                    for(int ki = 2; ki < 8; ki++)
                                                    {
                                                            ch[(i-1)*4+ki][2*j] = '#';
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
                                        if(map->mo[i][j]->getCT() == WOOD_WALL)
                                        {
                                            if(i % 2 == 1)
                                            {
                                                    for(int ki = 2; ki < 8; ki++)
                                                    {
                                                        ch[(i-1)*4+ki][2*j] = '=';
                                                    }
                                            }
                                            else
                                            {
                                                    for(int kj = 1; kj < 4;kj++)
                                                    {
                                                        ch[i*4][2*(j-1)+kj] = '|';
                                                        ch[i*4+1][2*(j-1)+kj] = '|';
                                                    }
                                            }
                                        }
                                        if(map->mo[i][j]->getCT() == CORRUPTED_WOOD_WALL)
                                        {
                                            if(i % 2 == 1)
                                            {
                                                    for(int ki = 2; ki < 8; ki++)
                                                    {
                                                        if(ki <= 3 || ki >= 7)
                                                            ch[(i-1)*4+ki][2*j] = '=';
                                                        if(ki == 4 || ki == 6)
                                                            ch[(i-1)*4+ki][2*j] = '-';
                                                        if(ki == 5)
                                                            ch[(i-1)*4+ki][2*j] = ' ';
                                                    }
                                            }
                                            else
                                            {
                                                    for(int kj = 1; kj < 4;kj++)
                                                    {
                                                        ch[i*4][2*(j-1)+kj] = ' ';
                                                        ch[i*4+1][2*(j-1)+kj] = ' ';
                                                    }
                                                    ch[i*4][2*(j-1)+1] = '|';
                                                    ch[i*4+1][2*(j-1)+3] = '|';

                                            }
                                        }
                                        if(map->mo[i][j]->getCT() == CORRUPTED_IRON_WALL)
                                        {
                                            if(i % 2 == 1)
                                            {
                                                    for(int ki = 2; ki < 8; ki++)
                                                    {
                                                        if(ki <= 3 || ki >= 7)
                                                            ch[(i-1)*4+ki][2*j] = '#';
                                                        else
                                                            ch[(i-1)*4+ki][2*j] = '=';
                                                    }
                                            }
                                            else
                                            {
                                                    for(int kj = 1; kj < 4;kj++)
                                                    {
                                                        ch[i*4][2*(j-1)+kj] = '|';
                                                        ch[i*4+1][2*(j-1)+kj] = '|';
                                                    }
                                                    ch[i*4][2*(j-1)+1] = '#';
                                                    ch[i*4+1][2*(j-1)+3] = '#';

                                            }
                                        }
                                        if(map->mo[i][j]->getCT() == EMPTY)
                                        {
                                            if(i % 2 == 1)
                                            {
                                                    for(int ki = 2; ki < 8; ki++)
                                                    {
                                                            ch[(i-1)*4+ki][2*j] = ' ';
                                                    }
                                            }
                                            else
                                            {
                                                    for(int kj = 1; kj < 4;kj++)
                                                    {
                                                            ch[i*4][2*(j-1)+kj] = ' ';
                                                            ch[i*4+1][2*(j-1)+kj] = ' ';
                                                    }
                                            }
                                        }
                                }
                                if(map->mo[i][j]->whoami() == WALL && map->mo[i][j]->vision() == 0)
                                {
                                    if(i % 2 == 1)
                                    {
                                            for(int ki = 4; ki < 6; ki++)
                                            {
                                                ch[(i-1)*4+ki][2*j] = '?';
                                            }
                                    }
                                    else
                                    {
                                        ch[i*4][2*(j-1)+2] = '?';
                                        ch[i*4+1][2*(j-1)+2] = '?';
                                    }
                                }

                        }
                }
                for(int j = 0; j < 21; j++)
                {
                        for(int i = 0; i < 60; i++)
                        {
                                cout << ch[i][j];
                        }
                        cout << endl;
                }
                //sleep(10);
                map->transpose();
                std::cout << "draw done\n"; sleep(3);
        }
        void updateStat(int turns, int hp, int armor)
        {
                ch[59][0] = '0' + (turns % 10);
                ch[58][0] = '0' + (turns / 10);
                ch[59][2] = '0' + (hp % 10);
                ch[59][4] = '0' + (armor % 10);         
        }
        //num_anim = mo[i][j]->getCT();
        void treasureAnimate(int xi, int xj, int t)
        {
                    draw();
                    for(int k = 0; k < 3; k++)
                    {
                                draw_content(xj, xi, t*1000+k);
                                system("clear");
                                for(int j = 0; j < 21; j++)
                                {
                                for(int i = 0; i < 60; i++)
                                {
                                              cout << ch[i][j];
                                }
                                cout << endl;
                                }
                                sleep(1);
                    }
        }
        void animation(int xi, int xj)
        {
                
                int t = map->mo[xi][xj]->getCT();
                if(t == MINE || t == WEB)
                {
                    draw();
                    for(int k = 0; k < 3; k++)
                    {
                                draw_content(xj, xi, map->mo[xi][xj]->getCT()*1000+k);
                                system("clear");
                                for(int j = 0; j < 21; j++)
                                {
                                for(int i = 0; i < 60; i++)
                                {
                                              cout << ch[i][j];
                                }
                                cout << endl;
                                }
                                sleep(1);
                    }
                }
                if(t == PIT)
                { 
                    map->mo[xi][xj]->is_player_here = 0;
                    draw();
                    for(int k = 0; k < 3; k++)
                    {
                                draw_content(xj, xi, map->mo[xi][xj]->getCT()*1000+k);
                                system("clear");
                                for(int j = 0; j < 21; j++)
                                {
                                for(int i = 0; i < 60; i++)
                                {
                                      cout << ch[i][j];
                                }
                                cout << endl;
                                }
                                sleep(1);
                    }
                    map->mo[xi][xj]->is_player_here = 1;
                    
                }
                
        }
        void itemAnimation(int t, int xi, int xj, int xie = 0, int xje = 0)
        {
                if(t == HAMMER || t == BAIT)
                { 
                    map->mo[xi][xj]->is_player_here = 0;
                    draw();
                    int tr;
                    for(int k = 0; k < 3; k++)
                    {
                                tr = 0;
                                if(map->mo[xi][xj]->getCT() >= 2 && map->mo[xi][xj]->getCT() <= 4)
                                        tr = 1;
                                draw_all_content(xj, xi, t * 1000 + k, tr);
                                system("clear");
                                for(int j = 0; j < 21; j++)
                                {
                                for(int i = 0; i < 60; i++)
                                {
                                      cout << ch[i][j];
                                }
                                cout << endl;
                                }
                                sleep(1);
                    }
                    map->mo[xi][xj]->is_player_here = 1;
                    
                }
                if(t == GRENADE)
                { 
                    map->mo[xi][xj]->is_player_here = 0;
                    draw();
                    int tr;
                    for(int k = 0; k < 3; k++)
                    {
                                tr = 0;
                                if(map->mo[xi][xj]->getCT() >= 2 && map->mo[xi][xj]->getCT() <= 4)
                                        tr = 1;
                                draw_all_content(xj, xi, t * 1000 + k, tr);
                                if(k == 2)
                                        draw_all_content(xje, xie, t * 1000 + 102, tr); //100 * 1 is additional second(first from 0) field modifier
                                system("clear");
                                for(int j = 0; j < 21; j++)
                                {
                                for(int i = 0; i < 60; i++)
                                {
                                      cout << ch[i][j];
                                }
                                cout << endl;
                                }
                                sleep(1);
                    }
                    map->mo[xi][xj]->is_player_here = 1;
                    
                }
                if(t == ROCKET)
                { 
                    draw();
                    int tr;
                    for(int k = 0; k < 3; k++)
                    {
                                tr = 0;
                                //animation is wrong:: highlights 2 ceils and draws false treasure
                                draw_all_content(xj, xi, t * 1000 + k, tr);
                                if(xj + 2 >= 1 && xj + 2 <= 9)
                                         draw_all_content(xj + 2, xi, t * 1000 + k, tr);
                                if(xi + 2 >= 1 && xi + 2 <= 9)
                                         draw_all_content(xj, xi + 2, t * 1000 + k, tr);
                                if(xi - 2 >= 1 && xi - 2 <= 9)
                                         draw_all_content(xj, xi - 2, t * 1000 + k, tr);
                                if(xj - 2 >= 1 && xj - 2 <= 9)
                                         draw_all_content(xj - 2, xi, t * 1000 + k, tr);
                                system("clear");
                                for(int j = 0; j < 21; j++)
                                {
                                for(int i = 0; i < 60; i++)
                                {
                                      cout << ch[i][j];
                                }
                                cout << endl;
                                }
                                sleep(1);
                    }
                    
                }
                
        }
};
