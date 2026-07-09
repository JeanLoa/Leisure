// Numero Aleatorios para datos de estudiante

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <iomanip>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Estudiantes {
    string* nombre;
    int* nota;
    int* grado;
};

int numaleatorio(int min, int max) {
    return min + rand() % max - min + 1;
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

void generareimprimirDatos(Estudiantes estudiante, int n) {
    for (int i = 0; i < n; ++i) {
        estudiante.nota[i] = numaleatorio(1, 20);
        estudiante.grado[i] = numaleatorio(1, 5);
        estudiante.nombre[i] = nombrealeatorio();
        gotoxy(0, 0); cout << "Estudiante:"; gotoxy(20, 0); cout << "Notas:"; gotoxy(40, 0); cout << "Grado:";
        gotoxy(0, i + 1);
        cout << setw(3) << i + 1 << ": ";
        cout << setw(3) << estudiante.nombre[i];
        gotoxy(20, i + 1);
        cout << setw(3) << i + 1 << ": ";
        cout << setw(3) << estudiante.nota[i];
        gotoxy(40, i + 1);
        cout << setw(3) << i + 1 << ": ";
        cout << setw(3) << estudiante.grado[i];
    }
}

void MayoraMenor(Estudiantes estudiante, int n) {
    sort(estudiante.nota, estudiante.nota + n, greater<int>());
    sort(estudiante.grado, estudiante.grado + n, greater<int>());
    cout << "\nNotas de estudiantes de mayor a menor:\n";
    for (int i = 0; i < n; ++i) {
        cout << estudiante.nota[i] << " ";
    }
    cout << "\nGrado de estudiantes de menor a mayor:\n";
    for (int i = 0; i < n; ++i) {
        cout << estudiante.grado[i] << " ";
    }
}

void MenoraMayor(Estudiantes estudiante, int n) {
    sort(estudiante.nota, estudiante.nota + n);
    sort(estudiante.grado, estudiante.grado + n);
    cout << "\nNotas de estudiantes de menor a mayor:\n";
    for (int i = 0; i < n; ++i) {
        cout << estudiante.nota[i] << " ";
    }
    cout << "\nGrados de estudiantes de menor a mayor:\n";
    for (int i = 0; i < n; ++i) {
        cout << estudiante.grado[i] << " ";
    }
}

void Promedio(Estudiantes estudiante, int n) {
    double promedionotas = 0;
    double promediogrado = 0;
    for (int i = 0; i < n; ++i) {
        promedionotas += estudiante.nota[i];
        promediogrado += estudiante.grado[i];
    }
    promedionotas = promedionotas / n;
    promediogrado = promediogrado / n;
    cout << "\nEl promedio de notas es: " << promedionotas;
    cout << "\nEl promedio de grado es: " << promediogrado;
}

void Moda(Estudiantes estudiante, int n) {
    unordered_map<int, int> contador_notas, contador_grado;
    for (int i = 0; i < n; ++i) {
        contador_notas[estudiante.nota[i]]++;
        contador_grado[estudiante.grado[i]]++;
    }
    int Modas[2] = { 0 };
    int Frecuencias[2] = { 0 };
    for (auto& num : contador_notas) {
        if (Frecuencias[0] < num.second) {
            Modas[0] = num.first;
            Frecuencias[0] = num.second;
        }
    }
    for (auto& num : contador_grado) {
        if (Frecuencias[1] < num.second) {
            Modas[1] = num.first;
            Frecuencias[1] = num.second;
        }
    }
    cout << "\nLa moda de las notas es: " << Modas[0] << " con frecuencia " << Frecuencias[0];
    cout << "\nLa moda de los grados es: " << Modas[1] << " con frecuencia " << Frecuencias[1];
}
void Maximo(Estudiantes estudiante, int n) {
    int max[2] = { INT_MIN };
    for (int i = 0; i < n; ++i) {
        if (max[0] < estudiante.nota[i]) {
            max[0] = estudiante.nota[i];
        }
        if (max[1] < estudiante.grado[i]) {
            max[1] = estudiante.grado[i];
        }
    }
    cout << "\nLa maxima nota es: " << max[0];
    cout << "\nEl maximo grado es: " << max[1];
}

void Minimo(Estudiantes estudiante, int n) {
    int min[2] = { INT_MAX };
    for (int i = 0; i < n; ++i) {
        if (min[0] > estudiante.nota[i]) {
            min[0] = estudiante.nota[i];
        }
        if (min[1] > estudiante.grado[i]) {
            min[1] = estudiante.grado[i];
        }
    }
    cout << "\nLa minima nota es: " << min[0];
    cout << "\nEl minimo grado es: " << min[1];
}

void MinimaLetras(const Estudiantes& estudiante, int n) {
    unordered_map<string, int> contador;

    for (int i = 0; i < n; ++i) {
        contador[estudiante.nombre[i]] = estudiante.nombre[i].length();
    }

    string minNombre;
    int minLetras = INT_MAX; 

    for (const auto& pair : contador) {
        if (pair.second < minLetras) {
            minLetras = pair.second;
            minNombre = pair.first;
        }
    }

    cout << "\nEl nombre con menos letras es: " << minNombre << " con " << minLetras << " letras";
}

void MaximoLetras(const Estudiantes& estudiante, int n) {
    unordered_map<string, int> contador;

    for (int i = 0; i < n; ++i) {
        contador[estudiante.nombre[i]] = estudiante.nombre[i].length();
    }

    string maxNombre;
    int maxLetras = INT_MIN;

    for (const auto& pair : contador) {
        if (pair.second > maxLetras) {
            maxNombre = pair.first;
            maxLetras = pair.second;
        }
    }
    cout << "\nEl nombre con mas letras es: " << maxNombre << " con " << maxLetras << " letras";
}


int main() {
    Estudiantes estudiante;
    int n;
    do {
        cout << "Ingrese la cantidad de estudiantes: ";
        cin >> n;
        system("cls");
    } while (n > 100 || n < 0);
    estudiante.nota = new int[n];
    estudiante.grado = new int[n];
    estudiante.nombre = new string[n];
    generareimprimirDatos(estudiante, n);
    MenoraMayor(estudiante, n);
    MayoraMenor(estudiante, n);
    Promedio(estudiante, n);
    Moda(estudiante, n);
    Maximo(estudiante, n);
    Minimo(estudiante, n);
    MaximoLetras(estudiante, n);
    MinimaLetras(estudiante, n);

    delete[] estudiante.nombre;
    delete[] estudiante.nota;
    delete[] estudiante.grado;

    return 0;
}
