#include "Vehiculo.h"
#include<sstream>
Vehiculo::Vehiculo(): placa(""), modelo(""), marca(""), ubiPlantel(""), categoria(""), tipoLicencia(""), estado(""), dueno(nullptr), PrecioAlquiler(0.0){
	solicitudes = new ColeccionSolicitudAlquiler();
	bitacoraEstado = new ColeccionEstado();
}
Vehiculo::Vehiculo(string placa, string modelo, string marca, char cat, string lic, Cliente* dueno): placa(placa), modelo(modelo), marca(marca), tipoLicencia(lic), dueno(dueno) {
	solicitudes = new ColeccionSolicitudAlquiler();
	bitacoraEstado = new ColeccionEstado();
	setCategoria(cat);
	setEstado('A', nullptr, nullptr);
	setPrecioAlquiler(categoria);
}
Vehiculo::~Vehiculo() {
	delete bitacoraEstado;
	bitacoraEstado = nullptr;
	delete solicitudes;
	solicitudes = nullptr;
}
void Vehiculo::setDueno(Cliente* aux) { this->dueno = aux; }
void Vehiculo::setPlaca(string placa) { this->placa = placa; }
void Vehiculo::setModelo(string modelo) { this->modelo = modelo; }
void Vehiculo::setMarca(string marca) { this->marca = marca; }
void Vehiculo::setUbiPlantel(string ubi) { this->ubiPlantel = ubi; }
void Vehiculo::setTipoLicencia(string lic) { this->tipoLicencia = lic; }
void Vehiculo::setEstado(char est, Colaborador* c, Fecha* f) {
	switch (est) {
	case 'A':
		this->estado = "Disponible";
		actualizarBitacora("Disponible", c, f);
		break;
	case 'B':
		this->estado = "Alquilado";
		actualizarBitacora("Alquilado", c, f);
		break;
	case 'C':
		this->estado = "Devuelto";
		actualizarBitacora("Devuelto", c, f);
		break;
	case 'D':
		this->estado = "Revision";
		actualizarBitacora("Revision", c, f);
		break;
	case 'E':
		this->estado = "Lavado";
		actualizarBitacora("Lavado", c, f);
		break;
	}
}
void Vehiculo::actualizaEstado(char est, Colaborador* c, Fecha* f) {
	if (bitacoraEstado->getUltimo() == "Disponible") {
		if (est == 'B' || est == 'D' || est == 'E') {
			setEstado(est, c, f);
		}
		else { return; }
	}
	else if (bitacoraEstado->getUltimo() == "Alquilado") {
		if (est == 'A' || est == 'C') {
			setEstado(est, c, f);
		}
		else { return; }
	}
	else if (bitacoraEstado->getUltimo() == "Devuelto") {
		if (est == 'D' || est == 'E') {
			setEstado(est, c, f);
		}
		else { return; }
	}
	else if (bitacoraEstado->getUltimo() == "Revision") {
		if (est == 'E') {
			setEstado(est, c, f);
		}
		else { return; }
	}
	else if (bitacoraEstado->getUltimo() == "Lavado") {
		if (est == 'A' || est == 'D') {
			setEstado(est, c, f);
		}
		else { return; }
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
	else {
		this->PrecioAlquiler = 0;
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
	default:
		this->categoria = "Sin Categoria";
		break;
	}
	
}
void Vehiculo::actualizarBitacora(string est,Colaborador* c, Fecha* f) {
	bitacoraEstado->insertarEstado(est, c, f);
}
void Vehiculo::insertarSolicitud(SolicitudAlquiler* aux) {
	if (aux->getPlaca() == placa) {
		solicitudes->insertarSolicitud(aux);
	}
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
ColeccionSolicitudAlquiler* Vehiculo::getHistorialSolicitudes() { return solicitudes; }


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
	if (dueno) {
		ss << dueno->toString() << endl;
	}
	else {
		ss << "Dueno Nulo" << endl;
	}
	return ss.str();
}
