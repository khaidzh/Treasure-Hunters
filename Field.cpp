Field::Field()
{
	is_discovered = false;
	is_player_here = false;	
	//content = NOTHING;
}

void Field::setCT(int ct)
{
	return;
}

int Field::getCT() const
{
	return 0;
}

bool Field::isEmpty() const
{
	return true;
}

int Field::whoami() const
{
	return FIELD;
}