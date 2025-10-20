#include "NodoVehiculo.h"
NodoVehiculo::NodoVehiculo() : obj(nullptr), sig(nullptr) {}
NodoVehiculo::NodoVehiculo(Vehiculo* aux) :obj(aux), sig(nullptr) {}
NodoVehiculo::~NodoVehiculo() {
	delete obj;
	obj = nullptr;
	delete sig;
	sig = nullptr;
}
void NodoVehiculo::setObj(Vehiculo* aux) { this->obj = aux; }
void NodoVehiculo::setSig(NodoVehiculo* aux) { this->sig = aux; }
Vehiculo* NodoVehiculo::getObj() { return obj; }
NodoVehiculo* NodoVehiculo::getSig() { return sig; }
