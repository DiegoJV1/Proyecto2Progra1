#include "ColeccionSucursal.h"
#include<sstream>
ColeccionSucursal::ColeccionSucursal() : inicio(nullptr), actual(nullptr) {}
ColeccionSucursal::~ColeccionSucursal() {
	while (inicio) {
		actual = inicio;
		inicio = inicio->getSig();
		delete actual->getObj();
		delete actual;
	}
}
void ColeccionSucursal::insertarSucursal(Sucursal* aux) {
	if (buscarSucursal(aux->getNum()) == true) { return; }
	else {
		NodoSucursal* nuevo = new NodoSucursal(aux);
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
void ColeccionSucursal::eliminarSucursal(string num) {
	if (buscarSucursal(num) == true) {
		if (inicio->getObj()->getNum() == num) {
			actual = inicio;
			inicio = inicio->getSig();
			delete actual->getObj();
			delete actual;
		}
		else {
			actual = inicio->getSig();
			NodoSucursal* anterior = inicio;
			while (actual) {
				if (actual->getObj()->getNum() == num) {
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
bool ColeccionSucursal::buscarSucursal(string num) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getNum() == num) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}
Sucursal* ColeccionSucursal::getSucursal(string num) {
	actual = inicio;
	while (actual) {
		if (actual->getObj()->getNum() == num) {
			return actual->getObj();
		}
		actual = actual->getSig();
	}
	return nullptr;
}
void ColeccionSucursal::intercambiarEntreSucursal(Vehiculo* vaux, Sucursal* saux) {
	if (vaux->getEstado() != "Alquilado") {
		if (buscarSucursal(saux->getNum()) == true) {
			Sucursal* antigua = nullptr;
			while (actual) {
				if (actual->getObj()->getVehiculos()->buscarVehiculo(vaux->getPlaca()) == true) {
					antigua = actual->getObj();
					break;
				}
				actual = actual->getSig();
			}
			if (antigua) {
				saux->insertarVehiculo(vaux);
				antigua->getPlanteles()->buscarPlantelPorVehiculo(vaux->getPlaca())->buscarEstacionamientoPorVehiculo(vaux->getPlaca());
				antigua->eliminarVehiculo(vaux->getPlaca());
				
			}
			else { return; }

		}
	}
	else { return; }
}
string ColeccionSucursal::toString() {
	stringstream ss;
	ss << "Lista de Sucursales: " << endl;
	actual = inicio;
	int i = 0;
	while (actual) {
		ss << "sucursal #" << i << ":" << endl;
		ss << actual->getObj()->toString() << endl;
		actual = actual->getSig();
		i++;
	}
	return ss.str();
}
