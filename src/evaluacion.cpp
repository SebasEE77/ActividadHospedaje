//
// Created by sebat on 19/03/2023.
//

#include "evaluacion.h"

evaluacion::evaluacion(int fecha, int calificacion, string comentario, string personaDestino,
                       string personaDeEvaluacion): fecha(fecha), califiacion(calificacion), comentario(comentario),
                       personaDestino(personaDestino), personaDeEvaluacion(personaDeEvaluacion) {}


int evaluacion::getFecha(){
    return fecha;
}
int evaluacion::getCalificacion(){
    return califiacion;
}
string evaluacion::getComentario(){
    return comentario;
}
string evaluacion::getPersonaDestino(){
    return personaDestino;
}
string evaluacion::getPersonaEvaluacion(){
    return personaDeEvaluacion;
}