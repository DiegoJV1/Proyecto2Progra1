#include "ContratoAlquiler.h"
ContratoAlquiler::ContratoAlquiler() :SolicitudAlquiler() {}
ContratoAlquiler::ContratoAlquiler(string cod, string idCte, string idCol, string idSuc, string pl, int dias, Fecha* ini, Fecha* ent, float pDia) :SolicitudAlquiler(cod,idCte,idCol,idSuc,pl,dias,ini,ent,pDia) {}
void ContratoAlquiler::setEstado(char nuevoEstado) {
	estado = "Terminado";
}
c1->setEstado(1);