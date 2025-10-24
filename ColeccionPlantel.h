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
	Plantel* buscarPlantelPorVehiculo(string placa);
	string plantelRecomendado();
	Plantel* getPlantel(string iden);
	string porcentajeDeCapacidadDeLosPlanteles();
	string toString();
};

