#pragma once
#include"NodoSucursal.h"
class ColeccionSucursal{
private:
	NodoSucursal* inicio;
	NodoSucursal* actual;
public:
	ColeccionSucursal();
	~ColeccionSucursal();
	void insertarSucursal(Sucursal* aux);
	void eliminarSucursal(string num);
	bool buscarSucursal(string num);
	void intercambiarEntreSucursal(Vehiculo* vaux, Sucursal* saux);
	string toString();
};

