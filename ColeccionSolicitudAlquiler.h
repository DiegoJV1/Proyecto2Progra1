#pragma once
#include"NodoSolicitudAlquiler.h"
class ColeccionSolicitudAlquiler{
private:
	NodoSolicitudAlquiler* inicio;
	NodoSolicitudAlquiler* actual;
public:
	ColeccionSolicitudAlquiler();
	~ColeccionSolicitudAlquiler();
	void insertarSolicitud(SolicitudAlquiler* aux);
	bool buscarSolicitud(string cod);
	string toString();
};

