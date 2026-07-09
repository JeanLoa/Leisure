#include <iostream>
#include <conio.h>
#include <vector>
#include <cstdlib> // Para srand()
#include <ctime>  // Para time()
#include <algorithm> //Para usar la función find
using namespace std;

int main() {
    // Inicializar la semilla para el generador de números aleatorios
    //Esto asegura que los números generados sean diferentes cada vez
    // que ejecutamos el programa.
    srand(static_cast<unsigned int>(time(0)));
    //un operador de conversión, forzams que el valor sea tratado como un número entero sin signo.

    // Vector para almacenar los números generados
    //Ya que puede redimensionarse automáticamente para acomodar más elementos según sea necesario.
    //Es muy útil cuando no se conoce cuantos elementos que se van a almacenar.
    vector<int> numeros;
    
    // Generar números aleatorios y asegurarse de que sean únicos
    while (numeros.size() < 4) {
        int numero = rand() % 40 + 1; // Generar un número entre 1 y 40
        // Verificar si el número yaestá en la lista
        if (find(numeros.begin(), numeros.end(), numero) == numeros.end()) {
            numeros.push_back(numero);
        }
    }

    // Mostrar los números generados
    cout << "Números generados: ";
    for (int i : numeros) {
        cout << i << " ";
    }
    cout << endl;

    _getch();

    return 0;
}
