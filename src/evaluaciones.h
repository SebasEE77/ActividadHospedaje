//
// Created by soray on 20/03/2023.
//

#ifndef HUESPED_EVALUACIONES_H
#define HUESPED_EVALUACIONES_H


#include <iostream>

using std::string;


class evaluaciones {
private:
    int calificacion;
    string fecha;
    string emisor;
    string receptor;
    string comentario;
public:
    evaluaciones() = default;
    evaluaciones(int calificacion, string fecha, string emisor, string receptor, string comentario);
    string getFecha();
    string getEmisor();
    string getReceptor();
    string getComentario();
    int getCalificacion();
};



#endif //HUESPED_EVALUACIONES_H
