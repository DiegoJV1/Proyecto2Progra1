#include "Fecha.h"
#include<sstream>
Fecha::Fecha() {
	dia = 0;
	mes = 0;
	annio = 0;
}
Fecha::Fecha(int auxdia, int auxmes, int auxannio) {
	this->dia = auxdia;
	this->mes = auxmes;
	this->annio = auxannio;
}
void Fecha::setDia(int auxdia) {
	if (auxdia > 0 && auxdia < 32) {
		this->dia = auxdia;
	}
}
void Fecha::setMes(int auxmes) {
	if (auxmes > 0 && auxmes < 13) {
		this->mes = auxmes;
	}
}
void Fecha::setAnnio(int auxannio) {
	this->annio = auxannio;
}

int Fecha::getDia() {
	return dia;
}
int Fecha::getMes() {
	return mes;
}
int Fecha::getAnnio() {
	return annio;
}
string Fecha::toString() {
	stringstream ss;
	ss << dia << "/" << mes << "/" << annio << endl;
	return ss.str();
}

