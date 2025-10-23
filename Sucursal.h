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
	Sucursal(string ubi, string num);
	~Sucursal();
	void setNum(string num);
	string getNum();
	void setUbicacion(string ubi); 
	string getUbicaion();
	void insertarCliente(Cliente* aux);
	void insertarVehiculo(Vehiculo* aux);
	void insertarColaborador(Colaborador* aux);
	void insertarPlantel(Plantel* aux);
	ColeccionPlantel* getPlanteles();
	ColeccionCliente* getClientes();
	ColeccionColaborador* getColaboradores();
	ColeccionVehiculo* getVehiculos();
	void eliminarCliente(string id);
	void eliminarVehiculo(string placa);
	void eliminarColaborador(string id);
	void eliminarPlantel(string iden);

	Cliente* getCliente(string id);
	Vehiculo* getVehiculo(string placa);
	Colaborador* getColaborador(string id);
	Plantel* getPlantel(string iden);

	string recomendacionDePlantel();
	string toString();

};

