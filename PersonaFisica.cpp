#include "PersonaFisica.h"
#include<sstream>
PersonaFisica::PersonaFisica(): Cliente(){}
PersonaFisica::PersonaFisica(string id, string nom, string resi) : Cliente(id, nom, resi) {}
PersonaFisica::~PersonaFisica() {}
string toString() {
	stringstream ss;
	ss<<Cliente::toString;
	return ss.str();
}