//
// Created by sebat on 18/03/2023.
//

#ifndef HUESPED_RESERVAS_H
#define HUESPED_RESERVAS_H
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "huesped.h"
#include "propietario.h"


using std::cout;
using std::string;
using std::endl;
using std::iterator;
using std::cin;
using std::unordered_map;
using std::make_pair;

class reservas {
private:
    int idPropietario;
    string nombreHuesped;
    int fechaInicio;
    int fechaFin;

public:
    reservas() = default;
    reservas(int idPropietario,string nombreHuesped,int fechaInicio, int fechaFin);

    int getidPropietario();
    string getNombreHuesped();
    int getFechaInicio();
    int getFechaFin();

};

#endif //HUESPED_RESERVAS_H
