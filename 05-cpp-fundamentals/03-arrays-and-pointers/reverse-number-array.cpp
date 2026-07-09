#include <iostream>

using namespace std;

int main() {
	int x[10];

	cout << "Ingrese 10 numeros:" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> x[i];
	}
	cout << "Los numeros inversamente puestos son:" << endl;
	for (int i = 9; i >= 0; i--) {
		cout << x[i] << "  ";
	}

	return 0;
}
