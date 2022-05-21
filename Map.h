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
	bool is_marker_here;
	virtual bool vision() const;
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

	//virtual bool vision() const final;
	bool activate(GameVisual* gv, int i, int j);
	void activatedBy(Player* player);

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

	bool damage(int damage);

	virtual void setCT(int ct);
	virtual int getCT() const;
	virtual bool isEmpty() const;
	virtual int whoami() const;
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
	Map(const char code[MAP_SIZE * MAP_SIZE + 1]);

	~Map();

	char* encode() const;

	Field* getField(int i, int j);
	Wall* getWall(int i, int j);
	Column* getColumn(int i, int j);

	void discoverField(int i, int j);
	void destroyField(int& hp, int i, int j);

	//isCorrect();

	void transpose();
};


