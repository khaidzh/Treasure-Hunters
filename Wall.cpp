Wall::Wall()
{
	is_discovered = false;
	type = EMPTY;
}

Wall::Wall(int type) : type(type)
{
	is_discovered = false;
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

bool Wall::damage(int damage)
{
	if (isEmpty())
		return false;
	type -= damage;
	if (type < 0)
		type = 0;
	return true;
}