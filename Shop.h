const int EDITTING = 0;
const int SHOPPING = 1;

class Custom
{
private:
	int money;
	int mode;
	bool first;
	int inventory[9]; //(ID, number)
public:
	Custom(Map* map);
	~Custom();

	action(const int& c);
	bool purchase(int price);
};