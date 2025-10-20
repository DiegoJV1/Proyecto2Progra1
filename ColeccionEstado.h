#pragma once
#include"NodoEstado.h"
class ColeccionEstado{
private:
	NodoEstado* inicio;
	NodoEstado* actual;
public:
	ColeccionEstado();
	~ColeccionEstado();
	void insertarEstado(string aux, Colaborador* c, Fecha* fecha);
	string getUltimo();
	string toString();
};

