#include "ColeccionCliente.h"
#include<sstream>
ColeccionCliente::ColeccionCliente() : inicio(nullptr), actual(nullptr) {}
ColeccionCliente::~ColeccionCliente() {
	while (inicio) {
		actual = inicio;
		inicio = inicio->getSig();
		delete actual->getObj();
		delete actual;
	}
}
void ColeccionCliente::insertarCliente(Cliente* aux) {
	if (buscarCliente(aux->getId()) == true) { return; }
	else {
		NodoCliente* nuevo = new NodoCliente(aux);
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
void ColeccionCliente::eliminarCliente(string id) {
	if (buscarCliente(id) == true) {
		if (inicio->getObj()->getId() == id) {
			actual = inicio;
			inicio = inicio->getSig();
			delete actual->getObj();
			delete actual;
		}
		else {
			actual = inicio->getSig();
			NodoCliente* anterior = inicio;
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
bool ColeccionCliente::buscarCliente(string id) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getId() == id) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}
Cliente* ColeccionCliente::getCliente(string id) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getId() == id) {
			return actual->getObj();
		}
		actual = actual->getSig();
	}
	return nullptr;
}
string ColeccionCliente::toString() {
	stringstream ss;
	ss << "Lista de Clientes: " << endl;
	actual = inicio;
	int i = 0;
	while (actual) {
		ss << "Cliente #" << i << ":" << endl;
		ss << actual->getObj()->toString() << endl;
		actual = actual->getSig();
		i++;
	}
	return ss.str();
}
