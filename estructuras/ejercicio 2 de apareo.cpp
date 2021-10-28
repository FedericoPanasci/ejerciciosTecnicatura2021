#include <iostream>

using namespace std;

/*
El dueño de un local de venta de juegos para distintas consolas necesita desarrollar un algoritmo que genere un vector, JuegosPorConsola, 
ordenado por consola, con un solo registro por consola según el siguiente diseño:
- Consola (cadena)
- Cantidad de juegos (4 dígitos)

Para obtener la información solicitada se cuenta con el conjunto de datos Juegos, ordenado por código de juego con un registro por cada juego que se encuentra en el local,
 con el siguiente diseño:
- Código del juego (6 digitos)
- Stock en el local (2 digitos)
- Titulo del Juego (cadena)
- Consola (cadena)

Realizar el procedimiento que complete el vector JuegosPorConsola recibiendo el vector de Juegos
*/



struct ST_JUEGO
{
    int codigoDeJuego;
    int stock;
    string tituloDelJuego;
    string consola;
};

struct ST_CONSOLA
{
    string NombreDeConsola;
    int cantDeJuegos;
};

void cargarJuegos(ST_JUEGO juegos[], int cantidad){
    cout << "ingrese los datos de los juegos ordenados por su codigo" << endl;
    
    for (int i = 0; i < cantidad; i++)
    {
        cout <<"ingrese codigo de juego ";
        cin >> juegos[i].codigoDeJuego;
        cout << endl;
        cout <<"ingrese titulo de juego ";
        cin >> juegos[i].tituloDelJuego;
        cout << endl;
        cout <<"ingrese stock de juego ";
        cin >> juegos[i].stock;
        cout << endl;
        cout <<"ingrese consola de juego ";
        cin >> juegos[i].consola;
        cout << endl;
    }
}

/*burbujeo*/void ordenarXNombre(ST_JUEGO juego[], int cantJuegos){
    ST_JUEGO aux;
    for (int i = 0; i < cantJuegos; i++)
    {
        for (int j = 0; j < cantJuegos; j++)
        {
            if (juego[j].consola >= juego[j + 1].consola)
            {
                aux = juego[j];
                juego[j] = juego[j+1];
                juego[j + 1] = aux;
            }
        }
    }
}

void cargarJuegosXConsola(ST_JUEGO juegos[], ST_CONSOLA juegosPorConsola[], int cantidad){
    string consola;
    int i = 0;
    int cantidadDeJuegos = 0;
    int k = 0; //controla el nuevo vector
    while (i < cantidad)
    {
        consola = juegos[i].consola; //guardo el nombre x el cual quiero ordenar
        while (i < cantidad && consola == juegos[i].consola)
        {
            /* cada vez que armo un while anidado tengo que 
            agregarle la condicion anterior
            */
           cantidadDeJuegos++; //es una variable que quiero saber
           i++; //aumento i para que avance en la posicion           
        }
        juegosPorConsola[k].NombreDeConsola = consola;
        juegosPorConsola[k].cantDeJuegos = cantidadDeJuegos;
        k++;
        cantidadDeJuegos = 0; //como ya lo guarde lo reinicio para contar la siguiente variable
    }
    return;
}

int main () {
    int cantidadDeConsolas = 100, cantDeJuegos = 100;
    ST_JUEGO juego[cantDeJuegos]; 
    ST_CONSOLA juegosPorConsola[cantDeJuegos];

    //aparear(juegosPorConsola, cantidadDeConsolas, juego, cantDeJuegos, juegosPorConsola, cantDeJuegos);
    ordenarXNombre(juego, cantDeJuegos);
    cargarJuegosXConsola(juego, juegosPorConsola, 100);
    //imprimirJuegosXConsola(juegosPorConsola, 100);


    return 0;
}