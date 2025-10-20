#include "Plantel.h"
#include<sstream>
Plantel::Plantel() : identificacion("z"), tipo('0'), p(nullptr), capacidad(0), filas(0), columnas(0) {}
Plantel::Plantel(string iden, char tipo): identificacion(iden), tipo(tipo) {
	setCapacidad();
	p = new Estacionamiento * *[filas];
	for (int i = 0; i < filas; i++) {
		p[i] = new Estacionamiento * [columnas];
		for (int j = 0; j < columnas; j++) {
			p[i][j] = nullptr;
		}
	}
	setCodigosEstacionamientos();
}
Plantel::~Plantel() {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			delete p[i][j];
		}
		delete[] p[i];
	}
	delete[] p;
	capacidad = 0;
	filas = 0; 
	columnas = 0;
	tipo = '0';
}
void Plantel::setCapacidad() {
	if (tipo == 1) {
		capacidad = 6;
		filas = 3;
		columnas = 2;
	}
	else if(tipo == 2) {
		capacidad = 30;
		filas = 6;
		columnas = 5;
	}
	else if (tipo == 3) {
		capacidad = 20;
		filas = 5;
		columnas = 4;
	}
	else if (tipo == 4) {
		capacidad = 25;
		filas = 5;
		columnas = 5;
	}
}
int Plantel::getCapacidad() { return capacidad; }
void Plantel::setTipo(char tipo) { this->tipo = tipo; }
void Plantel::setIdentificacion(string iden) { this->identificacion = iden; }
char Plantel::getTipo() { return tipo; }
string Plantel::getIdentificacion() { return identificacion; }
void Plantel::setCodigosEstacionamientos() {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			p[i][j]->setCodigo(identificacion);
			p[i][j]->setNum1(i);
			p[i][j]->setNum2(j);
		}
	}
}
void Plantel::insertarVehiculo(Vehiculo* aux, string cod, int num1, int num2){
	if (num1 > filas || num1<0 || num2>columnas || num2 < 0) { return; }
	else if (p[num1][num2]->getV() && p[num1][num2]->getEstado() == true) { return; }
	else {
		p[num1][num2]->setV(aux);
	}
}
string Plantel::recomendacionDeEstacionamiento(){
	stringstream ss;
	ss << toString() << endl << endl;
	ss << "Espacios Recomendados: " << endl;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			
		}
	}
}
int Plantel::espaciosLibres() {
	int contador = 0;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (!p[i][j] || p[i][j]->getEstado() == false) {
				contador++;
			}
		}
	}
	return contador;
}
bool Plantel::buscarVehiculo(string placa) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (p[i][j] && p[i][j]->getV()->getPlaca() == placa) {
				return true;
			}
		}
	}
}
Estacionamiento* Plantel::buscarEstacionamientoPorVehiculo(string placa) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (p[i][j] && p[i][j]->getV()->getPlaca() ==placa ) {
				p[i][j]->setEstado('D');
			}
		}
	}
}
string Plantel::toString(){
	stringstream ss;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			ss << p[i][j]->getCodigoNum() << " -> " << p[i][j]->getEstado() << "\t";
		}
		ss << "\n";
	}
	return ss.str();
}
