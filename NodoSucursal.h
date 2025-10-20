#pragma once
#include"Sucursal.h"
class NodoSucursal{
private:
	Sucursal* obj;
	NodoSucursal* sig;
public:
	NodoSucursal();
	NodoSucursal(Sucursal* aux);
	~NodoSucursal();
	void setObj(Sucursal* aux);
	void setSig(NodoSucursal* aux);
	Sucursal* getObj();
	NodoSucursal* getSig();
};

