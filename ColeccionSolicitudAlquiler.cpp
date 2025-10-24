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
		NodoSolicitudAlquiler* nuevo = new NodoSolicitudAlquiler(aux);
		if (!inicio) { 
			inicio = nuevo; 
			return;
		}
		else {
			actual = inicio;
			while (actual->getSig()) {
				if (actual->getObj()->getCodigo() == aux->getCodigo()) {
					cout << "ERROR: Ya existe la solicitud" << endl;
					return;
				}
				actual = actual->getSig();
			}
			actual->setSig(nuevo);
		}
}
bool ColeccionSolicitudAlquiler::esSolicitud(string cod) {
	if (!inicio) {
		cout << "ERROR: No existe la coleccion" << endl;
		return false;
	}
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getCodigo() == cod) {
			string estado = actual->getObj()->getEstado();
			if (estado == "aprobada" || estado == "pendiente" || estado == "rechazada" || estado == "anulada") {
				return true;
			}
			else {
				return false;
			}
		}
		actual = actual->getSig();
	}
}

SolicitudAlquiler* ColeccionSolicitudAlquiler::buscarSolicitud(string cod) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getCodigo() == cod) {
			return actual->getObj();
		}
		actual = actual->getSig();
	}
	return nullptr;
}
void ColeccionSolicitudAlquiler::cambiarAContrato(string cod) {
	if (inicio == nullptr)return;
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getCodigo() == cod) {
			if (actual->getObj()->getEstado() == "aprobada") {
				ContratoAlquiler* pasaAContrato = new ContratoAlquiler(actual->getObj()->getCodigo(), actual->getObj()->getIdCliente(), actual->getObj()->getIdColaborador(), actual->getObj()->getIdSucursal(), actual->getObj()->getPlaca(), actual->getObj()->getCanDias(), actual->getObj()->getInicio(), actual->getObj()->getEntrega(), actual->getObj()->getPrecioDia());
				delete actual->getObj();
				this->actual->setObj(pasaAContrato);
				
				return;
			}
			if (actual->getObj()->getEstado() != "aprobada") return;
		}
		actual = actual->getSig();
	}
	return;
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
bool esMenorFecha(Fecha* f1, Fecha* f2) {
	if (f1->getAnnio() != f2->getAnnio()) {
		return f1->getAnnio() < f2->getAnnio();
	}
	if (f1->getMes() != f2->getMes()) {
		return f1->getMes() < f2->getMes();
	}
	return f1->getDia() < f2->getDia();
}

void ColeccionSolicitudAlquiler::ordenarSolicitudes() {
	if (inicio == nullptr || inicio->getSig() == nullptr) return;

	NodoSolicitudAlquiler* nuevoInicio = nullptr;
	NodoSolicitudAlquiler* actual = inicio;

	while (actual) {
		NodoSolicitudAlquiler* siguiente = actual->getSig();

		// Puntero a la fecha del nodo actual
		Fecha* fechaActual = actual->getObj()->getInicio();

		// 1. Caso de Inserción: Lista nueva vacía, o 'actual' va antes del inicio de 'nuevoInicio'
		// CRÍTICO: Se debe verificar si nuevoInicio es NULL antes de acceder a sus miembros.
		if (!nuevoInicio || esMenorFecha(fechaActual, nuevoInicio->getObj()->getInicio())) {

			actual->setSig(nuevoInicio);
			nuevoInicio = actual;
		}

		// 2. Caso de Inserción: En medio o al final
		else {
			NodoSolicitudAlquiler* s = nuevoInicio;

			// Avanza 's' mientras el SIGUIENTE nodo (s->getSig()) sea menor o igual que 'actual'.
			while (s->getSig() && !esMenorFecha(fechaActual, s->getSig()->getObj()->getInicio())) {
				s = s->getSig();
			}

			// Re-enlaza 'actual'
			actual->setSig(s->getSig());
			s->setSig(actual);
		}

		actual = siguiente;
	}

	inicio = nuevoInicio;
}