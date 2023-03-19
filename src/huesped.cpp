//
// Created by sebat on 18/03/2023.
//

#include "huesped.h"

huesped::huesped(int id, string nombre, string sexo, int fechaNacimiento, int puntaje):
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
int huesped::getFechaNacimiento(){
    return fechaNacimiento;
}
float huesped::getPuntaje() {
    return puntaje;
};
