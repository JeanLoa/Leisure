#include <iostream>

using namespace std;

int main() {

	int numero1, numero2;
	int suma = 0;

	cout << "Ingrese el primer numero entero: ";
	cin >> numero1;

	cout << "Ingrese el segundo numero entero: ";
	cin >> numero2;

	for (int i = numero1; i <= numero2; i++) {
		suma += i;
	}

	cout << "La suma de los numeros entre " << numero1 << " y " << numero2 << " es " << suma;

	return 0;
}
