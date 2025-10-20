#include "RentACar.h"
#include<sstream>
RentACar::RentACar() : nombre(""), sucursales(nullptr) {}
RentACar::RentACar(string nom, ColeccionSucursal* aux) : nombre(nom), sucursales(aux) {}
void RentACar::setNombre(string nom) { this->nombre = nom; }
string RentACar::getNombre() { return nombre; }
void RentACar::insertarSucursal(Sucursal* aux) {
	if (!sucursales) {
		sucursales = new ColeccionSucursal();
		sucursales->insertarSucursal(aux);
	}
	else {
		sucursales->insertarSucursal(aux);
	}
}
void RentACar::eliminarSucursal(string num) {
	if (sucursales) {
		sucursales->eliminarSucursal(num);
	}
	else {
		return;
	}
}

string RentACar::toString() {
	stringstream ss;
	ss << "----RentACar----" << endl;
	ss << "Nombre: " << nombre << endl;
	if (sucursales) {
		ss << "Detalle de Sucursales: " << endl;
		ss << sucursales->toString() << endl;
		ss << "-----------------------------------------" << endl;
	}
	else {
		ss << "Detalle de Sucursales: nulo" << endl;
		ss << "-----------------------------------------" << endl;
	}
	return ss.str();
}
