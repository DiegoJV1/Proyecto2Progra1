#include "Sucursal.h"
#include<sstream>
Sucursal::Sucursal() : ubicacion(""), num("") {
	clientes = new ColeccionCliente();
	colaboradores = new ColeccionColaborador();
	vehiculos = new ColeccionVehiculo();
	planteles = new ColeccionPlantel();
	solicitudes = new ColeccionSolicitudAlquiler();
}
Sucursal::Sucursal(string ubi, string num) : ubicacion(ubi), num(num) {
	clientes = new ColeccionCliente();
	colaboradores = new ColeccionColaborador();
	vehiculos = new ColeccionVehiculo();
	planteles = new ColeccionPlantel();
	solicitudes = new ColeccionSolicitudAlquiler();
}
Sucursal::~Sucursal() {
	delete clientes;
	delete colaboradores;
	delete vehiculos;
	delete planteles;
	delete solicitudes;
}
void Sucursal::setNum(string num) { this->num = num; }
string Sucursal::getNum() { return num; }
void Sucursal::setUbicacion(string ubi) { this->ubicacion = ubi; }
string Sucursal::getUbicaion() { return ubicacion; }
void Sucursal::insertarPlantel(Plantel* aux) {
	if (!planteles) {
		planteles = new ColeccionPlantel();
		planteles->insertarPlantel(aux);
	}
	else {
		planteles->insertarPlantel(aux);
	}
	
}
void Sucursal::insertarCliente(Cliente* aux) {
	if (!clientes) {
		clientes = new ColeccionCliente();
		clientes->insertarCliente(aux);
	}
	else {
		clientes->insertarCliente(aux);
	}
}
void Sucursal::insertarVehiculo(Vehiculo* aux) {
	if (!vehiculos) {
		vehiculos = new ColeccionVehiculo();
		vehiculos->insertarVehiculo(aux);
	}
	else {
		vehiculos->insertarVehiculo(aux);
	}
}
void Sucursal::insertarColaborador(Colaborador* aux) {
	if (!colaboradores) {
		colaboradores = new ColeccionColaborador();
		colaboradores->insertarColaborador(aux);
	}
	else {
		colaboradores->insertarColaborador(aux);
	}
}
void Sucursal::insertarSolicitud(SolicitudAlquiler* aux) {
	if (solicitudes) {
		solicitudes = new ColeccionSolicitudAlquiler();
		solicitudes->insertarSolicitud(aux);
	}
	else {
		solicitudes->insertarSolicitud(aux);
	}
}
void Sucursal::eliminarCliente(string id) {
	if (clientes) {
		clientes->eliminarCliente(id);
	}
	else {
		return;
	}
}
void Sucursal::eliminarVehiculo(string placa) {
	if (vehiculos) {
		vehiculos->eliminarVehiculo(placa);
	}
	else {
		return;
	}
}
void Sucursal::eliminarColaborador(string id) {
	if (colaboradores) {
		colaboradores->eliminarColaborador(id);
	}
	else {
		return;
	}
}
void Sucursal::eliminarPlantel(string identificacion) {
	if (planteles) {
		planteles->eliminarPlantel(identificacion);
	}
	else {
		return;
	}
}
Cliente* Sucursal::getCliente(string id) {
	return clientes->getCliente(id);
}
Vehiculo* Sucursal::getVehiculo(string placa) {
	return vehiculos->getVehiculo(placa);
}
Colaborador* Sucursal::getColaborador(string id) {
	return colaboradores->getColaborador(id);
}
Plantel* Sucursal::getPlantel(string iden) {
	return planteles->getPlantel(iden);
}
SolicitudAlquiler* Sucursal::getSolicitud(string cod) {
	return solicitudes->buscarSolicitud(cod);
}

ColeccionPlantel* Sucursal::getPlanteles() { return planteles; }
ColeccionCliente* Sucursal::getClientes() { return clientes; }
ColeccionColaborador* Sucursal::getColaboradores() { return colaboradores; }
ColeccionVehiculo* Sucursal::getVehiculos() { return vehiculos; }
ColeccionSolicitudAlquiler* Sucursal::getSolicitudes() { return solicitudes; }


string Sucursal::recomendacionDePlantel() {
	if (planteles) {
		return planteles->plantelRecomendado();
	}
}


string Sucursal::toString() {
	stringstream ss;
	ss << "----Sucursal "<<num<<"----" << endl;
	ss << "Ubicacion: " << ubicacion << endl;
	if (planteles) {
		ss << "Detalle de Planteles: " << endl;
		ss << planteles->toString() << endl;
		ss << "-----------------------------------------" << endl;
	}
	else {
		ss << "Detalle de Planteles: nulo" << endl;
		ss << "-----------------------------------------" << endl;
	}

	if (clientes) {
		ss << "Detalle de Clientes: " << endl;
		ss << clientes->toString() << endl;
		ss << "-----------------------------------------" << endl;
	}
	else {
		ss << "Detalle de Clientes: nulo" << endl;
		ss << "-----------------------------------------" << endl;
	}

	if (vehiculos) {
		ss << "Detalle de Vehiculos: " << endl;
		ss << vehiculos->toString() << endl;
		ss << "-----------------------------------------" << endl;
	}
	else {
		ss << "Detalle de Vehiculos: nulo" << endl;
		ss << "-----------------------------------------" << endl;
	}

	if (colaboradores) {
		ss << "Detalle de Colaboradores: " << endl;
		ss << colaboradores->toString() << endl;
		ss << "-----------------------------------------" << endl;
	}
	else {
		ss << "Detalle de Colaboradores: nulo" << endl;
		ss << "-----------------------------------------" << endl;
	}
	return ss.str();
}
