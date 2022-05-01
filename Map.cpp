Map::Map()
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

/*
char* Map::encode()
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

Map::Map(char code[MAP_SIZE * MAP_SIZE + 1])
{
	
}




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
}*/