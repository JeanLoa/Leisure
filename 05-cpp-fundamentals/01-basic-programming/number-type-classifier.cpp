#include <iostream>

using namespace std;

int main() {
	int num;

	cout << "Ingrese un numero: ";
	cin >> num;

	if (num < 0) {
		cout << "El numero ingresado en negativo";
	}
	else if (num > 0) {
		cout << "El numero ingresado es positivo";
	}
	else cout << "El numero es cero";

	return 0;
}
