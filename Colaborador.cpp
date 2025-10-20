#include "Colaborador.h"
#include<sstream>
Colaborador::Colaborador(): id(""), nombre(""), fechaIngreso(nullptr) {}
Colaborador::Colaborador(string id, string nom, Fecha* fecha) : id(id), nombre(nom), fechaIngreso(fechaIngreso) {}
Colaborador::~Colaborador() {}
void Colaborador::setNombre(string nom) { this->nombre = nom; }
void Colaborador::setId(string id) { this->id = id; }
void Colaborador::setFechaIngreso(Fecha* fecha) { this->fechaIngreso = fecha; }
string Colaborador::getNombre() { return nombre; }
string Colaborador::getId() { return id; }
Fecha* Colaborador::getFechaIngreso() { return fechaIngreso; }
string Colaborador::toString() {
	stringstream ss;
	ss << "Nombre: " << nombre << endl;
	ss << "Id: " << id << endl;
	if (fechaIngreso) {
		ss << "Fecha de Ingreso: " << fechaIngreso->toString() << endl;
	}
	else {
		ss << "Fecha de Ingreso: nula " << endl;
	}
	return ss.str();
}
