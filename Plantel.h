#pragma once
#include"Estacionamiento.h"
#include<iostream>
using namespace std;
class Plantel{
private:
	string identificacion;
	char tipo;
	int capacidad, filas, columnas;
	Estacionamiento*** p;
public:
	Plantel();
	Plantel(string iden, char tipo);
	~Plantel();
	void setCapacidad();
	int getCapacidad();
	void setTipo(char tipo);
	void setIdentificacion(string iden);
	char getTipo();
	string getIdentificacion();

	void setCodigosEstacionamientos();
	void insertarVehiculo(Vehiculo* aux, string cod, int num1, int num2);

	string recomendacionDeEstacionamiento();
	string toString();

};

