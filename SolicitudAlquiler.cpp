#include "SolicitudAlquiler.h"
SolicitudAlquiler::SolicitudAlquiler(string cod, string idCte, string idCol, string idSuc,string pl, int dias, Fecha* ini, Fecha* ent, float pDia)
    : codigo(cod),
    idCliente(idCte),
    idColaborador(idCol),
    idSucursal(idSuc),
    placa(pl),
    canDias(dias),
    inicio(ini),
    entrega(ent),
    precioDia(pDia),
    estado("pendiente")
{
    calcularPrecioTotal();
}
SolicitudAlquiler::~SolicitudAlquiler() {
    delete inicio;
    delete entrega;
}

void SolicitudAlquiler::calcularPrecioTotal() {
    precioTotal = precioDia * canDias;
}

string SolicitudAlquiler::getCodigo() { return codigo; }
string SolicitudAlquiler::getIdCliente() { return idCliente; }
string SolicitudAlquiler::getIdColaborador() { return idColaborador; }
string SolicitudAlquiler::getIdSucursal() { return idSucursal; }
string SolicitudAlquiler::getPlaca() { return placa; }
int SolicitudAlquiler::getCanDias() { return canDias; }
Fecha* SolicitudAlquiler::getInicio() { return inicio; }
Fecha* SolicitudAlquiler::getEntrega() { return entrega; }
float SolicitudAlquiler::getPrecioDia() { return precioDia; }
float SolicitudAlquiler::getPrecioTotal() { return precioTotal; }
string SolicitudAlquiler::getEstado() { return estado; }

void SolicitudAlquiler::setCodigo(string n) { codigo = n; }
void SolicitudAlquiler::setIdCliente(string n) { idCliente = n; }
void SolicitudAlquiler::setIdColaborador(string n) { idColaborador = n; }
void SolicitudAlquiler::setIdSucursal(string n) { idSucursal = n; }
void SolicitudAlquiler::setPlaca(string n) { placa = n; }

void SolicitudAlquiler::setCanDias(int nuevoDias) {
    canDias = nuevoDias;
    calcularPrecioTotal(); 
}

void SolicitudAlquiler::setInicio(Fecha* nuevoIni) {
    delete inicio;
    inicio = nuevoIni;
}

void SolicitudAlquiler::setEntrega(Fecha* nuevoEnt) {
    delete entrega;
    entrega = nuevoEnt;
}

void SolicitudAlquiler::setPrecioDia(float nuevoPDia) {
    precioDia = nuevoPDia;
    calcularPrecioTotal();
}

void SolicitudAlquiler::setEstado(string nuevoEstado) {
    estado = nuevoEstado;
}