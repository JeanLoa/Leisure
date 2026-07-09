#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Pelota(int x, int y) {
    gotoxy(x, y);
    cout << "*";
}

void Arco(int x, int y) {
    gotoxy(x, y);
    cout << "______"; gotoxy(x, ++y);
    cout << "|    |"; gotoxy(x, ++y);
    cout << "|    |"; gotoxy(x, ++y);
    cout << "|    |"; gotoxy(x, ++y);
    cout << "|    |"; gotoxy(x, ++y);
}

void Muñeco(int x, int y) {
    gotoxy(x, y);
    cout << " O"; gotoxy(x, ++y);
    cout << "/|\\"; gotoxy(x, ++y);
    cout << "/ \\";
}

void borrar_Pel(int x, int y) {
    gotoxy(x, y);
    cout << " ";
}

void Borrar_Heroe(int x, int y) {
    gotoxy(x, y);
    cout << "  "; gotoxy(x, ++y);
    cout << "   "; gotoxy(x, ++y);
    cout << "   ";
}

void MoverHeroe(int& x, int& y) {
    char input = _getch();
    switch (input) {
    case 'w': --y; break;
    case 'a': --x; break;
    case 's': ++y; break;
    case 'd': ++x; break;
    }
}
void Goal() {
    system("cls");
    gotoxy(50, 30);
    cout << "¡¡¡GOOOOOOOLLLLLL!!!" << endl;
}

int main() {
    int x = 9;
    int y = 8;
    int prev_x, prev_y;

    int pelx = 15;
    int pely = 10;

    int arcx = 100;
    int arcy = 7;

    bool goal = false;

    while (!goal) {
        Muñeco(x, y);
        prev_x = x;
        prev_y = y;

        Pelota(pelx, pely);
        if (pelx == x - 1 && pely == y + 2) {
            borrar_Pel(pelx, pely);
            Pelota(pelx -= 1, pely);
        }
        if (pelx == x + 3 && pely == y + 2) {
            borrar_Pel(pelx, pely);
            Pelota(pelx += 1, pely);
        }
        if (pelx == x + 1 && pely == y) {
            borrar_Pel(pelx, pely);
            Pelota(pelx, pely -= 1);
        }
        if (pelx == x + 1 && pely == y + 2) {
            borrar_Pel(pelx, pely);
            Pelota(pelx, pely += 1);
        }

        Arco(arcx, arcy);
        MoverHeroe(x, y);
        Borrar_Heroe(prev_x, prev_y);
        Muñeco(x, y);
        if (x >= 110 || x <= 2) {
            x = 10;
        }
        if (y >= 20 || y <= 2) {
            y = 5;
        }
        if (pelx >= 100 && pelx <= 105 && pely >= 7 && pely <= 11) {
            goal = true;
            Goal();
        }
    }
    system("pause");
    return 0;
}
