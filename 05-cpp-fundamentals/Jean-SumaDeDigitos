#include <iostream>

using namespace std;

int main() {
	int num, numdigit;
	int units;
	int tens;
	int hundreds;

	cout << "Ingrese un numero:" << endl;
	cin >> num;

	while (num <= 0) {
		cout << "Por favor, ingrese un numero entero positivo:" << endl;
		cin >> num;
	}

	units = num % 10;
	tens = ((num % 100) - units) / 10;
	hundreds = ((num - units) - (tens*10)) / 100;

	numdigit = units + tens + hundreds;

	cout << "La suma de los digitos de " << num << " es " << numdigit;

	return 0;
}
