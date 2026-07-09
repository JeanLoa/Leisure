#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

const int largo = 11;
const int ancho = 19;

char mapa[largo][ancho] = {
    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    {2, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2},
    {2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 2},
    {2, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2},
    {2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 2},
    {2, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2},
    {2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 2},
    {2, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2},
    {2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 2},
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2},
    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void resetColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
}

void board1(char mapa[largo][ancho]) {
    char block = 219;
    for (int i = 0; i < largo; ++i) {
        gotoxy(0, i);
        for (int j = 0; j < ancho; ++j) {
            if (mapa[i][j] == 0) {
                cout << " ";
            }
            else if (mapa[i][j] == 1) {
                setColor(7, 5);
                cout << block;
                resetColor();
            }
            else if (mapa[i][j] == 2) {
                setColor(7, 2);
                cout << block;
                resetColor();
            }
            else if (mapa[i][j] == 3) {
                setColor(7, 6);
                cout << block;
                resetColor();
            }
        }
    }
}

void player(int x, int y) {
    char player = '*';
    gotoxy(x, y);
    setColor(2, 5);
    cout << player;
    resetColor();
}

void deleteplayer(int x, int y) {
    gotoxy(x, y);
    cout << " ";
}

void moveplayer(int& x, int& y) {
    char input = toupper(_getch());
    switch (input) {
    case 'W': if (y > 0 && (mapa[y - 1][x] == 0 || mapa[y - 1][x] == 3)) --y; break;
    case 'A': if (x > 0 && (mapa[y][x - 1] == 0 || mapa[y][x - 1] == 3)) --x; break;
    case 'S': if (y < largo - 1 && (mapa[y + 1][x] == 0 || mapa[y + 1][x] == 3)) ++y; break;
    case 'D': if (x < ancho - 1 && (mapa[y][x + 1] == 0 || mapa[y][x + 1] == 3)) ++x; break;
    }
}

bool vic(int x, int y) {
    return mapa[y][x] == 3;
}

int main() {
    int x = 1, y = 1;
    bool victory = false;

    while (!victory) {
        int prevx = x, prevy = y;
        board1(mapa);
        player(x, y);
        moveplayer(x, y);
        deleteplayer(prevx, prevy);
        victory = vic(x, y);
    }
    system("cls");
    cout << "¡Victoria!" << endl;
    return 0;
}
