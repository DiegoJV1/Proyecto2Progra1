#include "Cliente.h"
#include<sstream>
Cliente::Cliente(): id(""), nombre(""), residencia("") {}
Cliente::~Cliente() {}
Cliente::Cliente(string id, string nom, string resi): id(id), nombre(nom), residencia(resi) {}
void Cliente::setId(string id) { this->id = id; }
void Cliente::setNombre(string nom) { this->nombre = nom; }
void Cliente::setResidencia(string resi) { this->residencia = resi; }
string Cliente::getId() { return id; }
string Cliente::getNombre() { return nombre; }
string Cliente::getResidencia() { return residencia; }
string Cliente::toString() {
	stringstream ss;
	ss << "Nombre: " << nombre << endl;
	ss << "Id: " << id << endl;
	ss << "Lugar de Residencia: " << residencia << endl;
	return ss.str();
}
//