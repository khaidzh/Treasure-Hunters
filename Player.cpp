Player::Player(Map* map, int i, int j) : map(map), i(i), j(j)
{
	hp = 3;
	armor = 0;
	money = 10;
	map->getField(i, j)->is_player_here = true;
	map->getField(i, j)->discover();
	map->getWall(i - 1, j)->discover();
	map->getWall(i + 1, j)->discover();
	map->getWall(i, j - 1)->discover();
	map->getWall(i, j + 1)->discover();
}

Player::~Player()
{
	map = nullptr;
}

int Player::check(bool& code)
{
	code = true;
	return code;
}

bool Player::move(int direction)
{
	bool code;
	map->getField(i, j)->is_player_here = false;
	switch(direction)
	{
		case UP:
			if (code = map->getWall(i - 1, j)->isEmpty())
				(i == TOP_BORDER) ? check(code) : (i -= STEP);
			break;
		case DOWN:
			if (code = map->getWall(i + 1, j)->isEmpty())
				(i == BOTTOM_BORDER) ? check(code) : (i += STEP);
			break;
		case LEFT:
			if (code = map->getWall(i, j - 1)->isEmpty())
				(j == LEFT_BORDER) ? check(code) : (j -= STEP);
			break;
		case RIGHT:
			if (code = map->getWall(i, j + 1)->isEmpty())
				(j == RIGHT_BORDER) ? check(code) : (j += STEP);
			break;
	}
	map->getField(i, j)->is_player_here = true;
	map->getField(i, j)->discover();
	map->getWall(i - 1, j)->discover();
	map->getWall(i + 1, j)->discover();
	map->getWall(i, j - 1)->discover();
	map->getWall(i, j + 1)->discover();
	return code;
}