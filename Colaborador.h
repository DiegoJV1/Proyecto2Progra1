#pragma once
#include<iostream>
#include"Fecha.h"
#include"ColeccionSolicitudAlquiler.h"
using namespace std;
class Colaborador{
private:
	string id, nombre;
	Fecha* fechaIngreso;
	ColeccionSolicitudAlquiler* trabajos;
public:
	Colaborador();
	Colaborador(string id, string nom, Fecha* fecha);
	~Colaborador();
	void setNombre(string nom);
	void setId(string id);
	void setFechaIngreso(Fecha* fecha);
	void insertarTrabajo(SolicitudAlquiler* aux);
	string getNombre();
	string getId();
	Fecha* getFechaIngreso();
	ColeccionSolicitudAlquiler* getHistorialTrabajos();
	string toString();
};

