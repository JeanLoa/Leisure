#include <iostream>

using namespace std;

int randnum(int min, int max) {
	return min + rand() % (max - min + 1);
}

void GenerarDatos(int* datos, int n) {
	cout << "Los datos del arreglo son:\n";
	for (int i = 0; i < n; ++i) {
		datos[i] = randnum(1, 9);
		cout << datos[i] << " ";
	}
}

void VerificarPatron(int* datos, int n) {
	int patron;
	cout << "\n";
	do {
		cout << "Ingrese el patron: ";
		cin >> patron;
	} while (patron <= 99 || patron >= 1000);
	
	int contador = 0;
	
	int digito1 = patron / 100;
	int digito2 = patron / 10 % 10;
	int digito3 = patron % 10;

	for (int i = 0; i < n; ++i) {
		if (datos[i] == digito1 && datos[i + 1] == digito2 && datos[i + 2] == digito3) {
			contador++;
		}
	}
	cout << "\nEl patron " << patron << " se repite " << contador << " veces";
}

int main() {
	srand(time(0));
	int n;
	do {
		cout << "Ingrese el tamano del arreglo: ";
		cin >> n;
		system("cls");
	} while (n >= 30 || n <= 0);
	int* arreglo = new int[n];
	GenerarDatos(arreglo, n);
	VerificarPatron(arreglo, n);
	return 0;
}
