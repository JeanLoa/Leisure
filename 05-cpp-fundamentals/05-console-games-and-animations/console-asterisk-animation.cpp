#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void HideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void ast(int& x, int& y) {
	gotoxy(x, y);
	cout << "*";
}

void deleteast(int& x, int& y) {
	gotoxy(x, y);
	cout << " ";
}

int main() {
	char input = toupper(_getch());
	HideCursor();
	while (input == 'Q') {
		int x = 60, y = 15;
		for (int i = 0; i < 4; ++i) {
			int prevx = x, prevy = y;
			x++;
			ast(x, y);
			deleteast(prevx, prevy);
			Sleep(10);
		}
		for (int i = 0; i < 1; ++i) {
			int prevx = x, prevy = y;
			y--;
			ast(x, y);
			deleteast(prevx, prevy);
			Sleep(10);
		}
		for (int i = 0; i < 8; ++i) {
			int prevx = x, prevy = y;
			x--;
			ast(x, y);
			deleteast(prevx, prevy);
			Sleep(10);
		}
		for (int i = 0; i < 2; ++i) {
			int prevx = x, prevy = y;
			y++;
			ast(x, y);
			deleteast(prevx, prevy);
			Sleep(10);
		}
		for (int i = 0; i < 12; ++i) {
			int prevx = x, prevy = y;
			x++;
			ast(x, y);
			deleteast(prevx, prevy);
			Sleep(10);
		}
		for (int i = 0; i < 3; ++i) {
			int prevx = x, prevy = y;
			y--;
			ast(x, y);
			deleteast(prevx, prevy);
			Sleep(10);
		}
		for (int i = 0; i < 16; ++i) {
			int prevx = x, prevy = y;
			x--;
			ast(x, y);
			deleteast(prevx, prevy);
			Sleep(10);
		}
		for (int i = 0; i < 4; ++i) {
			int prevx = x, prevy = y;
			y++;
			ast(x, y);
			deleteast(prevx, prevy);
			Sleep(10);
		}
		for (int i = 0; i < 20; ++i) {
			int prevx = x, prevy = y;
			x++;
			ast(x, y);
			deleteast(prevx, prevy);
			Sleep(10);
		}
		for (int i = 0; i < 5; ++i) {
			int prevx = x, prevy = y;
			y--;
			ast(x, y);
			deleteast(prevx, prevy);
			Sleep(10);
		}
		for (int i = 0; i < 24; ++i) {
			int prevx = x, prevy = y;
			x--;
			ast(x, y);
			deleteast(prevx, prevy);
			Sleep(10);
		}
	}
	return 0;
}
