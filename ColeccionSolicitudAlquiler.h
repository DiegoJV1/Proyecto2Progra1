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
	SolicitudAlquiler* buscarSolicitud(string cod);
	bool esSolicitud(string cod);

	void cambiarAContrato(string cod);
	string toString();
};

