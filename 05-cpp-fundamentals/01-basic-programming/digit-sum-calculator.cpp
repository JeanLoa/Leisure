#include <iostream>

using namespace std;

int main() {
    long long int num, suma = 0;

    cout << "Ingrese un numero:" << endl;
    cin >> num;

    // Verificar si el número ingresado es positivo
    while (num <= 0) {
        cout << "Por favor, ingrese un numero entero positivo:" << endl;
        cin >> num;
    }

    // Sumar los dígitos del número
    while (num > 0) {
        suma += num % 10;
        num /= 10;
    }

    cout << "La suma de los digitos es: " << suma << endl;

    return 0;
}
