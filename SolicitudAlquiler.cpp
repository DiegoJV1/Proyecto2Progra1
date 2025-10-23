#include "SolicitudAlquiler.h"
#include<sstream>
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

void SolicitudAlquiler::setEstado(int nuevoEstado) {
    switch (nuevoEstado) {
        case 1: {
            estado = "aprobada";
            break;
        }
        case 2 : {
            estado = "pendiente";
            break;
        }
        case 3 : {
            estado = "rechazada";
            break;
        }
        case 4 : {
            estado = "anulada";
            break;
        }
    }
}
string SolicitudAlquiler::toString() {
    stringstream ss;
    ss << "----Solicitud de Alquiler----" << endl;
    ss << "Codigo: " << codigo << endl;
    ss << "Colaborador-Id: " << idColaborador << endl;
    ss << "Cliente-Id: " << idCliente << endl;
    ss << "Placa-Vehiculo: " << placa << endl;
    ss << "Sucursal-Id: " << idSucursal << endl;
    ss << "Fecha de inicio: " << inicio->toString() << endl;
    ss << "Fecha de entega: " << entrega->toString() << endl;
    ss << "Costo Diario: " << precioDia << endl;
    ss << "Costo Total: " << precioTotal << endl;
    ss << "Estado: " << estado << endl;
    return ss.str();
}