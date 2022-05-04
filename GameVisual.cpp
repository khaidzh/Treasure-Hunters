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
        Map * getMap()
        {
                return map;
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
            if(t == 4000)
                s = "    _ CID";
            if(t == 4001)
                s = "*********";
            if(t == 4002)
                s = "Off _ CID";
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
                                            ch[(i-1)*4+3][(j-1)*2+1] = 'P';
                                            ch[(i-1)*4+2][(j-1)*2+2] = '/';
                                            ch[(i-1)*4+3][(j-1)*2+2] = 'W';
                                            ch[(i-1)*4+4][(j-1)*2+2] = '\\';
                                            ch[(i-1)*4+3][(j-1)*2+3] = 'M';
                                        }
                                        else
                                        {
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
                        for(int i = 0; i < 42; i++)
                        {
                                cout << ch[i][j];
                        }
                        cout << endl;
                }
                //sleep(10);
                map->transpose();
        }
        //num_anim = mo[i][j]->getCT();
        void animation(int xi, int xj)
        {
                draw();
                for(int k = 0; k < 3; k++)
                {
                        draw_content(xj, xi, map->mo[xi][xj]->getCT()*1000+k);
                        system("clear");
                        for(int j = 0; j < 21; j++)
                        {
                              for(int i = 0; i < 42; i++)
                              {
                                      cout << ch[i][j];
                              }
                        cout << endl;
                        }
                        sleep(1);
                }
                
                
        }
};
