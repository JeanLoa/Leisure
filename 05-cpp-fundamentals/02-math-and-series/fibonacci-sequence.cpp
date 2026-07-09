#include <iostream>

int main() {
    int limite;
    int anterior = 0;
    int actual = 1;
    int siguiente;

    // Solicitar al usuario que ingrese el límite para la secuencia de Fibonacci
    std::cout << "Ingrese el límite para la secuencia de Fibonacci: ";
    std::cin >> limite;

    // Imprimir los primeros dos números de la secuencia
    std::cout << "Secuencia de Fibonacci hasta " << limite << ":\n";
    std::cout << anterior << " ";
    std::cout << actual << " ";

    // Generar y imprimir la secuencia de Fibonacci hasta el límite dado por el usuario
    while (actual + anterior <= limite) {
        siguiente = anterior + actual;
        std::cout << siguiente << " ";
        anterior = actual;
        actual = siguiente;
    }

    std::cout << std::endl;

    return 0;
}
