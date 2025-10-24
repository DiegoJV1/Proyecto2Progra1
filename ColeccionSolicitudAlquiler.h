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
	bool esMayorFecha(Fecha* f1, Fecha* f2);
	void ordenarSolicitudes();
	void cambiarAContrato(string cod);
	string toString();
};

