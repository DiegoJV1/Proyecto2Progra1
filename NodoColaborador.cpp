#include "NodoColaborador.h"
NodoColaborador::NodoColaborador() : obj(nullptr), sig(nullptr) {}
NodoColaborador::NodoColaborador(Colaborador* aux) :obj(aux), sig(nullptr) {}
NodoColaborador::~NodoColaborador() {
	delete obj;
	obj = nullptr;
	delete sig;
	sig = nullptr;
}
void NodoColaborador::setObj(Colaborador* aux) { this->obj = aux; }
void NodoColaborador::setSig(NodoColaborador* aux) { this->sig = aux; }
Colaborador* NodoColaborador::getObj() { return obj; }
NodoColaborador* NodoColaborador::getSig() { return sig; }

