class Item
{
protected:
	int cost;
	int available_number;
public:
	void purchase();
};

class PlacedItem : Item
{
	//virtual activation() = 0;
};

class HandItem : Item
{
	//virtual usage() = 0;
};

class Treasure
{
public:
	Treasure();
	~Treasure();
	
};

class FalseTreasure
{
public:
	FalseTreasure();
	~FalseTreasure();
	
};

class MinedTreasure()
{

};

class Mine
{
public:
	Mine();
	~Mine();
	
};

class Pit
{
public:
	Pit();
	~Pit();
	
};

class IronWall
{
public:
	IronWall();
	~IronWall();
	
};

class Web
{
public:
	Web();
	~Web();
	
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

