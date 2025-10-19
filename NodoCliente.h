#pragma once
#include"Cliente.h"
class NodoCliente{
private:
	Cliente* obj;
	NodoCliente* sig;
public:
	NodoCliente();
	NodoCliente(Cliente* aux);
	~NodoCliente();
	void setObj(Cliente* aux);
	void setSig(NodoCliente* aux);
	Cliente* getObj();
	NodoCliente* getSig();
};

