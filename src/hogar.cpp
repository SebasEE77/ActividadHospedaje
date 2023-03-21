//
// Created by sebat on 18/03/2023.
//

#include "hogar.h"

hogar::hogar(int id, string direccion, int numCamasDispo, int alojarBebes, string descripcionHogar, int disponibilidad):
id(id), direccion(direccion), numCamasDispo(numCamasDispo), alojarBebes(alojarBebes), descripcionHogar(descripcionHogar),
disponibilidad(disponibilidad){}

string hogar::getDireccion() {
    return direccion;
}
int hogar::getnumCamasDispos() {
    return numCamasDispo;
}
int hogar::getalojarBebes() {
    return alojarBebes;
}
string hogar::getdescripcionHogar() {
    return descripcionHogar;
}

int hogar::getDisponibilidad(){
    return disponibilidad;
}

void hogar::setDisponibilidad(int dispo) {
    this->disponibilidad = dispo;
}
