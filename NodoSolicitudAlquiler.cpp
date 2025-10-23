#include "NodoSolicitudAlquiler.h"
NodoSolicitudAlquiler::NodoSolicitudAlquiler() : obj(nullptr), sig(nullptr) {}
NodoSolicitudAlquiler::NodoSolicitudAlquiler(SolicitudAlquiler* aux) :obj(aux), sig(nullptr) {}
NodoSolicitudAlquiler::~NodoSolicitudAlquiler() {
	delete obj;
	obj = nullptr;
}
void NodoSolicitudAlquiler::setObj(SolicitudAlquiler* aux) { this->obj = aux; }
void NodoSolicitudAlquiler::setSig(NodoSolicitudAlquiler* aux) { this->sig = aux; }
SolicitudAlquiler* NodoSolicitudAlquiler::getObj() { return obj; }
NodoSolicitudAlquiler* NodoSolicitudAlquiler::getSig() { return sig; }

