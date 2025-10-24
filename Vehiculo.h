#pragma once
#include"ColeccionEstado.h"
#include"ColeccionSolicitudAlquiler.h"
class Vehiculo{
private:
	string placa, modelo, marca, ubiPlantel, categoria, tipoLicencia, estado;
	double PrecioAlquiler;
	ColeccionEstado* bitacoraEstado;
	ColeccionSolicitudAlquiler* solicitudes;
public:
	Vehiculo();
	Vehiculo(string placa, string modelo, string marca, char cat, string lic);
	~Vehiculo();
	void setPlaca(string placa);
	void setModelo(string modelo);
	void setMarca(string marca);
	void setUbiPlantel(string ubi);
	void setTipoLicencia(string lic);
	void setEstado(char est, Colaborador* c, Fecha* f);
	void setPrecioAlquiler(string cat);
	void setCategoria(char cat);
	void actualizarBitacora(string est, Colaborador* c, Fecha* f);
	void insertarSolicitud(SolicitudAlquiler* aux);

	string getPlaca();
	string getModelo();
	string getMarca();
	string getUbiPlantel();
	string getTipoLicencia();
	string getEstado();
	string getCategoria();
	double getPrecioAlquiler();
	ColeccionSolicitudAlquiler* getHistorialSolicitudes();

	string toStringBitacora();
	string toString();
	void actualizaEstado(char est, Colaborador* c, Fecha* f);
};

