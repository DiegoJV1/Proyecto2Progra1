#pragma once
#include "Cliente.h"
class PersonaFisica : public Cliente{
public:
	PersonaFisica();
	PersonaFisica(string id, string nom, string resi);
	virtual ~PersonaFisica();
	virtual string toString()override;
};

