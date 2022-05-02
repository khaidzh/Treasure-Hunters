const char UP = 'w';
const char DOWN = 's';
const char LEFT = 'a';
const char RIGHT = 'd';

const int STEP = 2;

const int TOP_BORDER = 1;
const int BOTTOM_BORDER = 9;
const int LEFT_BORDER = 1;
const int RIGHT_BORDER = 9;

class Player
{
private:
	Map* map;
	int i;
	int j;
	int hp;
	int armor;
	//Item* item[N_ITEM]
public:
	Player(Map* map, int i, int j); //Map& map
	~Player();
	int check(bool& code);
	bool move(int direction);

	//use(int n);
};