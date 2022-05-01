Column::Column()
{
	is_discovered = true;
}

void Column::setCT(int ct)
{
	return;
}

int Column::getCT() const
{
	return 0;
}

bool Column::isEmpty() const
{
	return false	;
}


int Column::whoami() const
{
	return COLUMN;
}