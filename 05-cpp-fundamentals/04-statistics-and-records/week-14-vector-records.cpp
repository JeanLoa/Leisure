#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <tuple>

using namespace std;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int randnum(int min, int max) {
	return min + rand() % (max - min + 1);
}

char randchar() {
	int num = rand() % 2;
	switch (num) {
	case 0: return 'S';
	case 1: return 'N';
	}
}

void GeneraryListaParalelos(vector<char>& Vgripe, vector<char>& Vtos, vector<int>& Vpesos) {
	cout << "Entonces los valores generados fueron:\n";
	for (int i = 0; i < Vgripe.size(); ++i) {
		Vgripe[i] = randchar();
		Vtos[i] = randchar();
		Vpesos[i] = randnum(1, 20);

		cout << "\n\nAlumno " << i + 1;
		cout << "\nGripe: " << Vgripe[i];
		cout << "\nTos: " << Vtos[i];
		cout << "\nPeso: " << Vpesos[i];
	}
}

void Porcentaje_gripe_tos(const vector<char>& Vgripe, const vector<char>& Vtos) {
	double enfermos_simultaneos = 0;
	int totalpersonas = Vgripe.size();
	for (int i = 0; i < Vgripe.size(); ++i) {
		if (Vgripe[i] == 'S' && Vtos[i] == 'S') {
			enfermos_simultaneos++;
		}
	}
	enfermos_simultaneos =  enfermos_simultaneos * 100 / totalpersonas;
	cout << "\nEl porcentaje de enfermos simultaneos es: " << enfermos_simultaneos << "%";
}

void Promedio_pesos_enfermos(const vector<char>& Vgripe, const vector<char>& Vtos, const vector<int>& Vpesos) {
	double promedio_enf = 0;
	int total_enfermos = 0;

	for (int i = 0; i < Vpesos.size(); ++i) {
		if (Vtos[i] == 'S' || Vgripe[i] == 'S') {
			promedio_enf += Vpesos[i];
			total_enfermos++;
		}
	}

	if (total_enfermos > 0) {
		promedio_enf /= total_enfermos;
		cout << "\nEl promedio de los pesos de las personas enfermas es: " << promedio_enf << " kg";
	}
	else {
		cout << "\nNo hay personas enfermas en el grupo.";
	}
}

void Listado_ordenado(vector<int> Vpesos, vector<char> Vgripe, vector<char> Vtos) {
	vector<tuple<int, char, char>> alumnos;
	for (int i = 0; i < Vgripe.size(); ++i) {
		alumnos.push_back(make_tuple(Vpesos[i], Vgripe[i], Vtos[i]));
	}
	sort(alumnos.rbegin(), alumnos.rend());
	for (int i = 0; i < Vgripe.size(); ++i) {
		Vpesos[i] = get<0>(alumnos[i]);
		Vgripe[i] = get<1>(alumnos[i]);
		Vtos[i] = get<2>(alumnos[i]);
		cout << "\nAlumnos " << i + 1 << ":";
		cout << "\nGripe:" << Vgripe[i];
		cout << "\nTos:" << Vtos[i];
		cout << "\nPeso:" << Vpesos[i];
	}
}

int main() {
	srand(time(0));
	int n;
	vector<char> Vgripe, Vtos;
	vector<int> Vpesos;
	do {
		cout << "Ingrese numero de alumnos: ";
		cin >> n;
		system("cls");
	} while (n > 20 || n < 0);

	Vgripe.resize(n); Vtos.resize(n); Vpesos.resize(n);
	GeneraryListaParalelos(Vgripe, Vtos, Vpesos);
	cout << "\n\nResultados:\n\n";
	Porcentaje_gripe_tos(Vgripe, Vtos);
	Promedio_pesos_enfermos(Vgripe, Vtos, Vpesos);
	Listado_ordenado(Vpesos, Vtos, Vgripe);

	return 0;
}
