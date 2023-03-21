// Created by sebat on 17/03/2023.
#include "Airbnb.h"

void primeraOpcion(Airbnb *Propietario){
    string fechaNacimiento;
    float puntaje;
    string nombre,sexo;
    cout << "Escriba su nombre"<<endl;
    getline(cin >> std::ws, nombre);
    cout << "Cual es su genero"<<endl;
    cin >> sexo;
    cout << "Cual es su fecha de nacimiento en formato dd/mm/aa"<<endl;
    cin >> fechaNacimiento;
    cout << "Cual es su puntaje"<<endl;
    cin >> puntaje;
    Propietario->agregarPropietario(nombre,sexo,fechaNacimiento,puntaje);
}

void segundaOpcion(Airbnb *Huesped){
    string fechaNacimiento;
    float puntaje;
    string nombre,sexo;
    getline(cin >> std::ws, nombre);
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
    getline(cin >> std::ws, direccion);
    cout << "Agrege el numero de camas disponibles"<<endl;
    cin >> numCamasDispo;
    cout << "Es posible alojar bebes?"<<endl;
    cout << "1. Si"<<endl;cout << "2. No"<<endl;
    cin >> alojarBebes;
    cout << "Ponga una descripcion del lugar"<<endl;
    getline(cin >> std::ws, descripcionHogar);
    cout << "Ponga la disponibilidad del hogar"<<endl;
    cout << "1. Disponible"<<endl;cout << "2. No disponible"<<endl;
    cin >> disponibilidad;
    PropietarioHogar->agregarInfoHogar(direccion, numCamasDispo, alojarBebes, descripcionHogar,disponibilidad);
}

void quintaOpcion(Airbnb *crearReserva){
    string nombreHuesped;
    string fechaInicio, fechaFin;
    cout << "Escriba su nombre como Huesped"<<endl;
    getline(cin >> std::ws, nombreHuesped);
    cout << "Cual es la feha de inicio de su estadia en formato dd/mm/aa"<<endl;
    cin >> fechaInicio;
    cout << "Hasta que dia es su estadia en formato dd/mm/aa"<<endl;
    cin >> fechaFin;
    crearReserva->crearReserva(nombreHuesped,fechaInicio,fechaFin);
}

void OctavaOpcion(Airbnb *evaluaciones){
    string emisor, receptor, fecha, tipo;
    string comentario = "Ninguno";
    int calificacion = -1;
    int opcion, id;
    cout << "La evaluacion es para un huesped o propietario?:" << endl;
    cin >> tipo;
    cout << "Indique el nombre de la persona a quien va dirigida la evaluacion:" << endl;
    getline(cin >> std::ws, receptor);
    cout << "Indique su nombre:" << endl;
    getline(cin >> std::ws, emisor);
    cout << "Indique su id:" << endl;
    cin >> id;
    cout << "Indique del 1 al 5, la calificacion:" << endl;
    do{
        cin >> calificacion;
        if(calificacion < 1 || calificacion > 5){
            cout << "Ingrese de nuevo la calificacion:" << endl;
        }

    }while(calificacion < 1 || calificacion > 5);
    cout << "Tiene comentarios al respecto?" << endl;
    cout << "1. Si\n" << "2.No\n" << endl;
    cin >> opcion;
    if (opcion == 1){
        cout << "Ingrese su comentario:" << endl;
        getline(cin >> std::ws, comentario);
    }
    cout << "Coloque la fecha en la que realiza la evualuacion en formato dd/mm/aa:"<<endl;
    cin >> fecha;
    if(evaluaciones->cambiarCalificacionPersona(id, receptor,calificacion,tipo) == 1) {
        evaluaciones->agregarEvaluacion(calificacion, fecha, emisor, receptor, comentario);
    }
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
        cout << "8. Agregar evaluacion\n";
        cout << "9. Mostrar evaluacion\n";
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
                pAirbnb->eliminarReserva();
                break;
            case 8:
                OctavaOpcion(pAirbnb);
                break;
            case 9:
                pAirbnb->mostrarEvaluaciones();
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        }
    } while (opc != 0);
}

int main() {
    Airbnb *pAirbnb = new Airbnb("AIRBNB");

    mostrarMenu(pAirbnb);

}