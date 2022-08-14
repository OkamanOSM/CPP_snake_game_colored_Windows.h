#include <iostream>
#include <Windows.h>
using namespace std;

int widht = 90; int height = 25; 

//NOTE: our color function is in the while loop.

char sahne [25][90];
char keyboard[256];
const char character = 219; //the character snake will be written in

void getxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
} // WIndows.h function, you can copy it

void kursorutemizle() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out,&cursorInfo);

}// A function that cleans cursor. Again taken from Windows.h library

void keyboards(char s[]) {
	for (int x = 0; x < 256; x++) {
		s[x] = (char)(GetAsyncKeyState(x) >> 8);
}
} // Windows.h function that scans if you cin any chracter. In the bottom of page, there is explanation how it works




void getin0() {

	for (int i = 0; i < height; i++) {
		for (int e = 0; e < widht; e++) {
			sahne[i][e] = ' ';
		}
	}
} // filling sahne[][]sahne char with ' ' empty.

void write() {

	for (int i = 0; i < height; i++) {
		for (int e = 0; e < widht; e++) {
			getxy(e, i);
			cout << sahne[i][e];
		}
	}
}  // writing the sahne[][] char by using getxy (special windows function)

void border() {
	for (int e = 0; e < widht; e++) {
		sahne[0][e] = character;
	}
	for (int v = 0; v < widht; v++) {
		sahne [height -1][v] = character;
	}
	for (int w = 0; w < height; w++) {
		sahne[w][0] = character;
	}
	for (int f = 0; f < height; f++) {
		sahne[f][widht-1] =   character;
	}
} // borders





//everything is okey until here, now it's  getting harder to understand. please constrantrate here


const int maxlenght = 15;   // MAX SNAKE LENGHT
int snakelenght = 0; // current snake lenght


// we're going to have a database in struct
enum direction {
	rightx= 1,
	leftx  = 2,
	upx = 3,
	downx = 4 
}; // enum class for the directions

struct snake {
	int x;
	int y;
	direction DIRECTION;
	
 }; // data base

snake snaketail [maxlenght]; // enum class

void establishsnake() {
	snakelenght = 1;
	snaketail[0].x = 20;
	snaketail[0].y = 10;
	snaketail[0].DIRECTION = rightx;
} // establishing of head, every change will be here and others will follow that guy

void showsnake() {



	for (int i = 0; i < snakelenght; i++)
	{
		int x = snaketail[i].x;
		int y = snaketail[i].y;
		sahne[y][x] = character;
	}


} // showing up snake


void sddsnaketail ()
{
	if (snakelenght == maxlenght )
		return; // max lenght


	int x = snaketail[snakelenght - 1].x;
	int y = snaketail[snakelenght - 1].y;
	direction directionx = snaketail[snakelenght - 1].DIRECTION;

	switch (snaketail[snakelenght - 1].DIRECTION)
	{
	case rightx:
		x--;
		break;
	case leftx:
		x++;
		break;
	case downx:
		y--;
		break;
	case upx:
		y++;
		break;
	}

	snaketail[snakelenght].x = x;
	snaketail[snakelenght].y = y;
	snaketail[snakelenght].DIRECTION= directionx;
	snakelenght++;
} // adding a new tail which follows the next (until the head)

void runsnake() {


	for (int i = 0; i < snakelenght; i++) {

		switch (snaketail[i].DIRECTION) {

		case rightx:
		snaketail[i].x++;
			break;

		case leftx:
			snaketail[i].x--;
			break;

		case upx:

			snaketail[i].y++;
			break;
		case downx:
			snaketail[i].y--;
			break;


	 
		}

	}
	for (int i = snakelenght - 1; i > 0; i--) {
		snaketail[i].DIRECTION = snaketail[i - 1].DIRECTION;
	}// the previous follows the next

}
void keyboardcontorl() {


	keyboards(keyboard);

	if (keyboard['A'] != 0)
	{
		snaketail[0].DIRECTION = leftx;
	}
	if (keyboard['D'] != 0)
	{
		snaketail[0].DIRECTION = rightx;
	}
	if (keyboard['W'] != 0)
	{
		snaketail[0].DIRECTION = downx;
	}
	if (keyboard['S'] != 0)
	{
		snaketail[0].DIRECTION = upx;
	}
	if (keyboard['P'] != 0)
	{
		sddsnaketail();
	}
} 

int main() {

	kursorutemizle();

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 5); // color is here 
	
	establishsnake();

	while (true) {
		getin0(); // deletin all data in sahne[][] (filling up with ' ' empty characters)
		border();// adding the borders again

		keyboardcontorl(); // the head is changed,
		runsnake(); // the others and head is located while others also follows the priority numb's future change
		showsnake(); // showing
		write(); // showing
		Sleep(50);
	}

}

/*
for (int i = 0; i < widht; i++) {

		getxy(i, 0);
		cout << "a";
		Sleep(10);
	}

	for (int i = 0; i < height; i++) {

		getxy(widht -1,i);
		cout << "a";
		Sleep(10);

	}

	for (int i = widht -1; i >=0; i--) {

		getxy(  i, height -1);
		cout << "a";
		Sleep(10);
	}

	for (int i = height  - 1; i >= 0 ; i--) {

		getxy(0, i);
		cout << "a";
		Sleep(10);
	} */  // this is the longer version of borders, if you haven't understood the border func, you can also check this out 
          // while you learn getxy() function.
