//
// Created by sebat on 17/03/2023.
//

#ifndef HUESPED_PROPIETARIO_H
#define HUESPED_PROPIETARIO_H
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "huesped.h"

using std::cout;
using std::string;
using std::endl;
using std::iterator;
using std::cin;
using std::unordered_map;
using std::make_pair;
using std::vector;


class propietario {
private:
    int id;
    string nombre;
    string sexo;
    int fechaNacimiento;
    float puntaje;


public:
    propietario() = default;
    propietario(int id, string nombre, string sexo, int fechaNacimiento, float puntaje);

    int getId();
    string getNombre();
    string getSexo();
    int getFechaNacimiento();
    float getPuntaje();
};


#endif //HUESPED_PROPIETARIO_H
