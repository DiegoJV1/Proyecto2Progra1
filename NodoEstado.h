#pragma once
#include<iostream>
using namespace std;
class NodoEstado{
private:
	Empleado* e;
	string fechaCambio;
	string obj;
	NodoEstado* sig;
public:
	NodoEstado();
	NodoEstado(string aux, Empleado* aux, string fecha);
	~NodoEstado();
	void setObj(string aux);
	void setSig(NodoEstado* aux);
	string getObj();
	NodoEstado* getSig();
};

