#include "Colaborador.h"
#include<sstream>
Colaborador::Colaborador(): id(""), nombre(""), fechaIngreso(nullptr) {
	trabajos = new ColeccionSolicitudAlquiler();
}
Colaborador::Colaborador(string id, string nom, Fecha* fecha) : id(id), nombre(nom), fechaIngreso(fechaIngreso) {
	trabajos = new ColeccionSolicitudAlquiler();
}
Colaborador::~Colaborador() {
	delete trabajos;
}
void Colaborador::setNombre(string nom) { this->nombre = nom; }
void Colaborador::setId(string id) { this->id = id; }
void Colaborador::setFechaIngreso(Fecha* fecha) { this->fechaIngreso = fecha; }
void Colaborador::insertarTrabajo(SolicitudAlquiler* aux) {
	if (aux->getIdColaborador() == id) {
		trabajos->insertarSolicitud(aux);
	}
}
ColeccionSolicitudAlquiler* Colaborador::getHistorialTrabajos() { return trabajos; }
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
