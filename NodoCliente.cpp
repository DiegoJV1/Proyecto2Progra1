#include "NodoCliente.h"
NodoCliente::NodoCliente(): obj(nullptr), sig(nullptr) {}
NodoCliente::NodoCliente(Cliente* aux):obj(aux), sig(nullptr) {}
NodoCliente::~NodoCliente() {
	delete obj;
	obj = nullptr;
	delete sig;
	sig = nullptr;
}
void NodoCliente::setObj(Cliente* aux) { this->obj = aux; }
void NodoCliente::setSig(NodoCliente* aux) { this->sig = aux; }
Cliente* NodoCliente::getObj() { return obj; }
NodoCliente* NodoCliente::getSig() { return sig; }
