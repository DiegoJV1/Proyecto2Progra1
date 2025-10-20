#include "Estacionamiento.h"
#include<sstream>
Estacionamiento::Estacionamiento() :codigo(""), estado(false), v(nullptr), num1(0), num2(0) {}
Estacionamiento::Estacionamiento(string cod, int num1,int num2, char est, Vehiculo* aux) : codigo(cod), v(aux), num1(num1), num2(num2) {
	setEstado(est);
}
Estacionamiento::~Estacionamiento() {
	delete v;
	v = nullptr;
	estado = false;
}
void Estacionamiento::setCodigo(string cod) { this->codigo = cod; }
void Estacionamiento::setNum1(int num1) { this->num1 = num1; }
void Estacionamiento::setNum2(int num2) { this->num2 = num2; }
int Estacionamiento::getNum1() { return num1; }
int Estacionamiento::getNum2() { return num2; }
string Estacionamiento::getCodigo() { return codigo; }
string Estacionamiento::getCodigoNum() {
	stringstream ss;
	ss << codigo << num1<<num2;
	return ss.str();
}
void Estacionamiento::setEstado(char est) {
	switch (est) {
		case 'D':
			estado = false;
			break;
		case 'O':
			estado = true;
			break;
		default:
			estado = false;
			break;
	}
}
bool Estacionamiento::getEstado() { return estado; }
void Estacionamiento::setV(Vehiculo* aux) { 
	this->v = aux; 
	setEstado('O');
}
Vehiculo* Estacionamiento::getV() { return v; }
string Estacionamiento::toString() {
	stringstream ss;
	ss << "Estacionamiento #" << getCodigoNum() << endl;
	ss << "Estado: ";
	if (estado == true) {
		ss << "Ocupado" << endl;
		ss << "Datos del vehiculo: " << endl;
		ss << v->toString() << endl;
	}
	else {
		ss << "Disponible" << endl;
		ss << "Sin vehiculo asignado." << endl;
	}
	return ss.str();
}
