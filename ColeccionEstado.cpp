#include "ColeccionEstado.h"
#include<sstream>
ColeccionEstado::ColeccionEstado() : inicio(nullptr), actual(nullptr) {}
ColeccionEstado::~ColeccionEstado() {
	while (inicio) {
		actual = inicio;
		inicio = inicio->getSig();
		delete actual;
	}
}
void ColeccionEstado::insertarEstado(string aux) {
	NodoEstado* nuevo = new NodoEstado(aux);
	if (!inicio) { inicio = nuevo; }
	else {
		actual = inicio;
		while (actual->getSig()) {
			actual = actual->getSig();
		}
		actual->setSig(nuevo);
	}
}
string ColeccionEstado::toString() {
	stringstream ss;
	ss << "Lista de Clientes: " << endl;
	actual = inicio;
	int i = 0;
	while (actual) {
		ss << "Cliente #" << i << ":" << endl;
		ss << actual->getObj() << endl;
		actual = actual->getSig();
		i++;
	}
	return ss.str();
}
