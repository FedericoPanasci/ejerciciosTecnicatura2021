#include <iostream>

using namespace std;

#define CANT_DESTINOS 30
#define CANT_HABITACIONES 60
#define CANT_HOTELES 60

struct ST_HABITACION
{
    int numero;
    int capacidad;
    char estado;
};

struct ST_HOTEL
{
    string nombre;
    short int categoria;
    ST_HABITACION habitaciones[CANT_HABITACIONES];
};

struct ST_DESTINO
{
    string nombre;
    string descripcion;
    string pais;
    char temporada;
    ST_HOTEL hotel;
};

void ordenarXDestino(ST_DESTINO nombre[CANT_DESTINOS], int cantidad)
{
    int i = 0, j = 0;
    string aux;
    bool ordenado = false;
    while (i < CANT_DESTINOS && !ordenado)
    {
        ordenado = true; // Arranco asumiendo que si esta ordenado
        // Los ultimos i elementos ya estan ordenados
        for (j = 0; j < CANT_DESTINOS - i - 1; j++)
        {
            if (nombre[j].nombre > nombre[j + 1].nombre)
            {
                aux = nombre[j].nombre;
                nombre[j].nombre = nombre[j + 1].nombre;
                nombre[j + 1].nombre = aux;
                ordenado = false; // Cambio el flag si hice un swap
            }
        }
        i++;
    }
}

void indicarDestino(string &destino, int &cantidad)
{
    cout << "indique el destinto: ";
    cin >> destino;
    cout << "indique la cantidad de pasajeros: ";
    cin >> cantidad;
    return;
}
int buscarHabitacion(ST_DESTINO nombre[CANT_DESTINOS], ST_HABITACION numero[CANT_HABITACIONES], string destino, int cantidad, string accion)
{
    // Cuando arranco evalúo todo el vector de 0 a n - 1
    int inicio = 0;
    int fin = CANT_DESTINOS - 1;
    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;
        // Si el elemento es el del medio, devolvemos la posicion
        if (nombre[mitad].nombre == destino)
            return mitad;
        // Si el elemento es menor entonces solo puede estar en la primer mitad
        if (nombre[mitad].nombre > destino)
        {
            fin = mitad - 1; //Cambio el limite superior
        }
        else
        {
            inicio = mitad + 1; // Cambio el limite inferior
        }
    }
    // Si llegamos hasta aca es que el elemento no estaba
    return -1;
}

void ocuparDesocupar(ST_DESTINO nombre[CANT_DESTINOS], ST_HOTEL nombreHotel[CANT_HOTELES], int destino, int cantidadPas, string accion){
    if (accion == "ocupar")
    {
        if (nombreHotel[destino].habitaciones.capacidad >= cantidadPas)
        {
        nombre[destino].hotel.habitacion.estado = 'o';
        cout << "su habitacion es: " << nombre[destino].hotel.habitacion.numero + 1 << endl;
        cout << nombre[destino].nombre << endl;
        }
        
    }
    else
    {
        nombre[destino].hotel.habitacion.estado = 'd';
    }
   return; 
}
int main()
{
    ST_DESTINO nombre[CANT_DESTINOS];
    ST_HABITACION numero[CANT_HABITACIONES];
    ST_HOTEL nombreHotel[CANT_HOTELES];
    ordenarXDestino(nombre, CANT_DESTINOS);
    string destinoPasajero;
    int cantidadPasajeros;
    string accion;
    cout << "que accion va a realizar (ocupar o desocupar habitacion)? ";
    cin >> accion;
    if (accion == "ocupar")
    {
        indicarDestino(destinoPasajero, cantidadPasajeros);
        int posicion = buscarHabitacion(nombre, nombreHotel, numero, destinoPasajero, cantidadPasajeros, accion);
        ocuparDesocupar(nombre, posicion, cantidadPasajeros, accion);
    }
    else
    {
        indicarDestino(destinoPasajero, cantidadPasajeros);
        int posicion = buscarHabitacion(nombre, numero, destinoPasajero, cantidadPasajeros, accion);
        ocuparDesocupar(nombre, posicion, cantidadPasajeros, accion);
    }

    system("pause");
    return 0;
}