#include <iostream>
using namespace std;

int main() {
	int num;
	int suma = 0;

	cout << "Ingrese un numero:" << endl;
	cin >> num;

	for (int i = 2; i <= num; i+=2) {
		suma += i;
	}
	cout << "La suma de los numeros pares hasta el numero " << num << " es " << suma;
	return 0;
}
