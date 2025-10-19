#include "PersonaJuridica.h"
#include<sstream>
PersonaJuridica::PersonaJuridica() :Cliente(), actividadEconomica(""), porcenDescuento(0.0) {}
PersonaJuridica::PersonaJuridica(string id, string nom, string resi, string act, double desc) : Cliente(id, nom, resi), actividadEconomica(act), porcenDescuento(desc) {}
PersonaJuridica:: ~PersonaJuridica() {}
void PersonaJuridica::setActividadEconomica(string act) { this->actividadEconomica = act; }
void PersonaJuridica::setPorcenDescuento(double desc) { this->porcenDescuento = desc; }
string PersonaJuridica::getActividadEconomica() { return actividadEconomica; }
double PersonaJuridica::getPorcenDescuento() { return porcenDescuento; }
string PersonaJuridica::toString() {
	stringstream ss;
	ss << Cliente::toString() << endl;
	ss << "Actividad Economica: " << actividadEconomica << endl;
	ss << "Porcentaje de Descuento: " << porcenDescuento << endl;
	return ss.str();

}