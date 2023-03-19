//
// Created by sebat on 19/03/2023.
//
#include "Airbnb.h"
Airbnb::Airbnb(string nombre): idPropietario(1), nombre(nombre), disponibilidad(disponibilidad) {}

void Airbnb::agregarPropietario(string nombre, string sexo, int fechaNacimiento, float puntaje) {
    propietario *pPropietario = new propietario(this->idPropietario, nombre, sexo, fechaNacimiento, puntaje);
    this->vectorPropietario.push_back(pPropietario);
    this->idPropietario++;
}
void Airbnb::agregarHuesped(string nombre, string sexo, int fechaNacimiento, float puntaje) {
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

void Airbnb::crearReserva(string nombreHuesped,int fechaInicio, int fechaFin) {
    int idReserva;
    hogar *pHogar;
    cout << "Escriba el id del propietario para crear la reserva" << endl;
    cin >> idReserva;
    auto encontrar = mapaHogar.find(idReserva);
    if (encontrar != mapaHogar.end()) {
        reservas *pReserva = new reservas(idReserva, nombreHuesped, fechaInicio, fechaFin);
        this->mapaReservas.insert(make_pair(idReserva, pReserva));
        cout << "Se creo la reserva" << endl;
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


string Airbnb::getNombre(){
    return nombre;
}