void Item::purchase()
{
	//money -= cost;
}

bool PlacedItem::vision()
{
	return visionable;
}

int Nothing::getID() const
{
	return NOTHING;
}

int Treasure::getID() const
{
	return TREASURE;
}

int FalseTreasure::getID() const
{
	return FALSE_TREASURE;
}

int MinedTreasure::getID() const
{
	return MINED_TREASURE;
}

int Mine::getID() const
{
	return MINE;
}

int Pit::getID() const
{
	return PIT;
}

int Web::getID() const
{
	return WEB;
}