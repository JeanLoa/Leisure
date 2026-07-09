#include <iostream>

using namespace std;

struct Nodo {
public:
	int dato;
	Nodo* siguiente;
	
	Nodo(int valor) : dato(valor), siguiente(nullptr) {}
	~Nodo() {}
};

struct ListaEnlazada {
private:
	Nodo* cabeza;
public:
	ListaEnlazada() : cabeza(nullptr) {}
	~ListaEnlazada() {
		Nodo* temp;
		while (cabeza) {
			temp = cabeza;
			cabeza = cabeza->siguiente;
			delete temp;
		}
	}
	void insertarInicio(int valor) {
		Nodo* nuevo = new Nodo(valor);
		nuevo->siguiente = cabeza;
		cabeza = nuevo;
	}
	void insertarFinal(int valor) {
		if (!cabeza) {
			cabeza = new Nodo(valor);
			return;
		}
		Nodo* temp = cabeza;
		while (temp->siguiente) {
			temp = temp->siguiente;
		}
		temp->siguiente = new Nodo(valor);
	}
	void eliminar(int valor) {
		if (!cabeza) return;
		if (cabeza->dato == valor) {
			Nodo* temp = cabeza;
			cabeza = cabeza->siguiente;
			delete temp;
			return;
		}
		Nodo* temp = cabeza;
		while (temp->siguiente && temp->siguiente->dato != valor) {
			temp = temp->siguiente;
		}
		if (temp->siguiente) {
			Nodo* eliminar = temp->siguiente;
			temp->siguiente = temp->siguiente->siguiente;
			delete eliminar;
		}
	}
	void mostrar() {
		Nodo* temp = cabeza;
		while (temp) {
			cout << temp->dato << " -> ";
			temp = temp->siguiente;
		}
		cout << "NULL" << endl;
	}
};
