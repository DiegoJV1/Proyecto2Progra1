#pragma once
#include<iostream>
using namespace std;
class NodoEstado{
private:
	string obj;
	NodoEstado* sig;
public:
	NodoEstado();
	NodoEstado(string aux);
	~NodoEstado();
	void setObj(string aux);
	void setSig(NodoEstado* aux);
	string getObj();
	NodoEstado* getSig();
};

