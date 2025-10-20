#pragma once
#include"NodoColaborador.h"
class ColeccionColaborador{
private:
	NodoColaborador* inicio;
	NodoColaborador* actual;
public:
	ColeccionColaborador();
	~ColeccionColaborador();
	void insertarColaborador(Colaborador* aux);
	void eliminarColaborador(string id);
	bool buscarColaborador(string id);
	string toString();
};

