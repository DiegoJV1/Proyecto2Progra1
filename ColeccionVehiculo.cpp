#include "ColeccionVehiculo.h"
#include<sstream>
ColeccionVehiculo::ColeccionVehiculo() : inicio(nullptr), actual(nullptr) {}
ColeccionVehiculo::~ColeccionVehiculo() {
	while (inicio) {
		actual = inicio;
		inicio = inicio->getSig();
		delete actual->getObj();
		delete actual;
	}
}
void ColeccionVehiculo::insertarVehiculo(Vehiculo* aux) {
	if (buscarVehiculo(aux->getPlaca()) == true) { return; }
	else {
		NodoVehiculo* nuevo = new NodoVehiculo(aux);
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
void ColeccionVehiculo::eliminarVehiculo(string placa) {
	if (buscarVehiculo(placa) == true) {
		if (inicio->getObj()->getPlaca() == placa && inicio->getObj()->getEstado()!="Alquilado") {
			actual = inicio;
			inicio = inicio->getSig();
			delete actual->getObj();
			delete actual;
		}
		else {
			actual = inicio->getSig();
			NodoVehiculo* anterior = inicio;
			while (actual) {
				if (actual->getObj()->getPlaca() == placa && actual->getObj()->getEstado() != "Alquilado") {
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
bool ColeccionVehiculo::buscarVehiculo(string placa) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getPlaca() == placa) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}
Vehiculo* ColeccionVehiculo::getVehiculo(string placa) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getPlaca() == placa) {
			return actual->getObj();
		}
		actual = actual->getSig();
	}
	return nullptr;
}
string ColeccionVehiculo::toString() {
	stringstream ss;
	ss << "Lista de Vehiculos: " << endl;
	actual = inicio;
	int i = 0;
	while (actual) {
		ss << "Vehiculo #" << i << ":" << endl;
		ss << actual->getObj()->toString() << endl;
		actual = actual->getSig();
		i++;
	}
	return ss.str();
}
