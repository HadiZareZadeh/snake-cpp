#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <ctime>

using namespace std;

const int height=20 , width=40;
int x=width/2,y=height/2,ans=0;
bool launching =true;
int dir = 3,fx,fy,food=0,num;

void map(){ 
	cout << string(width,'*') << endl;
	for (int j=0;j<height-2;++j)
		cout << '*' << string(width-2,' ')<<'*'<<endl;
	cout << string(width,'*') << endl;
}
void gotoxy(int x,int y){
	COORD pos;
	HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition( hConsole, pos );
	}
}
void foodplace() {
	srand((unsigned)time(NULL));
	fx = rand() % (width - 2) + 1;
	fy = rand() % (height - 2) + 1;
	gotoxy(fx, fy);
	cout << "$";
}
void message() {
	cout << "\n\tGame Over !!!\n\n\t" << endl;
	cout << "\tYour Score : " << food << endl;
}
void trying() {
	cout << "\t1 to exit\n\t0 to new game" << endl;
	cin >> ans;
	while (!(ans == 0 || ans == 1))
		cin >> ans;
	if (ans == 0) {
		launching = true;
		x = (width / 2);	//random
		y = (height / 2);	//random
		system("cls");
		food = 0;
	}
}
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void move(int dx, int dy) {
	x = x + dx;
	y = y + dy;

	if (x == fx && y == fy) {
		food++;
		foodplace();
	}
	if (x == 0 || x == (width - 1) || y == 0 || y == (height - 1)) {
		launching = false;
	}
	system("cls");
	map();
	gotoxy(fx, fy);
	cout << "$";
	gotoxy(x, y);
	cout << char(254);
}
void movement() {
	switch (dir){
	case 0: move(0, -1);
		break;
	case 1: move(1, 0);
		break;
	case 2: move(0, 1);
		break;
	case 3: move(-1, 0);
		break;
	}
	
}
void launch() {
	while (launching) {
		if (_kbhit()) {
			switch (_getch()) {
			case 's':
				if (dir != 0) dir = 2;
				break;
			case 'a':
				if (dir != 1) dir = 3;
				break;
			case 'w':
				if (dir != 2) dir = 0;
				break;
			case 'd':
				if (dir != 3) dir = 1;
				break;
			}
		}
		movement();
		Sleep(200);
	}
}
int main(){
	hidecursor();
	do{
	map();
	foodplace();
	gotoxy(x, y);
	cout << char(254);
	launch();
	system("cls");
	message();
	trying();
	}while(ans==0);
	return 0;
}