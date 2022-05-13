Field::Field()
{
	is_discovered = false;
	is_player_here = false;	
	is_marker_here = false;	
	content = new Nothing;
}

Field::~Field()
{
	delete content;
}

Field::Field(int placed_item_ID)
{
	Field();
	setCT(placed_item_ID);
}

void Field::setCT(int ct)
{
	delete content;
	switch(ct)
	{
		case TREASURE:
			content = new Treasure;
			break;
		case FALSE_TREASURE:
			content = new FalseTreasure;
			break;
		case MINED_TREASURE:
			content = new MinedTreasure;
			break;
		case MINE:
			content = new Mine;
			break;
		case PIT:
			content = new Pit;
			break;
		case WEB:
			content = new Web;
			break;
		default:
			content = new Nothing;
			break;
	}
}

int Field::getCT() const
{
	return content->getID();
}

bool Field::isEmpty() const
{
	return 0;
}

int Field::whoami() const
{
	return FIELD;
}

bool Field::activate(GameVisual* gv, int i, int j)
{
	if (content->getID() == MINE)
	{
		gv->animation(i, j);
 		delete content;
		content = new Nothing;
		//content->discover();
		return true;
	}
	return false;
}

void Field::activatedBy(Player* player)
{
	player->getGV()->animation(player->getPosition().first, player->getPosition().second);
	switch(content->getID())
	{
		case MINE:
			player->takeDamage(MINE_DAMAGE);

 			delete content;
			content = new Nothing;
			break;
		case WEB:
			player->addMove(4);

 			delete content;
			content = new Nothing;
			break;
		case PIT:
			player->takeDamage(PIT_DAMAGE);
			player->addMove(3);

 			delete content;
			content = new Nothing;
			break;
	}
}

// PlacedItem* Field::getContent()
// {
// 	return content;
// }
