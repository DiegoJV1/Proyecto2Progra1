#pragma once
#include"Vehiculo.h"
class Estacionamiento{
private:
	string codigo;
	int num1, num2;
	bool estado;
	Vehiculo* v;
public:
	Estacionamiento();
	Estacionamiento(string cod, int num1, int num2, char est, Vehiculo* aux);
	~Estacionamiento();
	void setCodigo(string cod);
	void setNum1(int num1);
	int getNum1();
	int getNum2();
	void setNum2(int num2);
	string getCodigoNum();
	string getCodigo();
	void setEstado(char est);
	bool getEstado();
	void setV(Vehiculo* aux);
	Vehiculo* getV();
	string toString();

};

