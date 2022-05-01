Wall::Wall()
{
	is_discovered = false;
	type = EMPTY;
}

void Wall::setCT(int ct)
{
	type = ct;
}

int Wall::getCT() const
{
	return type;
}

bool Wall::isEmpty() const
{
	return (type == EMPTY);
}

int Wall::whoami() const
{
	return WALL;
}