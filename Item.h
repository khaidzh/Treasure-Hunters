enum ItemID
{
	NOTHING,
	TREASURE,
	FALSE_TREASURE,
	MINED_TREASURE,
	MINE,
	PIT,
	WEB
};

enum HandItemID
{
	CROSSBOW,
	BAIT,
	HAMMER,
	ROCKET,
	GRENADE,
	POTION
};

enum ItemDamage
{
	NULL_DAMAGE,
	PIT_DAMAGE,
	MINE_DAMAGE
};

// class Item
// {
// protected:
// 	int cost;
// 	//int available_number;
// public:
// 	//Item();
// 	//void purchase();
// };

class PlacedItem
{
protected:
	bool visionable;
	//int cost;
public:
	bool vision();
	void discover();
	virtual int getID() const = 0;
	//virtual void purchase() const = 0;
	//virtual activation() = 0;
};

class HandItem
{
	//virtual usage() = 0;
};

class Nothing : public PlacedItem
{
public:
	Nothing();
	//~Nothing();
	virtual int getID() const;
	
};

class Treasure : public PlacedItem
{
public:
	Treasure();
	//~Treasure();
	virtual int getID() const;
	
};

class FalseTreasure : public PlacedItem
{
public:
	FalseTreasure();
	//~FalseTreasure();
	virtual int getID() const;
	
};

class MinedTreasure : public PlacedItem
{
public:
	MinedTreasure();
	//~MinedTreasure();
	virtual int getID() const;

};

class Mine : public PlacedItem
{
public:
	Mine();
	//~Mine();
	virtual int getID() const;
	
};

class Pit : public PlacedItem
{
public:
	Pit();
	//~Pit();
	virtual int getID() const;
	
};

class Web : public PlacedItem
{
public:
	Web();
	//~Web();
	virtual int getID() const;
	
};