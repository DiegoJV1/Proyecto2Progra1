#include "NodoEstado.h"
NodoEstado::NodoEstado() : obj(""), sig(nullptr) {}
NodoEstado::NodoEstado(string aux) :obj(aux), sig(nullptr) {}
NodoEstado::~NodoEstado() {
	delete sig;
	sig = nullptr;
}
void NodoEstado::setObj(string aux) { this->obj = aux; }
void NodoEstado::setSig(NodoEstado* aux) { this->sig = aux; }
string NodoEstado::getObj() { return obj; }
NodoEstado* NodoEstado::getSig() { return sig; }
