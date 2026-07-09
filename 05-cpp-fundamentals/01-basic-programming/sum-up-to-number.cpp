#include <iostream>

using namespace std;

int main() {
	int numero;
	int suma = 0;
	int contador = 1;

	cout << "Ingrese un numero: ";
	cin >> numero;

	while (numero <= 0) {
			cout << "Por favor, ingrese un numero positivo: ";
			cin >> numero;
	}

	while (contador <= numero) {
			suma += contador;
			contador++;
	}

	cout << "La suma de todos los numeros positivos menores a " << numero << " es " << suma;

	return 0;
}
