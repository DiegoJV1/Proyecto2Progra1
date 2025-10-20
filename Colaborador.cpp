#include "Colaborador.h"
#include<sstream>
Colaborador::Colaborador(): id(""), nombre(""), fechaIngreso("") {}
Colaborador::Colaborador(string id, string nom, string fecha) : id(id), nombre(nom), fechaIngreso(fechaIngreso) {}
Colaborador::~Colaborador() {}
void Colaborador::setNombre(string nom) { this->nombre = nom; }
void Colaborador::setId(string id) { this->id = id; }
void Colaborador::setFechaIngreso(string fecha) { this->fechaIngreso = fecha; }
string Colaborador::getNombre() { return nombre; }
string Colaborador::getId() { return id; }
string Colaborador::getFechaIngreso() { return fechaIngreso; }
string Colaborador::toString() {
	stringstream ss;
	ss << "Nombre: " << nombre << endl;
	ss << "Id: " << id << endl;
	ss << "Fecha de Ingreso: " << endl;
	return ss.str();
}
