Map::Map()
{
	//empty
}

Map::Map(int code)
{
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			if (i % 2 == 1 && j % 2 == 1)
				mo[i][j] = new Field;
			else if (i % 2 == 1 || j % 2 == 1)
				mo[i][j] = new Wall;
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
				//mo[i][j]->setCT(CORRUPTED_WOOD_WALL);
				break;
			case '2':
				mo[i][j] = new Wall(WOOD_WALL);
				//mo[i][j]->setCT(WOOD_WALL);
				break;
			case '3':
				mo[i][j] = new Wall(CORRUPTED_IRON_WALL);
				//mo[i][j]->setCT(CORRUPTED_IRON_WALL);
				break;
			case '4':
				mo[i][j] = new Wall(IRON_WALL);
				//mo[i][j]->setCT(IRON_WALL);
				break;
			case ' ':
				mo[i][j] = new Field();
				//mo[i][j]->setCT();
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
				//mo[i][j]->setCT();
				break;
			case 'd':
				mo[i][j] = new Field(MINED_TREASURE);
				//mo[i][j]->setCT();
				break;
			case 'm':
				mo[i][j] = new Field(MINE);
				//mo[i][j]->setCT();
				break;
			case 'p':
				mo[i][j] = new Field(PIT);
				//mo[i][j]->setCT();
				break;
			case 'w':
				mo[i][j] = new Field(WEB);
				//mo[i][j]->setCT();
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

/*
c4c4c4c4c4c
0 0t0f0d0m4
c2c2c2c2c0c
4 0 0 0w0p4
c0c2c2c2c2c
4 0 0 2 0 4
c2c2c0c0c0c
4 0 2 0 2 4
c0c2c2c2c0c
4 0 0 0 0 4
c4c4c4c4c4c
*/

/*
const char* Map::encode()
{
	char code[MAP_SIZE * MAP_SIZE + 1]
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
		{
			char& c = code[i * MAP_SIZE + j];
			switch(mo[i][j]->whoami())
			{
				case COLUMN:
					c = 'c';
					break;
				case 
			}
		}
	code[MAP_SIZE * MAP_SIZE] = '\n';
	return code;
}
*/


/*
Wall* Map::topWall(int i, int j)
{
	return &wall[i * 2][j];
}
Wall* Map::bottomWall(int i, int j)
{
	return &wall[i * 2 + 2][j];
}
Wall* Map::leftWall(int i, int j)
{
	return &wall[i * 2 + 1][j];
}
Wall* Map::rightWall(int i, int j)
{
	return &wall[i * 2 + 1][j + 1];
}
*/


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

//template<typename T>
//void std::swap(T& a, T& b);