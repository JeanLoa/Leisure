#include <iostream>
#include <windows.h>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Estudiante {
	string* nombre;
	int* grado;
	int* nota;
};

int numeroaleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

string nombrealeatorio() {
    int num = rand() % 20;
    string name;
    switch (num) {
    case 0: name = "Estefano"; break;
    case 1: name = "Alicia"; break;
    case 2: name = "Leopoldo"; break;
    case 3: name = "Leonardo"; break;
    case 4: name = "Rosa"; break;
    case 5: name = "Jorge"; break;
    case 6: name = "Alex"; break;
    case 7: name = "Felix"; break;
    case 8: name = "David"; break;
    case 9: name = "Jean"; break;
    case 10: name = "Juan"; break;
    case 11: name = "Luna"; break;
    case 12: name = "Cristal"; break;
    case 13: name = "Leon"; break;
    case 14: name = "Maria"; break;
    case 15: name = "Kylian"; break;
    case 16: name = "Cristiano"; break;
    case 17: name = "Messi"; break;
    case 18: name = "Upamecano"; break;
    case 19: name = "Antoine"; break;
    }
    return name;
}

void GenerarDatosEstudiante(Estudiante estudiante, int n) {
    gotoxy(0, 0); cout << "Nombre:"; gotoxy(20, 0); cout << "Grado:"; gotoxy(40, 0); cout << "Nota:";
    for (int i = 0; i < n; ++i) {
		estudiante.nombre[i] = nombrealeatorio();
        estudiante.grado[i] = numeroaleatorio(1, 5);
        estudiante.nota[i] = numeroaleatorio(1, 20);
        gotoxy(0, i + 1); cout << estudiante.nombre[i] << setw(3);
        gotoxy(20, i + 1); cout << estudiante.grado[i] << setw(3);
        gotoxy(40, i + 1); cout << estudiante.nota[i] << setw(3);
	}
}

void MayoraMenor(Estudiante estudiante, int n){
    sort(estudiante.nota, estudiante.nota + n, greater<int>());
    sort(estudiante.grado, estudiante.grado + n, greater<int>());
    cout << "\nLas notas de mayor a menor: ";
    for (int i = 0; i < n; ++i) {
        cout << estudiante.nota[i] << " ";
    }
    cout << "\nLos grados de mayor a menor: ";
    for (int i = 0; i < n; ++i) {
        cout << estudiante.grado[i] << " ";
    }
}

void MenoraMayor(Estudiante estudiante, int n) {
    sort(estudiante.nota, estudiante.nota + n);
    sort(estudiante.grado, estudiante.grado + n);
    cout << "\nLas notas de menor a mayor: ";
    for (int i = 0; i < n; ++i) {
        cout << estudiante.nota[i] << " ";
    }
    cout << "\nLos grados de menor a mayor: ";
    for (int i = 0; i < n; ++i) {
        cout << estudiante.grado[i] << " ";
    }
}

void Promedio(Estudiante estudiante, int n) {
    double promedio_notas = 0;
    double promedio_grado = 0;
    for (int i = 0; i < n; ++i) {
        promedio_notas += estudiante.nota[i];
        promedio_grado += estudiante.grado[i];
    }
    promedio_notas /= n;
    promedio_grado /= n;
    cout << "\nEl promedio de notas es: " << promedio_notas;
    cout << "\nEl promedio de grados es: " << promedio_grado;
}

void Moda(Estudiante estudiante, int n) {
    unordered_map<int, int> contador_g, contador_n;
    for (int i = 0; i < n; ++i) {
        contador_g[estudiante.grado[i]]++;
        contador_n[estudiante.nota[i]]++;
    }
    int moda_g = 0, frec_g = 0, moda_n = 0, frec_n = 0;
    for (auto pair : contador_g) {
        if (pair.second > frec_g) {
            frec_g = pair.second;
            moda_g = pair.first;
        }
    }
    for (auto pair : contador_n) {
        if (pair.second > frec_n) {
            frec_n = pair.second;
            moda_n = pair.first;
        }
    }
    cout << "\nLa moda de las notas es: " << moda_n << " con " << frec_n << " apariciones";
    cout << "\nLa moda de los grados es: " << moda_g << " con " << frec_g << " apariciones";
}

void Mediana(Estudiante estudiante, int n) {
    double mediana_n = 0, mediana_g = 0;
    vector<int> notas(estudiante.nota, estudiante.nota + n), grados(estudiante.grado, estudiante.grado + n);
    sort(notas.begin(), notas.end()); sort(grados.begin(), grados.end());
    if (n % 2 != 0) {
        mediana_n = notas[n / 2];
        mediana_g = grados[n / 2];
    }
    else if (n % 2 == 0){
        mediana_n = (notas[n / 2] + notas[(n / 2) - 1]) / 2;
        mediana_g = (grados[n / 2] + notas[(n / 2) - 1]) / 2;
    }
    else {
        cout << "\nLa mediana no existe";
    }
    cout << "La mediana de notas es: " << mediana_n;
    cout << "La mediana de grados es: " << mediana_g;
}

int main() {
    int n;
    Estudiante estudiante;
    do {
        cout << "Ingrese la cantidad de estudiantes: ";
        cin >> n;
        system("cls");
    } while (n > 100 || n < 0);
    estudiante.nombre = new string[n];
    estudiante.grado = new int[n];
    estudiante.nota = new int[n];
    GenerarDatosEstudiante(estudiante, n);
    MayoraMenor(estudiante, n);
    MenoraMayor(estudiante, n);
    Promedio(estudiante, n);
    Moda(estudiante, n);
    Mediana(estudiante, n);
	return 0;
}
