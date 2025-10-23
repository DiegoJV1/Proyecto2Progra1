#pragma once
#include "SolicitudAlquiler.h"
class ContratoAlquiler : public SolicitudAlquiler{
public:
	ContratoAlquiler();
	ContratoAlquiler(string cod, string idCte, string idCol, string idSuc, string pl, int dias, Fecha* ini, Fecha* ent, float pDia);
	virtual void setEstado(int nuevoEstado) override;
};

