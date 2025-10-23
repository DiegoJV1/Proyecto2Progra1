#include "ColeccionPlantel.h"
#include<sstream>
ColeccionPlantel::ColeccionPlantel() : inicio(nullptr), actual(nullptr) {}
ColeccionPlantel::~ColeccionPlantel() {
	while (inicio) {
		actual = inicio;
		inicio = inicio->getSig();
		delete actual->getObj();
		delete actual;
	}
}
void ColeccionPlantel::insertarPlantel(Plantel* aux) {
	if (buscarPlantel(aux->getIdentificacion()) == true) { return; }
	else {
		NodoPlantel* nuevo = new NodoPlantel(aux);
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
void ColeccionPlantel::eliminarPlantel(string iden) {
	if (buscarPlantel(iden) == true) {
		if (inicio->getObj()->getIdentificacion() == iden) {
			actual = inicio;
			inicio = inicio->getSig();
			delete actual->getObj();
			delete actual;
		}
		else {
			actual = inicio->getSig();
			NodoPlantel* anterior = inicio;
			while (actual) {
				if (actual->getObj()->getIdentificacion() == iden) {
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
bool ColeccionPlantel::buscarPlantel(string iden) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getIdentificacion() == iden) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}
Plantel* ColeccionPlantel::getPlantel(string iden) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getIdentificacion() == iden) {
			return actual->getObj();
		}
		actual = actual->getSig();
	}
	return nullptr;
}
Plantel* ColeccionPlantel::buscarPlantelPorVehiculo(string placa) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->buscarVehiculo(placa) == true) {
			return actual->getObj();
		}
		actual = actual->getSig();
	}
}
string ColeccionPlantel::plantelRecomendado() {
	if (inicio) {
		Plantel* mayor = inicio->getObj();
		actual = inicio->getSig();
		while (actual) {
			if (mayor->espaciosLibres() < actual->getObj()->espaciosLibres()) {
				mayor = actual->getObj();
			}
			actual = actual->getSig();
		}
		return mayor->getIdentificacion();
	}
}
string ColeccionPlantel::toString() {
	stringstream ss;
	ss << "Lista de Planteles: " << endl;
	actual = inicio;
	int i = 0;
	while (actual) {
		ss << "Plantel #" << i << ":" << endl;
		ss << actual->getObj()->toString() << endl;
		actual = actual->getSig();
		i++;
	}
	return ss.str();
}
