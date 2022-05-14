const char UP = 'w';
const char DOWN = 's';
const char LEFT = 'a';
const char RIGHT = 'd';
const char PICKUP = 'e';

const int TOP_BORDER = 1;
const int BOTTOM_BORDER = 9;
const int LEFT_BORDER = 1;
const int RIGHT_BORDER = 9;

const int STEP = 2;
const int WIN_CODE = 1000;

class Player
{
private:
	Map* map;
	GameVisual* gv;
	int i;
	int j;
	int hp;
	int armor;
	int money;
	int number_of_moves;

	int treasure;
	int detector;
	bool isShod;
public:
	std::pair<int, int> inventory[6]; //(ID, number)
	Player(GameVisual* gv, int i, int j); //Map& map
	~Player();

	GameVisual* getGV();
	std::pair<int, int> getPosition() const;

	void addMove(int number = 1);
	void addArmor(int armor);
	void takeDamage(int damage);
	//void setEquipment();

	bool isAlive() const;
	bool isPlaying() const;

	int check(bool& code);
	int move(int direction, bool repeat = false);

	bool useItem(int n);
};