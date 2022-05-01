Player::Player(Map* map, int i, int j) : map(map), i(i), j(j)
{
	hp = 3;
	map->getField(i, j)->is_player_here = true;
}

Player::~Player()
{
	map = nullptr;
}

bool Player::move(int direction)
{
	map->getField(i, j)->is_player_here = false;
	switch(direction)
	{
		case UP:
			if (i == TOP_BORDER)
				break;
			else
				i -= STEP;
			break;
		case DOWN:
			if (i == BOTTOM_BORDER)
				break;
			else
				i += STEP;
			break;
		case LEFT:
			if (j == LEFT_BORDER)
				break;
			else
				j -= STEP;
			break;
		case RIGHT:
			if (j == RIGHT_BORDER)
				break;
			else
				j += STEP;
			break;
	}
	map->getField(i, j)->is_player_here = true;
	return true;
}