#pragma once
#include<iostream>
#include"Colaborador.h"
using namespace std;
class NodoEstado{
private:
	Colaborador* c;
	Fecha* fechaCambio;
	string obj;
	NodoEstado* sig;
public:
	NodoEstado();
	NodoEstado(string aux, Colaborador* c, Fecha* fecha);
	~NodoEstado();
	void setObj(string aux);
	void setSig(NodoEstado* aux);
	void setC(Colaborador* c);
	void setFechaCambio(Fecha* f);
	Colaborador* getC();
	Fecha* getFechaCambio();
	string getObj();
	NodoEstado* getSig();
	string toString();
};

