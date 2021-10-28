#include <iostream>

using namespace std;

/*
Una compañía aérea desea emitir un listado con los movimientos mensuales de sus M vuelos al exterior.
Para ello cuenta con la siguiente información. De cada vuelo realizado el número de vuelo, destino, y cantidad de
asientos. De cada pasajero el número de pasaporte y el importe que abonó por el pasaje en dólares.
La información finaliza con un número de pasaporte igual a cero. Se pide emitir el siguiente listado:

*/

int main () {
    int vuelos = 0, numeroDeVuelo = 0, cantidadDeAsientos = 0, pasaportePasajero = 0, pagoPasaje = 0, recaudacion = 0;
    string destino = "";
    
    while (numeroDeVuelo > 0)
    {
    cout << "ingrese el numero de vuelo: ";
    cin >> numeroDeVuelo;
    vuelos++;
    cout << "ingrese el destino del vuelo: ";
    cin >> destino;
    cout << "ingrese la cantidad de asientos que se vendieron siendo 100 el total: ";
    cin >> cantidadDeAsientos;


    cout << "ingrese el numero de pasaporte del pasajero (si ingresa 0 finaliza el programa): ";
    cin >> pasaportePasajero;

        while (pasaportePasajero > 0)
        {
            cout << "ingrese cuanto pago por el pasaje: ";
            cin>> pagoPasaje;
            recaudacion = recaudacion + pagoPasaje;
            cout << "ingrese otro numero de pasajero: ";
            cin >> pasaportePasajero;
        }
    cout << "ingrese otro numero de vuelo: ";
    cin >> numeroDeVuelo;
    }
    
    return 0;
}