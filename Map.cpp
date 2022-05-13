// Map::Map()
// {
// 	//empty
// }

Map::Map()
{
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			if (i % 2 == 1 && j % 2 == 1)
			{
				mo[i][j] = new Field;
				mo[i][j]->discover();
			}
			else if (i % 2 == 1 || j % 2 == 1)
			{
				mo[i][j] = new Wall;
				mo[i][j]->discover();
			}
			else 
				mo[i][j] = new Column;

	for (int i = 1; i < MAP_SIZE; i += 2)
	{
		mo[i][0]->setCT(IRON_WALL);
		mo[0][i]->setCT(IRON_WALL);
		mo[i][MAP_SIZE - 1]->setCT(IRON_WALL);
		mo[MAP_SIZE - 1][i]->setCT(IRON_WALL);
	}
}

Map::~Map()
{
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			delete mo[i][j];
}

Map::Map(const char code[MAP_SIZE * MAP_SIZE + 1])
{
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++) 
		switch(code[i * MAP_SIZE + j])
		{
			case 'c':
				mo[i][j] = new Column();
				break;
			case '0':
				mo[i][j] = new Wall();
				break;
			case '1':
				mo[i][j] = new Wall(CORRUPTED_WOOD_WALL);
				break;
			case '2':
				mo[i][j] = new Wall(WOOD_WALL);
				break;
			case '3':
				mo[i][j] = new Wall(CORRUPTED_IRON_WALL);
				break;
			case '4':
				mo[i][j] = new Wall(IRON_WALL);
				break;
			case '_':
				mo[i][j] = new Field();
				break;
			case 's':
				mo[i][j] = new Field();
				mo[i][j]->is_player_here = true;
				break;
			case 't':
				mo[i][j] = new Field(TREASURE);
				break;
			case 'f':
				mo[i][j] = new Field(FALSE_TREASURE);
				break;
			case 'd':
				mo[i][j] = new Field(MINED_TREASURE);
				break;
			case 'm':
				mo[i][j] = new Field(MINE);
				break;
			case 'p':
				mo[i][j] = new Field(PIT);
				break;
			case 'w':
				mo[i][j] = new Field(WEB);
				break;
		}
}

Field* Map::getField(int i, int j)
{
	return (Field*)mo[i][j];
}

Wall* Map::getWall(int i, int j)
{
	return (Wall*)mo[i][j];
}

Column* Map::getColumn(int i, int j)
{
	return (Column*)mo[i][j];
}

void Map::discoverField(int i, int j)
{	
	mo[i][j]->discover();
	mo[i - 1][j]->discover();
	mo[i + 1][j]->discover();
	mo[i][j - 1]->discover();
	mo[i][j + 1]->discover();
}


void Map::destroyField(int& hp, int i, int j)
{
	if (mo[i][j]->getCT() == TREASURE)
	{
		hp = 0;
		std::cout << "Treasure has been blowed up!\n";
		sleep(1);
	}
	mo[i][j]->setCT(NOTHING);
	mo[i - 1][j]->setCT(EMPTY);
	mo[i + 1][j]->setCT(EMPTY);
	mo[i][j - 1]->setCT(EMPTY);
	mo[i][j + 1]->setCT(EMPTY);
}
/*
c4c4c4c4c4c
0 0t0f0d0m4
c2c2c2c2c0c
4 0 0 0w0p4
c0c0c2c2c2c
4 0 0 2 0 4
c0c0c0c0c0c
4 0 0 0 0 4
c0c2c2c2c0c
4 0 0 0 0 4
c4c4c4c4c4c
*/

char* Map::encode() const
{
	char* code = (char *)malloc(MAP_SIZE * MAP_SIZE + 2);
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
		{
			char& c = code[i * MAP_SIZE + j];
			switch(mo[i][j]->whoami())
			{
				case COLUMN:
					c = 'c';
					break;
				case WALL:
					c = '0' + mo[i][j]->getCT();
					break;
				case FIELD:
					switch(mo[i][j]->getCT())
					{
						case NOTHING:
							c = '_';
							break;
						case TREASURE:
							c = 't';
							break;
						case FALSE_TREASURE:
							c = 'f';
							break;
						case MINED_TREASURE:
							c = 'd';
							break;
						case MINE:
							c = 'm';
							break;
						case PIT:
							c = 'p';
							break;
						case WEB:
							c = 'w';
							break;
					}
					break;
			}
		}
	code[MAP_SIZE * MAP_SIZE] = '\n';
	code[MAP_SIZE * MAP_SIZE + 1] = '\0';
	return code;
}

void Map::transpose()
{
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = i + 1; j < MAP_SIZE; j++) 
		{
			MapObject* tmp = mo[i][j];
			mo[i][j] = mo[j][i];
			mo[j][i] = tmp;
			tmp = nullptr;
		}
}