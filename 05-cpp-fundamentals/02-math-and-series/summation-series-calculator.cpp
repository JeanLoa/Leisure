#include <iostream>
#include <cmath>

int main() {
    int m, n, D = 1;
    double suma = 0.0;

    // Solicitar valores para m y n
    std::cout << "Ingresa el número de términos (2 < m < 10): ";
    std::cin >> m;
    while (2 >= m || m >= 10) {
        std::cout << "Ingrese el numero de terminos adecuado (2 < m < 10): "<< std::endl;
        std::cin >> m;
    }

    std::cout << "Ingresa el valor de la constante n (2 < n < 50): ";
    std::cin >> n;
    while (2 >= n || n >= 50) {
        std::cout << "Ingrese el valor de n adecuado (2 < n < 50): " << std::endl;
        std::cin >> n;
    }
    // Verificar si los valores están dentro de los rangos permitidos
    if (m >= 2 && m < 10 && n >= 2 && n < 50) {
        for (int i = 1; i <= m; ++i) {
            if (i == 1)
            {
                suma += (pow(2, i) * (n + i));
                D = 2;
            }
            else {
                suma += (pow(2, i) * (n + i)) / D;
                D += 2;
            }
        }

        std::cout << "La suma de los " << m << " términos de la serie es: " << suma << std::endl;
    }
    else {
        std::cout << "Los valores ingresados no cumplen con los rangos permitidos." << std::endl;
    }

    return 0;
}
