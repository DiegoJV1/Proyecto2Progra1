#pragma once
#include"NodoPlantel.h"
class ColeccionPlantel{
private:
	NodoPlantel* inicio;
	NodoPlantel* actual;
public:
	ColeccionPlantel();
	~ColeccionPlantel();
	void insertarPlantel(Plantel* aux);
	void eliminarPlantel(string iden);
	bool buscarPlantel(string iden);
	string plantelRecomendado();
	string toString();
};

