#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <iostream>
using namespace std; 
int getch( )
{
	struct termios oldt, newt;
	int ch;
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
}
// int main()
// {	
// 	cout << getch() << " ";	
// 	return 0;
// }
