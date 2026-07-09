#include <iostream>

using namespace std;

int main() {
    int num;
    int i = 1;
    int suma = 0;

    cout << "Ingrese un numero: " << endl;
    cin >> num;

    // Validar que el número ingresado sea positivo
    while (num <= 0) {
        cout << "Por favor, ingrese un numero entero positivo: ";
        cin >> num;
    }

    // Calcular la suma de los primeros N números naturales
    while (i <= num) {
        suma += i;
        i++;
    }

    // Imprimir la suma calculada
    cout << "La suma de los primeros " << num << " numeros naturales es: " << suma << endl;

    return 0;
}
