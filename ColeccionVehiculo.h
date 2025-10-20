#pragma once
#include"NodoVehiculo.h"
class ColeccionVehiculo{
private:
	NodoVehiculo* inicio;
	NodoVehiculo* actual;
public:
	ColeccionVehiculo();
	~ColeccionVehiculo();
	void insertarVehiculo(Vehiculo* aux);
	void eliminarVehiculo(string placa);
	bool buscarVehiculo(string placa);
	string toString();
};

