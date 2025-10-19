#pragma once
#include "Cliente.h"
class PersonaJuridica :public Cliente{
protected:
	string actividadEconomica;
	double porcenDescuento;
public:
	PersonaJuridica();
	PersonaJuridica(string id, string nom, string resi, string act, double desc);
	virtual ~PersonaJuridica();
	void setActividadEconomica(string act);
	void setPorcenDescuento(double desc);
	string getActividadEconomica();
	double getPorcenDescuento();
	virtual string toString()override;
};

