#pragma once
#include"Cliente.h"
#include"ColeccionEstado.h"
class Vehiculo{
private:
	Cliente* dueno;
	string placa, modelo, marca, ubiPlantel, categoria, tipoLicencia, estado;
	double PrecioAlquiler;
	ColeccionEstado* bitacoraEstado;
public:
	Vehiculo();
	Vehiculo(string placa, string modelo, string marca, string ubi, char cat, string lic, Cliente* dueno, ColeccionEstado* b);
	~Vehiculo();
	void setDueno(Cliente* aux);
	void setPlaca(string placa);
	void setModelo(string modelo);
	void setMarca(string marca);
	void setUbiPlantel(string ubi);
	void setTipoLicencia(string lic);
	void setEstado(char est);
	void setPrecioAlquiler(string cat);
	void setCategoria(char cat);
	void actualizarBitacora(string est, Colaborador* c, Fecha* f);
	string getPlaca();
	string getModelo();
	string getMarca();
	string getUbiPlantel();
	string getTipoLicencia();
	string getEstado();
	string getCategoria();
	double getPrecioAlquiler();
	Cliente* getDueno();
	string toStringBitacora();
	string toString();
	void actualizaEstado(char est);
};

