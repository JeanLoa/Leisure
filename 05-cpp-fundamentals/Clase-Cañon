#include <iostream>
#include <conio.h> // Para getch()
#include <windows.h>

using namespace std;

const int screenHeight = 20; // Altura del disparo
const char cannonChar = '^'; // Carácter del cañón
const char bulletChar = '*'; // Carácter de la bala

int cannonX = 10; // Posición inicial del cañón
int bulletX, bulletY; // Posición de la bala

void gotoxy(int x, int y) {
    cout << "\033[" << y << ";" << x << "H"; // Mueve el cursor a la posición (x, y)
}

void drawCannon() {
    gotoxy(cannonX, screenHeight);
    cout << cannonChar;
}

void drawBullet() {
    gotoxy(bulletX, bulletY);
    cout << bulletChar;// cout << "Ball subiendo ";
}

void clearBullet() {
    gotoxy(bulletX, bulletY);
    cout << ' '; //cout << "Ball borrado ";
}

int main() {
    char key; //recibe pulsacion del teclado
    bool bulletActive = false;
    int velocidad = 10;//i=1;

    while (true) {
        if (_kbhit()) {//verifica si hay una tecla presionada en el búfer del teclado
            key = _getch();
            if (key == ' ') {
                if (!bulletActive) {
                    bulletActive = true;
                    bulletX = cannonX;
                    bulletY = screenHeight - 1;
                }
            }
            else if (key == 'a') {
                cannonX--; // Mover el cañón a la izquierda
            }
            else if (key == 'd') {
                cannonX++; // Mover el cañón a la derecha
            }
        }

        if (bulletActive) {
            //cout << "Ball activa ";

            bulletY--;

            if (bulletY <= 0) {
                bulletActive = false;
            }
            else {
                drawBullet();
                Sleep(velocidad);
                clearBullet();
            }
        }

        drawCannon();//cout<<i++;
        Sleep(velocidad);

    }

    return 0;
}
