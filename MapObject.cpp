void MapObject::discover()
{
	is_discovered = true;
}

bool MapObject::vision() const
{
	return is_discovered;
}