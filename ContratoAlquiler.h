#pragma once
#include "SolicitudAlquiler.h"
class ContratoAlquiler : public SolicitudAlquiler{
public:
	virtual void setEstado(char nuevoEstado) override;
};

