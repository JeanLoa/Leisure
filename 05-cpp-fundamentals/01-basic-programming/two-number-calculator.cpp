#include <iostream>

using namespace std;

int main() {
	int num1, num2;
	char operacion;

	cout << "Ingrese 2 numeros: " << endl;
	cin >> num1 >> num2;

	cout << "Seleccione la operacion a realizar: " << endl;
	cout << "1. Suma" << endl;
	cout << "2. Resta" << endl;
	cout << "3. Multiplicacion" << endl;
	cout << "4. Division" << endl;
	cin >> operacion;

	switch (operacion) {
	case '1':
		cout << "La suma es: " << num1 + num2 << endl;
		break;
	case '2':
		cout << "La resta es: " << num1 - num2 << endl;
		break;
	case '3':
		cout << "La multiplicacion es: " << num1 * num2 << endl;
		break;
	case '4':
		if (num2 != 0) { cout << "La division es: " << num1 / num2 << endl; }
		else { cout << "No se puede dividir por cero" << endl; }
		break;
	default: cout << "Opcion Invalida. Seleccione entre las opciones, por favor.";
	}
	return 0;
}
