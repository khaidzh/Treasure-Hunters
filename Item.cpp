bool PlacedItem::vision()
{
	return visionable;
}

Nothing::Nothing()
{
	visionable = true;
}

int Nothing::getID() const
{
	return NOTHING;
}

Treasure::Treasure()
{
	visionable = true;
}

int Treasure::getID() const
{
	return TREASURE;
}

FalseTreasure::FalseTreasure()
{
	visionable = true;
}

int FalseTreasure::getID() const
{
	return FALSE_TREASURE;
}

MinedTreasure::MinedTreasure()
{
	visionable = true;
}

int MinedTreasure::getID() const
{
	return MINED_TREASURE;
}

Mine::Mine()
{
	visionable = false;
}

int Mine::getID() const
{
	return MINE;
}

Pit::Pit()
{
	visionable = false;
}

int Pit::getID() const
{
	return PIT;
}

Web::Web()
{
	visionable = false;
}

int Web::getID() const
{
	return WEB;
}