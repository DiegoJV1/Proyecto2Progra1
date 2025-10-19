#include "Vehiculo.h"
#include<sstream>
Vehiculo::Vehiculo(): placa(""), modelo(""), marca(""), ubiPlantel(""), categoria(""), tipoLicencia(""), estado(""), dueno(nullptr), bitacoraEstado(nullptr), PrecioAlquiler(0.0){}
Vehiculo::Vehiculo(string placa, string modelo, string marca, string ubi, char cat, string lic, char est, Cliente* dueno, ColeccionEstado* b): placa(placa), modelo(modelo), marca(marca), ubiPlantel(ubi), tipoLicencia(lic), dueno(dueno), bitacoraEstado(b) {
	setCategoria(cat);
	setEstado(est);
	setPrecioAlquiler(categoria);
}
Vehiculo::~Vehiculo() {
	bitacoraEstado->~ColeccionEstado();
	delete bitacoraEstado;
	bitacoraEstado = nullptr;
}
void Vehiculo::setDueno(Cliente* aux) { this->dueno = aux; }
void Vehiculo::setPlaca(string placa) { this->placa = placa; }
void Vehiculo::setModelo(string modelo) { this->modelo = modelo; }
void Vehiculo::setMarca(string marca) { this->marca = marca; }
void Vehiculo::setUbiPlantel(string ubi) { this->ubiPlantel = ubi; }
void Vehiculo::setTipoLicencia(string lic) { this->tipoLicencia = lic; }
void Vehiculo::setEstado(char est) {
	switch (est) {
	case 'A':
		this->estado = "Disponible";
		break;
	case 'B':
		this->estado = "Alquilado";
		break;
	case 'C':
		this->estado = "Devuelto";
		break;
	case 'D':
		this->estado = "Revision";
		break;
	case 'E':
		this->estado = "Lavado";
		break;
	}
}
void Vehiculo::setPrecioAlquiler(string cat) { 
	if (cat == "Economico") {
		this->PrecioAlquiler = 10000;
	}
	else if (cat == "Estandar") {
		this->PrecioAlquiler = 20000;
	}
	else if (cat == "Lujo") {
		this->PrecioAlquiler = 40000;
	}
	else if (cat == "4x4") {
		this->PrecioAlquiler = 50000;
	}
}
void Vehiculo::setCategoria(char cat) {
	switch (cat) {
	case 'A':
		this->categoria = "Economico";
		break;
	case 'B':
		this->categoria = "Estandar";
		break;
	case 'C':
		this->categoria = "Lujo";
		break;
	case 'D':
		this->categoria = "4x4";
		break;
	}
}
void Vehiculo::actualizarBitacora(string est) {
	bitacoraEstado->insertarEstado(est);
}
string Vehiculo::getPlaca() { return placa; }
string Vehiculo::getModelo() { return modelo; }
string Vehiculo::getMarca() { return marca; }
string Vehiculo::getUbiPlantel() { return ubiPlantel; }
string Vehiculo::getTipoLicencia() { return tipoLicencia; }
string Vehiculo::getEstado() { return estado; }
string Vehiculo::getCategoria() { return categoria; }
double Vehiculo::getPrecioAlquiler() { return PrecioAlquiler; }
Cliente* Vehiculo::getDueno() { return dueno; }
string Vehiculo::toStringBitacora() {
	stringstream ss;
	ss << bitacoraEstado->toString() << endl;
	return ss.str();
}
string Vehiculo::toString() {
	stringstream ss;
	ss << "Placa: " << placa << endl;
	ss << "Modelo: " << modelo << endl;
	ss << "Marca: " << marca << endl;
	ss << "Ubicacion en el Plantel: " << ubiPlantel << endl;
	ss << "Tipo de licencia requerida: " << tipoLicencia << endl;
	ss << "Estado: " << estado << endl;
	ss << "Categoria: " << categoria << endl;
	ss << "Precio Alquiler: " << PrecioAlquiler << endl;
	ss << " Dueno: " << endl;
	ss << dueno->toString() << endl;
	return ss.str();
}
