#include "PersonaFisica.h"
#include<sstream>
PersonaFisica::PersonaFisica(): Cliente(){}
PersonaFisica::PersonaFisica(string id, string nom, string resi) : Cliente(id, nom, resi) {}
PersonaFisica::~PersonaFisica() {}
