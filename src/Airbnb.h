//
// Created by sebat on 19/03/2023.
//

#ifndef HUESPED_AIRBNB_H
#define HUESPED_AIRBNB_H
#include <iostream>
#include <vector>
#include "huesped.h"
#include "hogar.h"
#include <unordered_map>
#include <algorithm>
#include "reservas.h"
#include "evaluacion.h"


using std::cout;
using std::string;
using std::endl;
using std::iterator;
using std::cin;
using std::unordered_map;
using std::make_pair;
using std::vector;

class Airbnb {
    int idPropietario;
    int disponibilidad;
    string nombre;
    unordered_map<int, hogar*> mapaHogar;
    unordered_map<int, reservas*> mapaReservas;
    vector<propietario*> vectorPropietario;
    vector<huesped*> vectorHuesped;
    vector<evaluacion*>vectorEvaluacion;


public:
    Airbnb() = default;
    Airbnb(string nombre);
    void agregarInfoHogar(string direccion, int numCamasDispo, int alojarBebes, string descripcionHogar, int disponibilidad);
    void mostrarInfo();
    void agregarPropietario(string nombre, string sexo, int fechaNacimiento, float puntaje);
    void agregarHuesped(string nombre, string sexo, int fechaNacimiento, float puntaje);
    void crearReserva(string nombreHuesped,int fechaInicio, int fechaFin);
    void mostrarInfoReserva();
    void eliminarReserva();

    string getNombre();

};


#endif //HUESPED_AIRBNB_H
