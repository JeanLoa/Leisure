#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>

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

void setColor(int textColor, int bgColor) {
    int colorAttribute = bgColor << 4 | textColor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorAttribute);
}

void resetColor() {
    setColor(7, 0);
}

int randnum(int min, int max) {
    return min + rand() % (max - min + 1);
}

void imprimirMatriz(int** datos, int n, int m) {
    char block = 219;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (datos[i][j] == 1) {
                setColor(7, 15);
                cout << block;
            }
            else {
                setColor(0, 0);
                cout << " ";
            }
        }
        cout << endl;
    }
    resetColor();
}

void generarMatriz(int** datos, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            datos[i][j] = (randnum(1, 5) == 1) ? 1 : 0;
        }
    }
}

void actualizarMatriz(int** datos, int n, int m) {
    int** nuevaMatriz = new int* [n];
    for (int i = 0; i < n; ++i) {
        nuevaMatriz[i] = new int[m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int vecinosVivos = 0;
            for (int k = -1; k <= 1; ++k) {
                for (int l = -1; l <= 1; ++l) {
                    if (k == 0 && l == 0) continue;
                    int ni = i + k;
                    int nj = j + l;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        vecinosVivos += datos[ni][nj];
                    }
                }
            }
            if (datos[i][j] == 1) {
                nuevaMatriz[i][j] = (vecinosVivos == 2 || vecinosVivos == 3) ? 1 : 0;
            }
            else {
                nuevaMatriz[i][j] = (vecinosVivos == 3) ? 1 : 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            datos[i][j] = nuevaMatriz[i][j];
        }
        delete[] nuevaMatriz[i];
    }
    delete[] nuevaMatriz;
}

int main() {
    srand(time(0));
    HideCursor();
    int i = 0;
    int n, m;
    do {
        cout << "Ingrese el tamano del automata (largo): ";
        cin >> n;
        cout << "Ingrese el tamano del automata (ancho): ";
        cin >> m;
        system("cls");
    } while ((n > 30 || n <= 0) || (m > 30 || m <= 0));

    int** Automata = new int* [n];
    for (int i = 0; i < n; ++i) {
        Automata[i] = new int[m];
    }

    generarMatriz(Automata, n, m);

    while (i < 30) {
        system("cls");
        cout << "La matriz en la iteracion " << i + 1 << " luce:" << endl;
        imprimirMatriz(Automata, n, m);
        _getch();
        actualizarMatriz(Automata, n, m);
        ++i;
        Sleep(100);
    }
    if (i == 30) {
        system("cls");
        cout << "Las iteraciones han terminado" << endl;
        system("pause");
    }

    for (int i = 0; i < n; ++i) {
        delete[] Automata[i];
    }
    delete[] Automata;

    return 0;
}
