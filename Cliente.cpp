#include "Cliente.h"
#include<sstream>
Cliente::Cliente(): id(""), nombre(""), residencia(""), contador(0) {
	solicitudes = new ColeccionSolicitudAlquiler();
}
Cliente::~Cliente() {
	delete solicitudes;
	solicitudes = nullptr;
}
Cliente::Cliente(string id, string nom, string resi): id(id), nombre(nom), residencia(resi), contador(0) {
	solicitudes = new ColeccionSolicitudAlquiler();
}
void Cliente::setId(string id) { this->id = id; }
void Cliente::setNombre(string nom) { this->nombre = nom; }
void Cliente::setResidencia(string resi) { this->residencia = resi; }
void Cliente::insertarSolicitud(SolicitudAlquiler* aux) {
	if (aux->getIdCliente() == id) {
		solicitudes->insertarSolicitud(aux);
		contador++;

	}
}
string Cliente::getId() { return id; }
string Cliente::getNombre() { return nombre; }
string Cliente::getResidencia() { return residencia; }
ColeccionSolicitudAlquiler* Cliente::getHistorialAlquiler() { return solicitudes; }
int Cliente::getCantidadDeSolicitudes() { return contador; }
string Cliente::toString() {
	stringstream ss;
	ss << "Nombre: " << nombre << endl;
	ss << "Id: " << id << endl;
	ss << "Lugar de Residencia: " << residencia << endl;
	return ss.str();
}
