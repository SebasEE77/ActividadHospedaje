//
// Created by sebat on 17/03/2023.
//

#include "propietario.h"

propietario::propietario(int id, string nombre, string sexo,
                         int fechaNacimiento, float puntaje): id(id),nombre(nombre),sexo(sexo),
                         fechaNacimiento(fechaNacimiento),puntaje(puntaje) {}


int propietario::getId(){
    return id;
}
string propietario::getNombre(){
    return nombre;
}
string propietario::getSexo(){
    return sexo;
}
string propietario::getFechaNacimiento(){
    return fechaNacimiento;
}
float propietario::getPuntaje() {
    return puntaje;
};

void propietario::setPuntaje(float puntaje){
    this->puntaje = puntaje;
}
