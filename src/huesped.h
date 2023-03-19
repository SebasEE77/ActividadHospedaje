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
    int fechaNacimiento;
    int puntaje;
    vector<huesped*> vectorHuesped;

public:
    huesped() = default;
    huesped(int id, string nombre, string sexo, int fechaNacimiento, int puntaje);

    string getNombre();
    string getSexo();
    int getId();
    int getFechaNacimiento();
    float getPuntaje();

};


#endif //HUESPED_HUESPED_H
