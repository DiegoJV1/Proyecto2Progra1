#pragma once
#include<iostream>
#include"ColeccionSolicitudAlquiler.h"
using namespace std;
class Cliente{
protected:
	string id, nombre, residencia;
	ColeccionSolicitudAlquiler* solicitudes;
public:
	Cliente();
	Cliente(string id, string nom, string resi);

	virtual ~Cliente();
	void setId(string id);
	void setNombre(string nom);
	void setResidencia(string resi);
	void insertarSolicitud(SolicitudAlquiler* aux);

	string getId();
	string getNombre();
	string getResidencia();
	ColeccionSolicitudAlquiler* getHistorialAlquiler();

	virtual string toString();
};

