#include "NodoSucursal.h"
NodoSucursal::NodoSucursal() : obj(nullptr), sig(nullptr) {}
NodoSucursal::NodoSucursal(Sucursal* aux) :obj(aux), sig(nullptr) {}
NodoSucursal::~NodoSucursal() {
	delete obj;
	obj = nullptr;
	delete sig;
	sig = nullptr;
}
void NodoSucursal::setObj(Sucursal* aux) { this->obj = aux; }
void NodoSucursal::setSig(NodoSucursal* aux) { this->sig = aux; }
Sucursal* NodoSucursal::getObj() { return obj; }
NodoSucursal* NodoSucursal::getSig() { return sig; }

