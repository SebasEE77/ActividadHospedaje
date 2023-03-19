// Created by sebat on 17/03/2023.
#include "Airbnb.h"

void primeraOpcion(Airbnb *Propietario){
    int fechaNacimiento;
    float puntaje;
    string nombre,sexo;
    cout << "Escriba su nombre"<<endl;
    cin >> nombre;
    cout << "Cual es su genero"<<endl;
    cin >> sexo;
    cout << "Cual es su fecha de nacimiento"<<endl;
    cin >> fechaNacimiento;
    cout << "Cual es su puntaje"<<endl;
    cin >> puntaje;
    Propietario->agregarPropietario(nombre,sexo,fechaNacimiento,puntaje);
}

void segundaOpcion(Airbnb *Huesped){
    int fechaNacimiento;
    float puntaje;
    string nombre,sexo;
    cout << "Escriba su nombre"<<endl;
    cin >> nombre;
    cout << "Cual es su genero"<<endl;
    cin >> sexo;
    cout << "Cual es su fecha de nacimiento"<<endl;
    cin >> fechaNacimiento;
    cout << "Cual es su puntaje"<<endl;
    cin >> puntaje;
    Huesped->agregarHuesped(nombre,sexo,fechaNacimiento,puntaje);
}

void terceraOpcion(Airbnb *PropietarioHogar){
    string direccion,descripcionHogar;
    int numCamasDispo, alojarBebes,disponibilidad;
    cout << "Agrege la direccion del lugar"<<endl;
    cin >> direccion;
    cout << "Agrege el numero de camas disponibles"<<endl;
    cin >> numCamasDispo;
    cout << "Es posible alojar bebes?"<<endl;
    cout << "1. Si"<<endl;cout << "2. No"<<endl;
    cin >> alojarBebes;
    cout << "Ponga una descripcion del lugar"<<endl;
    cin >> descripcionHogar;
    cout << "Ponga la disponibilidad del hogar"<<endl;
    cout << "1. Disponible"<<endl;cout << "2. No disponible"<<endl;
    cin >> disponibilidad;
    PropietarioHogar->agregarInfoHogar(direccion, numCamasDispo, alojarBebes, descripcionHogar,disponibilidad);
}

void quintaOpcion(Airbnb *crearReserva){
    string nombreHuesped;
    int fechaInicio, fechaFin;
    cout << "Escriba su nombre como Huesped"<<endl;
    cin >> nombreHuesped;
    cout << "Cual es la feha de inicio de su estadia"<<endl;
    cin >> fechaInicio;
    cout << "Hasta que dia es su estadia"<<endl;
    cin >> fechaFin;
    crearReserva->crearReserva(nombreHuesped,fechaInicio,fechaFin);
}

void mostrarMenu(Airbnb *pAirbnb) {
    int opc = 0;
    do
    {
        cout << "\n**** Bienvenido al sistema de Propietarios ****\n";
        cout << "1. Iniciar Sesion Propietario\n";
        cout << "2. Iniciar Sesion Huespedes\n";
        cout << "3. Agregar informacion del hogar Propietario\n";
        cout << "4. Personas inscritas en el sistema\n";
        cout << "5. Crear Reserva\n";
        cout << "6. Mostrar Reservas\n";
        cout << "7. Liberar Reservas\n";
        cout << "0. Salir\n" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                primeraOpcion(pAirbnb);
                break;
            case 2:
                segundaOpcion(pAirbnb);
                break;
            case 3:
                terceraOpcion(pAirbnb);
                break;
            case 4:
                pAirbnb->mostrarInfo();
                break;
            case 5:
                quintaOpcion(pAirbnb);
                break;
            case 6:
                pAirbnb->mostrarInfoReserva();
                break;
            case 7:
                break;
            default:
                break;
        }
    } while (opc != 0);
}

int main() {
    Airbnb *pAirbnb = new Airbnb("AIRBNB");

    mostrarMenu(pAirbnb);

}