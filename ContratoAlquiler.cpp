#include "ContratoAlquiler.h"

ContratoAlquiler::ContratoAlquiler(string cod, string idCte, string idCol, string idSuc, string pl, int dias, Fecha* ini, Fecha* ent, float pDia) : SolicitudAlquiler(cod, idCte, idCol, idSuc, pl, dias, ini, ent, pDia) {}
void ContratoAlquiler::setEstado(int nuevoEstado) {
    switch (nuevoEstado) {
    case 1: {
        estado = "aprobado en alquiler";
        break;
    }
    case 2: {
        estado = "aprobado pendiente de ejecucion";
        break;
    }
    case 3: {
        estado = "finalizado con multa";
        break;
    }
    case 4: {
        estado = "finalizado con reintegro";
        break;
    }
    case 5: {
        estado = "finalizado sin vargos adicionales";
        break;
    }
    }
}
void ContratoAlquiler::setPrecioTotal(float pre) {
    precioTotal = pre;
}