enum PlacedItemID
{
	NOTHING,
	TREASURE,
	FALSE_TREASURE,
	MINED_TREASURE,
	MINE,
	PIT,
	WEB
};

class Item
{
protected:
	int cost;
	//int available_number;
public:
	//Item();
	void purchase();
};

class PlacedItem : public Item
{
private:
	bool visionable;
public:
	bool vision();
	virtual int getID() const = 0;
	//virtual activation() = 0;
};

class HandItem : public Item
{
	//virtual usage() = 0;
};

class Nothing : public PlacedItem
{
public:
	//Nothing();
	//~Nothing();
	virtual int getID() const;
	
};

class Treasure : public PlacedItem
{
public:
	//Treasure();
	//~Treasure();
	virtual int getID() const;
	
};

class FalseTreasure : public PlacedItem
{
public:
	//FalseTreasure();
	//~FalseTreasure();
	virtual int getID() const;
	
};

class MinedTreasure : public PlacedItem
{
	//MinedTreasure();
	//~MinedTreasure();
	virtual int getID() const;

};

class Mine : public PlacedItem
{
public:
	//Mine();
	//~Mine();
	virtual int getID() const;
	
};

class Pit : public PlacedItem
{
public:
	//Pit();
	//~Pit();
	virtual int getID() const;
	
};

// class IronWall
// {
// public:
// 	IronWall();
// 	~IronWall();
// 	virtual getID() const;
	
// };

class Web : public PlacedItem
{
public:
	//Web();
	//~Web();
	virtual int getID() const;
	
};











class Boots
{
public:
	Boots();
	~Boots();
	
};

class Armor
{
public:
	Armor();
	~Armor();
	
};

class MetalDetector
{
public:
	MetalDetector();
	~MetalDetector();
	
};

