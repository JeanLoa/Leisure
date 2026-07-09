#include <iostream>

using namespace std;

int main() {
	int num;
	int factorial = 1;

	cout << "Ingrese un numero positivo:" << endl;
	cin >> num;

	while (num < 0) {
		cout << "Por favor, ingrese un numero entero positivo:" << endl;
		cin >> num;
	}
	for (int i = 1; i <= num; ++i) {
		factorial *= i;
	}

	cout << "El factorial de " << num << " es " << factorial << endl;
	return 0;
}
