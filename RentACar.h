#pragma once
#include"ColeccionSucursal.h"
class RentACar{
private:
	ColeccionSucursal* sucursales;
	string nombre;
public:
	RentACar();
	RentACar(string nom, ColeccionSucursal* aux);
	void setNombre(string nom);
	string getNombre();
	void insertarSucursal(Sucursal* aux);
	void eliminarSucursal(string num);
	ColeccionSucursal* getSucurales();

	string toString();
};

