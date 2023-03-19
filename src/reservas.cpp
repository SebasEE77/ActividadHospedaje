//
// Created by sebat on 18/03/2023.
//

#include "reservas.h"

reservas::reservas(int idPropietario,string nombreHuesped,int fechaInicio, int fechaFin): idPropietario(idPropietario),
nombreHuesped(nombreHuesped), fechaInicio(fechaInicio), fechaFin(fechaFin) {}

int reservas::getidPropietario(){
    return idPropietario;
}
string reservas::getNombreHuesped(){
    return nombreHuesped;
}
int reservas::getFechaInicio(){
    return fechaInicio;
}
int reservas::getFechaFin() {
    return fechaFin;
}
