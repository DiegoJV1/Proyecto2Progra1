#pragma once
#include"Vehiculo.h"
class NodoVehiculo{
private:
	Vehiculo* obj;
	NodoVehiculo* sig;
public:
	NodoVehiculo();
	NodoVehiculo(Vehiculo* aux);
	~NodoVehiculo();
	void setObj(Vehiculo* aux);
	void setSig(NodoVehiculo* aux);
	Vehiculo* getObj();
	NodoVehiculo* getSig();
};

