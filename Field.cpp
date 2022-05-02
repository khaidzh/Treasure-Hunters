Field::Field()
{
	is_discovered = false;
	is_player_here = false;	
	content = new Nothing();
}

Field::~Field()
{
	delete content;
}

Field::Field(int placed_item_ID)
{
	is_discovered = false;
	is_player_here = false;	
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