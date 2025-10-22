#pragma once
#include"SolicitudAlquiler.h"
class NodoSolicitudAlquiler{
private:
	SolicitudAlquiler* obj;
	NodoSolicitudAlquiler* sig;
public:
	NodoSolicitudAlquiler();
	NodoSolicitudAlquiler(SolicitudAlquiler* aux);
	~NodoSolicitudAlquiler();
	void setObj(SolicitudAlquiler* aux);
	void setSig(NodoSolicitudAlquiler* aux);
	SolicitudAlquiler* getObj();
	NodoSolicitudAlquiler* getSig();
};

