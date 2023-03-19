//
// Created by sebat on 19/03/2023.
//

#ifndef HUESPED_EVALUACION_H
#define HUESPED_EVALUACION_H
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



class evaluacion {
private:
    int fecha;
    int califiacion;
    string comentario;
    string personaDestino;
    string personaDeEvaluacion;
public:
    evaluacion() = default;
    evaluacion(int fecha,int calificacion, string comentario,string personaDestino, string personaDeEvaluacion);

    int getFecha();
    int getCalificacion();
    string getComentario();
    string getPersonaDestino();
    string getPersonaEvaluacion();

};


#endif //HUESPED_EVALUACION_H
