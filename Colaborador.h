#pragma once
#include<iostream>
#include"Fecha.h"
using namespace std;
class Colaborador{
private:
	string id, nombre;
	Fecha* fechaIngreso;
public:
	Colaborador();
	Colaborador(string id, string nom, string fecha);
	~Colaborador();
	void setNombre(string nom);
	void setId(string id);
	void setFechaIngreso(string fecha);
	string getNombre();
	string getId();
	string getFechaIngreso();
	string toString();
};

