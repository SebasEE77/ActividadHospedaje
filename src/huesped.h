//
// Created by sebat on 18/03/2023.
//

#ifndef HUESPED_HUESPED_H
#define HUESPED_HUESPED_H
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;
using std::string;
using std::endl;
using std::iterator;
using std::cin;
using std::unordered_map;
using std::make_pair;
using std::vector;


class huesped {
private:
    int id;
    string nombre;
    string sexo;
    string fechaNacimiento;
    float puntaje;

public:
    huesped() = default;
    huesped(int id, string nombre, string sexo, string fechaNacimiento, float puntaje);

    string getNombre();
    string getSexo();
    int getId();
    string getFechaNacimiento();
    float getPuntaje();
    void setPuntaje(float puntaje);

};


#endif //HUESPED_HUESPED_H
