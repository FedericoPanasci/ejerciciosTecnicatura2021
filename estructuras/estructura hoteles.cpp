#include <iostream>

using namespace std;
#define CANT_HABITACIONES 60
#define CANT_DESTINOS 30
#define DESOCUPADO 'D'
#define OCUPADO 'O'

struct ST_HABITACION
{
    int numero;
    int capacidad;
    char estado;
};

struct ST_HOTEL
{
    string nombre;
    int categoria;
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

struct ST_ESTACION
{
    string nombre;
    int cantidad;
};

void llenarHabitacion(ST_DESTINO destino[], ST_HABITACION habitaciones[])
{
    int numHabitacion = 1;
    for (int j = 0; j < CANT_DESTINOS; j++)
    {

        for (int i = 0; i < CANT_HABITACIONES; i++)
        {
            if (i <= 19)
            {
                destino[j].hotel.habitaciones[i].capacidad = 2;
                destino[j].hotel.habitaciones[i].numero = numHabitacion++;
                destino[j].hotel.habitaciones[i].estado = 'D';
            }
            if (i > 19 && i <= 39)
            {
                destino[j].hotel.habitaciones[i].capacidad = 4;
                destino[j].hotel.habitaciones[i].numero = numHabitacion++;
                destino[j].hotel.habitaciones[i].estado = 'D';
            }
            if (i > 39 && i <= 59)
            {
                destino[j].hotel.habitaciones[i].capacidad = 8;
                destino[j].hotel.habitaciones[i].numero = numHabitacion++;
                destino[j].hotel.habitaciones[i].estado = 'D';
            }
        }
        numHabitacion = 1;
    }
}

void llenarDestino(ST_DESTINO destino[])
{
    destino[0].nombre = "milan";
    destino[0].pais = "italia";
    destino[0].descripcion = " ";
    destino[0].temporada = 'V';
    destino[0].hotel.nombre = "Borgo Egnazia";
    destino[0].hotel.categoria = 4;
    destino[1].nombre = "mendoza";
    destino[1].pais = "argentina";
    destino[1].descripcion = " ";
    destino[1].temporada = 'V';
    destino[1].hotel.nombre = "vinedo";
    destino[1].hotel.categoria = 4;
    destino[2].nombre = "santiago";
    destino[2].pais = "chile";
    destino[2].descripcion = " ";
    destino[2].temporada = 'I';
    destino[2].hotel.nombre = "santiago";
    destino[2].hotel.categoria = 3;
    destino[3].nombre = "medellin";
    destino[3].pais = "colombia";
    destino[3].descripcion = " ";
    destino[3].temporada = 'V';
    destino[3].hotel.nombre = "capitolio";
    destino[3].hotel.categoria = 3;
    destino[4].nombre = "paz";
    destino[4].pais = "bolivia";
    destino[4].descripcion = " ";
    destino[4].temporada = 'I';
    destino[4].hotel.nombre = "pacifico";
    destino[4].hotel.categoria = 2;
    destino[5].nombre = "machu";
    destino[5].pais = "peru";
    destino[5].descripcion = " ";
    destino[5].temporada = 'I';
    destino[5].hotel.nombre = "machupichu";
    destino[5].hotel.categoria = 4;
    destino[6].nombre = "ticos";
    destino[6].pais = "costaRica";
    destino[6].descripcion = " ";
    destino[6].temporada = 'V';
    destino[6].hotel.nombre = "tiqueros";
    destino[6].hotel.categoria = 5;
    destino[7].nombre = "havana";
    destino[7].pais = "cuba";
    destino[7].descripcion = " ";
    destino[7].temporada = 'V';
    destino[7].hotel.nombre = "cubano5";
    destino[7].hotel.categoria = 2;
    destino[8].nombre = "guatelco";
    destino[8].pais = "guatemala";
    destino[8].descripcion = " ";
    destino[8].temporada = 'V';
    destino[8].hotel.nombre = "caluroso";
    destino[8].hotel.categoria = 4;
    destino[9].nombre = "quito";
    destino[9].pais = "ecuador";
    destino[9].descripcion = " ";
    destino[9].temporada = 'I';
    destino[9].hotel.nombre = "mitadDelMundo";
    destino[9].hotel.categoria = 3;
    destino[10].nombre = "hondu";
    destino[10].pais = "honduras";
    destino[10].descripcion = " ";
    destino[10].temporada = 'I';
    destino[10].hotel.nombre = "hondureño3";
    destino[10].hotel.categoria = 2;
    destino[11].nombre = "cancun";
    destino[11].pais = "mexico";
    destino[11].descripcion = " ";
    destino[11].temporada = 'V';
    destino[11].hotel.nombre = "palassium";
    destino[11].hotel.categoria = 5;
    destino[12].nombre = "clasico";
    destino[12].pais = "puertoRico";
    destino[12].descripcion = " ";
    destino[12].temporada = 'V';
    destino[12].hotel.nombre = "laPerla";
    destino[12].hotel.categoria = 4;
    destino[13].nombre = "texano";
    destino[13].pais = "eeuu";
    destino[13].descripcion = " ";
    destino[13].temporada = 'I';
    destino[13].hotel.nombre = "reyes";
    destino[13].hotel.categoria = 3;
    destino[14].nombre = "costero";
    destino[14].pais = "portugal";
    destino[14].descripcion = " ";
    destino[14].temporada = 'I';
    destino[14].hotel.nombre = "portuario";
    destino[14].hotel.categoria = 3;
    destino[15].nombre = "laFrance";
    destino[15].pais = "francia";
    destino[15].descripcion = " ";
    destino[15].temporada = 'I';
    destino[15].hotel.nombre = "vasilique";
    destino[15].hotel.categoria = 5;
    destino[16].nombre = "papal";
    destino[16].pais = "vaticano";
    destino[16].descripcion = " ";
    destino[16].temporada = 'I';
    destino[16].hotel.nombre = "francisco2";
    destino[16].hotel.categoria = 5;
    destino[17].nombre = "alpes";
    destino[17].pais = "austria";
    destino[17].descripcion = " ";
    destino[17].temporada = 'I';
    destino[17].hotel.nombre = "altisimo";
    destino[17].hotel.categoria = 4;
    destino[18].nombre = "berlin";
    destino[18].pais = "alemania";
    destino[18].descripcion = " ";
    destino[18].temporada = 'I';
    destino[18].hotel.nombre = "oktober";
    destino[18].hotel.categoria = 3;
    destino[19].nombre = "manaos";
    destino[19].pais = "brasil";
    destino[19].descripcion = " ";
    destino[19].temporada = 'V';
    destino[19].hotel.nombre = "brasileirao";
    destino[19].hotel.categoria = 3;
    destino[20].nombre = "caracas";
    destino[20].pais = "venezuela";
    destino[20].descripcion = " ";
    destino[20].temporada = 'V';
    destino[20].hotel.nombre = "pacifico";
    destino[20].hotel.categoria = 4;
    destino[21].nombre = "wuhan";
    destino[21].pais = "china";
    destino[21].descripcion = " ";
    destino[21].temporada = 'I';
    destino[21].hotel.nombre = "buenosDias";
    destino[21].hotel.categoria = 4;
    destino[22].nombre = "tokio";
    destino[22].pais = "japon";
    destino[22].descripcion = " ";
    destino[22].temporada = 'I';
    destino[22].hotel.nombre = "tokitoki";
    destino[22].hotel.categoria = 3;
    destino[23].nombre = "serena";
    destino[23].pais = "tanzania";
    destino[23].descripcion = " ";
    destino[23].temporada = 'I';
    destino[23].hotel.nombre = "demonio";
    destino[23].hotel.categoria = 3;
    destino[24].nombre = "santorini";
    destino[24].pais = "grecia";
    destino[24].descripcion = " ";
    destino[24].temporada = 'I';
    destino[24].hotel.nombre = "katikies";
    destino[24].hotel.categoria = 4;
    destino[25].nombre = "toronto";
    destino[25].pais = "canada";
    destino[25].descripcion = " ";
    destino[25].temporada = 'I';
    destino[25].hotel.nombre = "capitalino";
    destino[25].hotel.categoria = 5;
    destino[26].nombre = "sidney";
    destino[26].pais = "australia";
    destino[26].descripcion = " ";
    destino[26].temporada = 'I';
    destino[26].hotel.nombre = "sidney";
    destino[26].hotel.categoria = 3;
    destino[27].nombre = "manchester";
    destino[27].pais = "inglaterra";
    destino[27].descripcion = " ";
    destino[27].temporada = 'I';
    destino[27].hotel.nombre = "united";
    destino[27].hotel.categoria = 5;
    destino[28].nombre = "bali";
    destino[28].pais = "indonesia";
    destino[28].descripcion = " ";
    destino[28].temporada = 'I';
    destino[28].hotel.nombre = "resort";
    destino[28].hotel.categoria = 5;
    destino[29].nombre = "matetsi";
    destino[29].pais = "zimbabwe";
    destino[29].descripcion = " ";
    destino[29].temporada = 'V';
    destino[29].hotel.nombre = "super";
    destino[29].hotel.categoria = 4;
}

void desocuparHabitacion(ST_DESTINO destino[], ST_HABITACION habitacion[], string lugar, int numHabitacion, int cantPasajeros, int posicionDestino)
{
    if (numHabitacion < 20)
    {
        destino[posicionDestino].hotel.habitaciones[numHabitacion - 1].capacidad = 2;
        destino[posicionDestino].hotel.habitaciones[numHabitacion - 1].estado = DESOCUPADO;
    }
    if (numHabitacion >= 20 && numHabitacion < 40)
    {
        destino[posicionDestino].hotel.habitaciones[numHabitacion - 1].capacidad = 4;
        destino[posicionDestino].hotel.habitaciones[numHabitacion - 1].estado = DESOCUPADO;
    }
    if (numHabitacion >= 40 && numHabitacion <= 60)
    {
        destino[posicionDestino].hotel.habitaciones[numHabitacion - 1].capacidad = 8;
        destino[posicionDestino].hotel.habitaciones[numHabitacion - 1].estado = DESOCUPADO;
    }
    cout << destino[posicionDestino].hotel.nombre << " fue desocupado en su habitacion " << destino[posicionDestino].hotel.habitaciones[numHabitacion - 1].numero << " y ahora cuenta con una capacidad de " << destino[posicionDestino].hotel.habitaciones[numHabitacion - 1].capacidad << " pasajeros." << endl;
}

void ocuparHabitacion(ST_DESTINO destino[], ST_HABITACION habitacion[], int cantPasajeros, int posicion)
{
    int i = 0;
    int habitacionesOcupadas = 0;
    if (cantPasajeros < 3)
    {
        while (habitacionesOcupadas < 1 && i <= 19)
        {
            if (destino[posicion].hotel.habitaciones[i].estado == DESOCUPADO)
            {
                destino[posicion].hotel.habitaciones[i].estado = OCUPADO;
                destino[posicion].hotel.habitaciones[i].capacidad = destino[posicion].hotel.habitaciones[i].capacidad - cantPasajeros;
                habitacionesOcupadas++;
                cout << destino[posicion].hotel.nombre << " fue ocupado en su habitacion " << destino[posicion].hotel.habitaciones[i].numero << " con " << cantPasajeros << " pasajeros." << endl;
            }
            else
            {
                i++;
            }
        }
    }
    i = 19;
    if (cantPasajeros < 5)
    {
        while (habitacionesOcupadas < 1 && i <= 39)
        {
            if (destino[posicion].hotel.habitaciones[i].estado == DESOCUPADO)
            {
                destino[posicion].hotel.habitaciones[i].estado = OCUPADO;
                destino[posicion].hotel.habitaciones[i].capacidad = destino[posicion].hotel.habitaciones[i].capacidad - cantPasajeros;
                habitacionesOcupadas++;
                cout << destino[posicion].hotel.nombre << " fue ocupado en su habitacion " << destino[posicion].hotel.habitaciones[i].numero << " con " << cantPasajeros << " pasajeros." << endl;
            }
            else
            {
                i++;
            }
        }
    }
    i = 39;
    if (cantPasajeros < 9)
    {
        while (habitacionesOcupadas < 1 && i <= 59)
        {
            if (destino[posicion].hotel.habitaciones[i].estado == DESOCUPADO)
            {
                destino[posicion].hotel.habitaciones[i].estado = OCUPADO;
                destino[posicion].hotel.habitaciones[i].capacidad = destino[posicion].hotel.habitaciones[i].capacidad - cantPasajeros;
                habitacionesOcupadas++;
                cout << destino[posicion].hotel.nombre << " fue ocupado en su habitacion " << destino[posicion].hotel.habitaciones[i].numero << " con " << cantPasajeros << " pasajeros." << endl;
            }
            else
            {
                i++;
            }
        }
    }
}

void buscarDestino(ST_DESTINO destino[], ST_HABITACION habitacion[], string lugar, int cantPasajeros, int accion, int numHabitacion)
{
    int inicio = 0;
    int fin = CANT_DESTINOS - 1;
    int mitad = 0;
    while (fin >= inicio)
    {
        mitad = inicio + (fin - inicio) / 2;

        if (destino[mitad].nombre == lugar)
        {
            if (accion < 2)
            {
                ocuparHabitacion(destino, habitacion, cantPasajeros, mitad);
            }
            else
            {
                desocuparHabitacion(destino, habitacion, lugar, numHabitacion, cantPasajeros, mitad);
            }
        }
        if (destino[mitad].nombre > lugar)
        {
            fin = mitad - 1;
        }
        else
        {
            inicio = mitad + 1;
        }
    }
}

void imprimirDestinos(ST_DESTINO destino[])
{
    cout << "##### los destinos a los que puede viajar son: #######" << endl;
    for (int i = 0; i < CANT_DESTINOS; i++)
    {
        cout << destino[i].nombre << endl;
    }
}

void ordenarXDestino(ST_DESTINO destino[], int limite)
{
    int i, j;
    ST_DESTINO aux;
    for (i = 0; i < limite - 1; i++)
    {
        for (j = 0; j < limite - i - 1; j++)
        {
            if (destino[j].nombre > destino[j + 1].nombre)
            {
                aux = destino[j];
                destino[j] = destino[j + 1];
                destino[j + 1] = aux;
            }
        }
    }
}

void imprimirEstacion(ST_ESTACION estacion[])
{
    cout << "los destinos mas concurridos de la estacion seleccionada son: ";
    cout << estacion[0].nombre << ", " << estacion[1].nombre << " y " << estacion[2].nombre;
    cout << endl;
}

void ordenarEstaciones(ST_ESTACION estacion[])
{
    ST_ESTACION aux;
    int j;
    int i = 0;
    bool ordenado = false;
    while (i < CANT_DESTINOS && !ordenado)
    {
        ordenado = true;
        for (j = 0; j < CANT_DESTINOS - i - 1; j++)
        {
            if (estacion[j].cantidad < estacion[j + 1].cantidad)
            {
                aux = estacion[j];
                estacion[j] = estacion[j + 1];
                estacion[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
    imprimirEstacion(estacion);
}

void inicializarEstacion(ST_ESTACION estacion[])
{
    for (int i = 0; i < CANT_DESTINOS; i++)
    {
        estacion[i].nombre = " ";
        estacion[i].cantidad = 0;
    }
}

void buscarEstacion(ST_DESTINO destino[], ST_HABITACION habitacion[], char estacion)
{
    ST_ESTACION estaciones[CANT_DESTINOS];
    inicializarEstacion(estaciones);
    int e = 0;
    int i = 0;
    int j = 0;
    while (i < CANT_DESTINOS)
    {
        if (destino[i].temporada == estacion)
        {
            estaciones[e].nombre = destino[i].nombre;
            while (j < CANT_HABITACIONES)
            {
                if (destino[i].hotel.habitaciones[j].estado == OCUPADO)
                {
                    estaciones[e].cantidad = estaciones[e].cantidad + 1;
                    j++;
                }
                j++;
            }
            e++;
            i++;
            j = 0;
        }
        else
        {
            i++;
        }
    }
    ordenarEstaciones(estaciones);
}

int main()
{
    ST_DESTINO destino[CANT_DESTINOS];
    ST_HOTEL hotel[CANT_DESTINOS];
    ST_HABITACION habitaciones[CANT_HABITACIONES];
    llenarDestino(destino);
    llenarHabitacion(destino, habitaciones);
    ordenarXDestino(destino, CANT_DESTINOS);
    string lugar = " ";
    int cantPasajeros = 0;
    int habitacionOcupada = 0;
    int accion = 0;
    cout << " ingrese el numero de la opcion que desea realizar?" << endl;
    cout << " 1 ocupar." << endl;
    cout << " 2 desocupar." << endl;
    cout << " 3 conocer ocupacion de una temporada" << endl;
    cout << " 4 finalizar programa." << endl;
    cin >> accion;
    string estacion = " ";
    while (accion < 4)
    {
        switch (accion)
        {
        case 1:
        {
            imprimirDestinos(destino);
            cout << "a que lugar desea viajar? ";
            cin >> lugar;
            cout << "cuantas personas ocuparan la habitacion? ";
            cin >> cantPasajeros;
            buscarDestino(destino, habitaciones, lugar, cantPasajeros, accion, 0);
        }
        break;
        case 2:
        {
            imprimirDestinos(destino);
            cout << "a que lugar viajo? ";
            cin >> lugar;
            cout << "que habitacion ocuparon? ";
            cin >> habitacionOcupada;
            buscarDestino(destino, habitaciones, lugar, 0, accion, habitacionOcupada);
        }
        break;
        case 3:
            cout << "de que temporada quiere conocer su capacidad? (invierno o verano) " << endl;
            cin >> estacion;
            if (estacion == "verano")
            {
                char estacionChar = 'V';
                buscarEstacion(destino, habitaciones, estacionChar);
            }
            else
            {
                char estacionChar = 'I';
                buscarEstacion(destino, habitaciones, estacionChar);
            }
            break;
        }
        ordenarXDestino(destino, CANT_DESTINOS);
        cout << "#############################" << endl;
        cout << " ingrese el numero de la opcion que desea realizar?" << endl;
        cout << " 1 ocupar." << endl;
        cout << " 2 desocupar." << endl;
        cout << " 3 conocer ocupacion de una temporada" << endl;
        cout << " 4 finalizar programa." << endl;
        cin >> accion;
    }
    cout << "programa finalizado." << endl;

    system("pause");
    return 0;
}