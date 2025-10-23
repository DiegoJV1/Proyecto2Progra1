#include "Plantel.h"
#include<sstream>
Plantel::Plantel() : identificacion("z"), tipo('0'), p(nullptr), capacidad(0), filas(0), columnas(0) {}
Plantel::Plantel(string iden, char tipo, int f, int c): identificacion(iden), tipo(tipo), filas(f), columnas(c) {
	setCapacidad();
	p = new Estacionamiento * *[filas];
	for (int i = 0; i < filas; i++) {
		p[i] = new Estacionamiento * [columnas];
		for (int j = 0; j < columnas; j++) {
			p[i][j] =new Estacionamiento();
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
	capacidad = filas * columnas;
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
		p[num1][num2]->getV()->setUbiPlantel(p[num1][num2]->getCodigoNum());
	}
}
void Plantel::insertarDisponible(Vehiculo* aux) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (!p[i][j]->getV()) {
				p[i][j]->setV(aux);
				p[i][j]->getV()->setUbiPlantel(p[i][j]->getCodigoNum());
			}
		}
	}
}
void Plantel::eliminarVehiculo(string placa) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (p[i][j]->getV()->getPlaca()==placa) {
				p[i][j]->setV(nullptr);
			}
		}
	}
}
string Plantel::recomendacionDeEstacionamiento(){
	stringstream ss;
	int contador = 0;
	int hayRecomendados = 0;
	ss << toString() << endl << endl;
	ss << "Espacios Recomendados: " << endl;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			//esquinas
			if (i == 0 && j == 0) {
				if (p[i][j+1]->getEstado()) {
					contador++;
				}
				if (p[i+1][j]->getEstado()) {
					contador++;
				}
				if (p[i+1][j + 1]->getEstado()) {
					contador++;
				}
			}
			if (i == filas && j == 0) {
				if (p[i][j + 1]->getEstado()) {
					contador++;
				}
				if (p[i - 1][j]->getEstado()) {
					contador++;
				}
				if (p[i - 1][j + 1]->getEstado()) {
					contador++;
				}
			}
			if (i == 0 && j == columnas) {
				if (p[i][j - 1]->getEstado()) {
					contador++;
				}
				if (p[i + 1][j -1]->getEstado()) {
					contador++;
				}
				if (p[i + 1][j]->getEstado()) {
					contador++;
				}
			}
			if (i == filas && j == columnas) {
				if (p[i - 1][j]->getEstado()) {
					contador++;
				}
				if (p[i - 1][j-1]->getEstado()) {
					contador++;
				}
				if (p[i][j - 1]->getEstado()) {
					contador++;
				}
			}
			//laterales
			if (i == 0 && j!= 0 && j!=columnas) {
				if (p[i][j + 1]->getEstado()) {
					contador++;
				}
				if (p[i][j - 1]->getEstado()) {
					contador++;
				}
				if (p[i + 1][j]->getEstado()) {
					contador++;
				}
				if (p[i + 1][j+1]->getEstado()) {
					contador++;
				}
				if (p[i + 1][j-1]->getEstado()) {
					contador++;
				}
			}
			if (i != 0 && i != filas && j == 0) {
				if (p[i][j + 1]->getEstado()) {
					contador++;
				}
				if (p[i+1][j]->getEstado()) {
					contador++;
				}
				if (p[i + 1][j+1]->getEstado()) {
					contador++;
				}
				if (p[i - 1][j]->getEstado()) {
					contador++;
				}
				if (p[i - 1][j + 1]->getEstado()) {
					contador++;
				}
			}
			if (i != 0 && i != filas && j == columnas) {
				if (p[i-1][j]->getEstado()) {
					contador++;
				}
				if (p[i-1][j - 1]->getEstado()) {
					contador++;
				}
				if (p[i][j-1]->getEstado()) {
					contador++;
				}
				if (p[i + 1][j - 1]->getEstado()) {
					contador++;
				}
				if (p[i+1][j]->getEstado()) {
					contador++;
				}
			}
			if (i == filas && j != 0 && j == columnas) {
				if (p[i-1][j]->getEstado()) {
					contador++;
				}
				if (p[i-1][j - 1]->getEstado()) {
					contador++;
				}
				if (p[i - 1][j + 1]->getEstado()) {
					contador++;
				}
				if (p[i][j + 1]->getEstado()) {
					contador++;
				}
				if (p[i][j - 1]->getEstado()) {
					contador++;
				}
			}
			//normales
			if (i != 0 && i != filas && j != 0 && j != columnas) {
				if (p[i][j + 1]->getEstado()) {
					contador++;
				}
				if (p[i][j - 1]->getEstado()) {
					contador++;
				}
				if (p[i + 1][j]->getEstado()) {
					contador++;
				}
				if (p[i + 1][j + 1]->getEstado()) {
					contador++;
				}
				if (p[i + 1][j - 1]->getEstado()) {
					contador++;
				}
				if (p[i - 1][j]->getEstado()) {
					contador++;
				}
				if (p[i - 1][j + 1]->getEstado()) {
					contador++;
				}
				if (p[i - 1][j - 1]->getEstado()) {
					contador++;
				}
			}
			if (contador == 0) {
				ss << p[i][j]->getCodigo() << endl;
				hayRecomendados++;
			}
			contador = 0;
		}
	}
	if (hayRecomendados == 0) {
		cout << "No hay estacionamientos recomendados" << endl;
	}
	return ss.str();
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
Vehiculo* Plantel::buscarVehiculoPorCodigo(string cod) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (p[i][j]->getCodigoNum()==cod && p[i][j]->getV()) {
				return p[i][j]->getV();
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
