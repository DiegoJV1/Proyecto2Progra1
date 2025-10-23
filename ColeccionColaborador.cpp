#include "ColeccionColaborador.h"
#include<sstream>
ColeccionColaborador::ColeccionColaborador() : inicio(nullptr), actual(nullptr) {}
ColeccionColaborador::~ColeccionColaborador() {
	while (inicio) {
		actual = inicio;
		inicio = inicio->getSig();
		delete actual->getObj();
		delete actual;
	}
}
void ColeccionColaborador::insertarColaborador(Colaborador* aux) {
	if (buscarColaborador(aux->getId()) == true) { return; }
	else {
		NodoColaborador* nuevo = new NodoColaborador(aux);
		if (!inicio) { inicio = nuevo; }
		else {
			actual = inicio;
			while (actual->getSig()) {
				actual = actual->getSig();
			}
			actual->setSig(nuevo);
		}
	}
}
void ColeccionColaborador::eliminarColaborador(string id) {
	if (buscarColaborador(id) == true) {
		if (inicio->getObj()->getId() == id) {
			actual = inicio;
			inicio = inicio->getSig();
			delete actual->getObj();
			delete actual;
		}
		else {
			actual = inicio->getSig();
			NodoColaborador* anterior = inicio;
			while (actual) {
				if (actual->getObj()->getId() == id) {
					anterior->setSig(actual->getSig());
					delete actual->getObj();
					delete actual;
				}
				anterior = actual;
				actual = actual->getSig();
			}
		}
	}
}
bool ColeccionColaborador::buscarColaborador(string id) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getId() == id) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}
Colaborador* ColeccionColaborador::getColaborador(string id) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getId() == id) {
			return actual->getObj();
		}
		actual = actual->getSig();
	}
	return nullptr;
}
string ColeccionColaborador::toString() {
	stringstream ss;
	ss << "Lista de Colaboradores: " << endl;
	actual = inicio;
	int i = 0;
	while (actual) {
		ss << "Colaborador #" << i << ":" << endl;
		ss << actual->getObj()->toString() << endl;
		actual = actual->getSig();
		i++;
	}
	return ss.str();
}
