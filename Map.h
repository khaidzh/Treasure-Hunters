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
	void discover();
	bool vision() const;
	virtual void setCT(int ct) = 0;
	virtual int getCT() const = 0;
	virtual bool isEmpty() const = 0;
	virtual int whoami() const = 0;
};

class Field : public MapObject
{
private:
	//content;
public:
	Field();
	virtual void setCT(int ct) override;
	virtual int getCT() const override;
	virtual bool isEmpty() const override;
	virtual int whoami() const override;
};

class Wall : public MapObject
{
private:
	int type;
public:
	Wall();
	virtual void setCT(int ct) override;
	virtual int getCT() const override;
	virtual bool isEmpty() const override;
	virtual int whoami() const override;
	//void damage();
};

class Column : public MapObject
{
public:
	Column();
	virtual void setCT(int ct) override;
	virtual int getCT() const override;
	virtual bool isEmpty() const override;
	virtual int whoami() const override;
};

class Map
{
private:
public:
	MapObject* mo[MAP_SIZE][MAP_SIZE];

	Map();
	//Map(Player&, mo[][]);
	~Map();

	Field* getField(int i, int j);
	Wall* getWall(int i, int j);
	// Wall* topWall(int i, int j);
	// Wall* bottomWall(int i, int j);
	// Wall* leftWall(int i, int j);
	// Wall* rightWall(int i, int j);

	//isCorrect();
	//void draw();
};


