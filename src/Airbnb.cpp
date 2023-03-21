//
// Created by sebat on 19/03/2023.
//
#include "Airbnb.h"
Airbnb::Airbnb(string nombre): idPropietario(1), nombre(nombre), disponibilidad(disponibilidad) {}

void Airbnb::agregarPropietario(string nombre, string sexo, string fechaNacimiento, float puntaje) {
    propietario *pPropietario = new propietario(this->idPropietario, nombre, sexo, fechaNacimiento, puntaje);
    this->vectorPropietario.push_back(pPropietario);
    this->idPropietario++;
}
void Airbnb::agregarHuesped(string nombre, string sexo, string fechaNacimiento, float puntaje) {
    huesped *pHuesped =new huesped(this->idPropietario,nombre,sexo, fechaNacimiento,puntaje);
    this->vectorHuesped.push_back(pHuesped);
    this->idPropietario++;
}

void Airbnb::agregarInfoHogar(string direccion, int numCamasDispo, int alojarBebes, string descripcionHogar, int disponibilidad) {
    int id;
    cout << "Ingrese el id del propietario"<<endl;
    cin >> id;
    hogar* pHogar = new hogar(id,direccion, numCamasDispo, alojarBebes, descripcionHogar, disponibilidad);
    this->mapaHogar.insert(make_pair(id,pHogar));
}

void Airbnb::mostrarInfo() {
    vector<propietario*>::iterator itVectorPropietario;
    vector<huesped*>::iterator itVectorHuesped;
    unordered_map<int, hogar*>::iterator itMap;

    cout << "\nLista de Propietarios:\n";
    for (itVectorPropietario = this->vectorPropietario.begin(); itVectorPropietario != this->vectorPropietario.end(); ++itVectorPropietario) {
        propietario *pPropietario = *itVectorPropietario;
        cout << "Id: "<< pPropietario->getId()<< " Nombre: "<<pPropietario->getNombre()<<" Sexo: "<<pPropietario->getSexo()
             <<" Fecha de Nacimiento: "<<pPropietario->getFechaNacimiento()<<" El puntaje es: "<<pPropietario->getPuntaje()<<endl;
    }
    cout << "\nLista de Huespedes:\n";
    for (itVectorHuesped = this->vectorHuesped.begin(); itVectorHuesped != this->vectorHuesped.end(); ++itVectorHuesped) {
        huesped *pHuesped = *itVectorHuesped;
        cout << "Id: " << pHuesped->getId() << " Nombre: " << pHuesped->getNombre() << " Sexo: " << pHuesped->getSexo()
             << " Fecha de Nacimiento: " << pHuesped->getFechaNacimiento() << " El puntaje es: "
             << pHuesped->getPuntaje() <<endl;
    }
    cout << "\nLista de hogares:\n";
    for (itMap = this->mapaHogar.begin(); itMap != this->mapaHogar.end(); ++itMap){
        int llave = itMap->first;
        hogar* pHogar = itMap->second;
        cout << "El ID del propietario es: " << itMap->first << " y la direccion del lugar es: " << itMap->second->getdescripcionHogar() << endl;
    }
}

void Airbnb::crearReserva(string nombreHuesped,string fechaInicio, string fechaFin) {
    int idReserva;
    hogar *pHogar;
    cout << "Escriba el id del propietario para crear la reserva" << endl;
    cin >> idReserva;
    auto encontrar = mapaHogar.find(idReserva);
    if (encontrar != mapaHogar.end()) {
        if(mapaHogar[idReserva]->getDisponibilidad() == 1) {
            reservas *pReserva = new reservas(idReserva, nombreHuesped, fechaInicio, fechaFin);
            this->mapaReservas.insert(make_pair(idReserva, pReserva));
            cout << "Se creo la reserva" << endl;
            mapaHogar[idReserva]->setDisponibilidad(0);
        }
        else{
            cout<<"No se pudo crear la reserva" << endl;
        }
    }
}

void Airbnb::mostrarInfoReserva() {
    unordered_map<int, reservas*>::iterator itMap;
    cout << "\nLista de Reservas:\n";
    for (itMap = this->mapaReservas.begin(); itMap != this->mapaReservas.end(); ++itMap){
        int llave = itMap->first;
        reservas *pReservas = itMap->second;
        cout << "El ID del propietario es: " << itMap->first << " y el nombre del huesped: " << itMap->second->getNombreHuesped() << endl;
    }
}

void Airbnb::eliminarReserva() {
    int num;
    int numId;
    cout << "El huesped abandono el hogar?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cin >> num;
    if(num == 1){
        cout << "Escribe el id del propietario para eliminar la reserva del huesped relacionado" << endl;
        cin>> numId;
        auto encontrar = mapaReservas.find(numId);
        if(encontrar != mapaReservas.end()){
            mapaReservas.erase(encontrar);
            cout << "Se elimino la reserva" << endl;
        }else{
            cout << "No se encontro ninguna reserva con ese Id" <<endl;
        }
    }else{
        cout << "No liberaste ninguna reserva" << endl;
    }

}

void Airbnb::agregarEvaluacion(int calificacion, string fecha, string emisor, string receptor, string comentario) {
    evaluaciones *pEvaluacion = new evaluaciones(calificacion, fecha, emisor, receptor, comentario);
    this->vectorEvaluacion.push_back(pEvaluacion);
}

void Airbnb::mostrarEvaluaciones(){
    vector<evaluaciones*>::iterator itVectorEvaluacion;
    if(vectorEvaluacion.size() != 0) {
        cout << "\nLista de Evaluaciones:\n";
        for (itVectorEvaluacion = this->vectorEvaluacion.begin(); itVectorEvaluacion != this->vectorEvaluacion.end(); ++itVectorEvaluacion) {
            evaluaciones *pEvaluacion = *itVectorEvaluacion;
            cout << "De: " << pEvaluacion->getEmisor() << "----" << "Para: " << pEvaluacion->getReceptor() << endl;
            cout << "Fecha de reseña: " << pEvaluacion->getFecha() << endl;
            cout << "Comentario:" << endl;
            cout << pEvaluacion->getComentario() << endl;
            cout << "Calificacion: " << pEvaluacion->getCalificacion() << endl;
            cout << "########################################" << endl;
        }
    }
    else{
        cout << "En el sistema actualmente no se encuentra ninguna evaluacion. Intentelo luego." << endl;
    }

}

int Airbnb::cambiarCalificacionPersona(int id, string nombre, int calificacion, string tipo) {
    float nuevoPuntaje;
    int bandera = 0;
    if(tipo == "huesped" || tipo == "Huesped"){
        vector<huesped*>::iterator itVectorHuesped;
        for (itVectorHuesped = this->vectorHuesped.begin(); itVectorHuesped != this->vectorHuesped.end() && bandera == 0; ++itVectorHuesped) {
            huesped *pHuesped = *itVectorHuesped;
            if(pHuesped->getNombre() == nombre){
                nuevoPuntaje = (pHuesped->getPuntaje() + calificacion) / 2;
                pHuesped->setPuntaje(nuevoPuntaje);
                bandera = 1;
            }
        }
        if (bandera == 0){
            cout << "El huesped " << nombre << " no se encuentra en nuestro sistema" << endl;
            cout << "Por lo tanto la evaluacion no es valida!" << endl;
        }
    }
    else{
        vector<propietario*>::iterator itVectorPropietario;
        for (itVectorPropietario = this->vectorPropietario.begin(); itVectorPropietario != this->vectorPropietario.end() && bandera == 0; ++itVectorPropietario) {
            propietario *pPropietario= *itVectorPropietario;
            if(pPropietario->getNombre() == nombre){
                nuevoPuntaje = (pPropietario->getPuntaje() + calificacion) / 2;
                pPropietario->setPuntaje(nuevoPuntaje);
                bandera = 1;
            }
        }
        if (bandera == 0){
            cout << "El huesped " << nombre << " no se encuentra en nuestro sistema" << endl;
            cout << "Por lo tanto la evaluacion no es valida!" << endl;
        }
    }
    return bandera;
}


string Airbnb::getNombre(){
    return nombre;
}