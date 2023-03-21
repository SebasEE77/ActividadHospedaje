//
// Created by sebat on 18/03/2023.
//

#include "reservas.h"

reservas::reservas(int idPropietario,string nombreHuesped,string fechaInicio, string fechaFin): idPropietario(idPropietario),
nombreHuesped(nombreHuesped), fechaInicio(fechaInicio), fechaFin(fechaFin) {}

int reservas::getidPropietario(){
    return idPropietario;
}
string reservas::getNombreHuesped(){
    return nombreHuesped;
}
string reservas::getFechaInicio(){
    return fechaInicio;
}
string reservas::getFechaFin() {
    return fechaFin;
}
