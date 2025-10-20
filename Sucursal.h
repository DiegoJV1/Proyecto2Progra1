#pragma once
#include"ColeccionColaborador.h"
#include"ColeccionCliente.h"
#include"ColeccionVehiculo.h"
#include"ColeccionPlantel.h"
#include"NodoPlantel.h"
class Sucursal{
private:
	string ubicacion, num;
	ColeccionPlantel* planteles;
	ColeccionCliente* clientes;
	ColeccionVehiculo* vehiculos;
	ColeccionColaborador* colaboradores;
public:
	Sucursal();
	Sucursal(string ubi, ColeccionCliente* clien, ColeccionColaborador* col, ColeccionVehiculo* ve, ColeccionPlantel* plan, string num);
	~Sucursal();
	void setNum(string num);
	string getNum();
	void setUbicacion(string ubi); 
	string getUbicaion();
	void insertarCliente(Cliente* aux);
	void insertarVehiculo(Vehiculo* aux);
	void insertarColabordor(Colaborador* aux);
	void insertarPlantel(Plantel* aux);
	void eliminarCliente(string id);
	void eliminarVehiculo(string placa);
	void eliminarColaborador(string id);
	void eliminarPlantel(string iden);

	string recomendacionDePlantel();
	string toString();

};

