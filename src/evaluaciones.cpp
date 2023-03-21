//
// Created by soray on 20/03/2023.
//

#include "evaluaciones.h"
evaluaciones::evaluaciones(int calificacion, string fecha, string emisor, string receptor, string comentario):
        calificacion(calificacion), fecha(fecha), emisor(emisor), receptor(receptor),comentario(comentario){}

int evaluaciones::getCalificacion() {
    return calificacion;
}

string evaluaciones::getComentario() {
    return comentario;
}

string evaluaciones::getEmisor() {
    return emisor;
}

string evaluaciones::getFecha(){
    return fecha;
}

string evaluaciones::getReceptor() {
    return receptor;

