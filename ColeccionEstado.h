#pragma once
#include"NodoEstado.h"
class ColeccionEstado{
private:
	NodoEstado* inicio;
	NodoEstado* actual;
public:
	ColeccionEstado();
	~ColeccionEstado();
	void insertarEstado(string aux);
	string toString();
};

