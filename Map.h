const int MAP_SIZE = 11;

enum WallType
{
	EMPTY,
	CORRUPTED_WOOD_WALL,
	WOOD_WALL,
	CORRUPTED_IRON_WALL,
	IRON_WALL
};

enum ObjectType
{
	FIELD,
	WALL,
	COLUMN
};

class MapObject
{
protected:
	bool is_discovered;
public:
	bool is_player_here;
	bool vision() const;
	void discover();
	virtual void setCT(int ct) = 0;
	virtual int getCT() const = 0;
	virtual bool isEmpty() const = 0;
	virtual int whoami() const = 0;
};

class Field : public MapObject
{
private:
	PlacedItem* content;
public:
	Field();
	Field(int placed_item_ID);
	~Field();
	virtual void setCT(int ct);
	virtual int getCT() const;
	virtual bool isEmpty() const;
	virtual int whoami() const;
};

class Wall : public MapObject
{
private:
	int type;
public:
	Wall();
	Wall(int type);
	virtual void setCT(int ct);
	virtual int getCT() const;
	virtual bool isEmpty() const;
	virtual int whoami() const;
	//void damage();
};

class Column : public MapObject
{
public:
	Column();
	virtual void setCT(int ct);
	virtual int getCT() const;
	virtual bool isEmpty() const;
	virtual int whoami() const;
};

class Map
{
private:
public:
	MapObject* mo[MAP_SIZE][MAP_SIZE];

	Map();
	Map(int code);
	Map(const char code[MAP_SIZE * MAP_SIZE + 1]);

	~Map();

	Field* getField(int i, int j);
	Wall* getWall(int i, int j);
	Column* getColumn(int i, int j);
	// Wall* topWall(int i, int j);
	// Wall* bottomWall(int i, int j);
	// Wall* leftWall(int i, int j);
	// Wall* rightWall(int i, int j);

	//isCorrect();
	//void draw();

	void transpose();
};


