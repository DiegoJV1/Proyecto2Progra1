#pragma once
#include "Sucursal.h"
class SolicitudAlquiler
{
protected:
	string codigo;
	string idCliente;
	string idColaborador;
	string idSucursal;
	string placa;
	int canDias;
	Fecha* inicio;
	Fecha* entrega;
	float precioDia;
	float precioTotal;
	string estado;
public:
	SolicitudAlquiler(string cod, string idCte, string idCol, string idSuc, string pl, int dias, Fecha* ini, Fecha* ent, float pDia);
	virtual ~SolicitudAlquiler();

	string getCodigo();
	string getIdCliente();
	string getIdColaborador();
	string getIdSucursal();
	string getPlaca();
	int getCanDias();
	Fecha* getInicio();
	Fecha* getEntrega();
	float getPrecioDia();
	float getPrecioTotal();
	string getEstado();


	void setCodigo(string);
	void setIdCliente(string);
	void setIdColaborador(string);
	void setIdSucursal(string);
	void setPlaca(string);
	void setCanDias(int);
	void setInicio(Fecha*);
	void setEntrega(Fecha*);
	void setPrecioDia(float);

	void calcularPrecioTotal();
	void setEstado(string nuevoEstado);
};

