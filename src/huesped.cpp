//
// Created by sebat on 18/03/2023.
//

#include "huesped.h"

huesped::huesped(int id, string nombre, string sexo, string fechaNacimiento, float puntaje):
id(id), nombre(nombre), sexo(sexo),fechaNacimiento(fechaNacimiento), puntaje(puntaje){}

int huesped::getId(){
    return id;
}
string huesped::getNombre(){
    return nombre;
}
string huesped::getSexo(){
    return sexo;
}
string huesped::getFechaNacimiento(){
    return fechaNacimiento;
}
float huesped::getPuntaje() {
    return puntaje;
};

void huesped::setPuntaje(float puntaje) {
    this->puntaje = puntaje;
}
