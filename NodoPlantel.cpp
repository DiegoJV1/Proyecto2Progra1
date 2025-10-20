#include "NodoPlantel.h"
NodoPlantel::NodoPlantel() : obj(nullptr), sig(nullptr) {}
NodoPlantel::NodoPlantel(Plantel* aux) :obj(aux), sig(nullptr) {}
NodoPlantel::~NodoPlantel() {
	delete obj;
	obj = nullptr;
	delete sig;
	sig = nullptr;
}
void NodoPlantel::setObj(Plantel* aux) { this->obj = aux; }
void NodoPlantel::setSig(NodoPlantel* aux) { this->sig = aux; }
Plantel* NodoPlantel::getObj() { return obj; }
NodoPlantel* NodoPlantel::getSig() { return sig; }

