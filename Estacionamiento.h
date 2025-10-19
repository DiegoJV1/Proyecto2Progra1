#pragma once
class Estacionamiento{
private:
	string codigo;
	bool estado;
	Vehiculo* v;
public:
	Estacionamiento();
	Estacionamiento(string, bool, Vehiculo);
	~Estacionamiento();
	void setCodigo(string);
	string getCodigo();
	void setEstado(bool);
	bool getEstado();
	void setV(Vehiculo*);
	Vehiculo* getV();
	string toString();
};

