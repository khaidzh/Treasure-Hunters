Custom::Custom(Map* map) : map(map)
{
	money = 10;
	mode = EDITTING;
	first = false;
	i = 1;
	j = 1;
	map->mo[1][1]->is_marker_here = true;
	for (int i = 0; i < 9; i++)
		inventory[i] = 0;
}

~Custom()
{
	map = nullptr;
}

bool purchase(int price)
{
	if (price > money)
		return false;
	money -= price;
	return true;
}

bool return_money();

bool Custom::take(const int& c)
{
	if (c == -1)
	{
		inventory[c] -=
	}
	if (!purchase(price[c]))
		return false;
	inventory[c] += (c == 0) ? 3 : 1;
	
}