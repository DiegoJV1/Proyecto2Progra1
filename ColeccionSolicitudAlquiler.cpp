#include "ColeccionSolicitudAlquiler.h"
#include<sstream>
ColeccionSolicitudAlquiler::ColeccionSolicitudAlquiler() : inicio(nullptr), actual(nullptr) {}
ColeccionSolicitudAlquiler::~ColeccionSolicitudAlquiler() {
	while (inicio) {
		actual = inicio;
		inicio = inicio->getSig();
		delete actual->getObj();
		delete actual;
	}
}
void ColeccionSolicitudAlquiler::insertarSolicitud(SolicitudAlquiler* aux) {
	if (buscarSolicitud(aux->getCodigo()) == true) { return; }
	else {
		NodoSolicitudAlquiler* nuevo = new NodoSolicitudAlquiler(aux);
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
bool ColeccionSolicitudAlquiler::buscarSolicitud(string cod) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getCodigo() == cod) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}
string ColeccionSolicitudAlquiler::toString() {
	stringstream ss;
	ss << "Lista de Contratos/Solicitudes de alquiler: " << endl;
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
