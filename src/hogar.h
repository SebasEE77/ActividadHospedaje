//
// Created by sebat on 18/03/2023.
//

#ifndef HUESPED_HOGAR_H
#define HUESPED_HOGAR_H
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

class hogar {
private:
    int id;
    string direccion;
    int numCamasDispo;
    int alojarBebes;
    string descripcionHogar;
    int disponibilidad;
public:
    hogar() = default;
    hogar(int id, string direccion, int numCamasDispo, int alojarBebes, string descripcionHogar, int disponibilidad);


    string getDireccion();
    int getnumCamasDispos();
    int getalojarBebes();
    string getdescripcionHogar();
    int getDisponibilidad();
    void setDisponibilidad(int dispo);



};


#endif //HUESPED_HOGAR_H
