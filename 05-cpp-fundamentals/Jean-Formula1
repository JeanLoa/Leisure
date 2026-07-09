#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int factorial(int x) {
	int factorial = 1;
	for (int i = 1; i <= x; ++i) {
		factorial *= i;
	}
	return factorial;
}

double formula(int i, int a, int b, int x) {
	int resultado;
	if (i % 2 != 0) {
		resultado = pow(-1, i) * pow(a + i, b) / (b + factorial(x));
		return resultado;
	}
	else {
		resultado = pow(-1, i) * pow(b - i, a) / (b + factorial(x));
		return resultado;
	}
}

int main() {
	float i, a, b, x = 1;
	double sumatotal = 0.0;
	cout << "Ingrese el valor de i:" << endl;
	cin >> i;
	cout << "Ingrese el valor de a:" << endl;
	cin >> a;
	while (a > 4 && a < 2) {
		cout << "Ingrese un valor entre el rango para a:";
		cin >> a;
	}
	cout << "Ingrese el valor de b:" << endl;
	cin >> b;
	while (b > 4 && b < 2) {
		cout << "Ingrese un valor entre el rango para b:";
		cin >> b;
	}
	for (int j = 1; j <= i; ++j) {
		sumatotal += formula(j, a, b, x);
		cout << "En el termino " << j << " el valor es: " << sumatotal << endl << _getch();
		++x;
		for (int k = 0; k < 100; k += 7) {
			if (x > k) {
				x = 1;
			}
		}
	}
	cout << "La suma total es: " << sumatotal;

	return 0;
}
