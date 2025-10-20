#pragma once
#include"Colaborador.h"
class NodoColaborador{
private:
	Colaborador* obj;
	NodoColaborador* sig;
public:
	NodoColaborador();
	NodoColaborador(Colaborador* aux);
	~NodoColaborador();
	void setObj(Colaborador* aux);
	void setSig(NodoColaborador* aux);
	Colaborador* getObj();
	NodoColaborador* getSig();
};

