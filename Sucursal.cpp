#include "Sucursal.h"
#include<sstream>
Sucursal::Sucursal() : ubicacion(""), clientes(nullptr), colaboradores(nullptr), vehiculos(nullptr), planteles(nullptr), num("") {}
Sucursal::Sucursal(string ubi, ColeccionCliente* clien, ColeccionColaborador* col, ColeccionVehiculo* ve, ColeccionPlantel* plan, string num) : ubicacion(ubi), clientes(clien), colaboradores(col), vehiculos(ve), planteles(plan), num(num) {}
Sucursal::~Sucursal() {
	delete clientes;
	delete colaboradores;
	delete vehiculos;
	delete planteles;
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
void Sucursal::insertarColabordor(Colaborador* aux) {
	if (!colaboradores) {
		colaboradores = new ColeccionColaborador();
		colaboradores->insertarColaborador(aux);
	}
	else {
		colaboradores->insertarColaborador(aux);
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
ColeccionPlantel* Sucursal::getPlanteles() { return planteles; }
ColeccionCliente* Sucursal::getClientes() { return clientes; }
ColeccionColaborador* Sucursal::getColaboradores() { return colaboradores; }
ColeccionVehiculo* Sucursal::getVehiculos() { return vehiculos; }

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
