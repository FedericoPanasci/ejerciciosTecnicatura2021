#include <iostream>

using namespace std;

#define CANT_JUEGOS 100
#define RANGO_MIN 100
#define RANGO_MAX 200
#define CANT_USUARIOS 1000

struct ST_JUEGOS
{
    int codigo;
    string nombre;
};

struct ST_USUARIO
{
    int codigo;
    string nombre;
    int fechaRegistro;
};

struct ST_RELACION
{
    int codigoJuego[CANT_JUEGOS];
    int codigoUsuario[CANT_USUARIOS];
};

void imprimirListado(ST_JUEGOS juegos[], ST_USUARIO jugadores[], ST_RELACION relacion[])
{

    int i = 0;
    int cantJugadores = 0;
    int key;
    int j = 0;

    while (i < CANT_JUEGOS)
    {

        key = juegos[i].codigo;

        cout << "nombre del juego: " << juegos[i/*codigo - 100*/].nombre << endl; 

        while (i < CANT_JUEGOS && key == juegos[i].codigo)
        {
            if (juegos[i].codigo == relacion[j].codigoJuego) //profe me figura el error "los tipos de operando no son compatibles int y int *"
            {
                if (jugadores[i].codigo == relacion[j].codigoUsuario) //aca me pasa el mismo error
                {
                    cout << jugadores[i].nombre << " - " << jugadores[i].fechaRegistro << endl; 
                    cantJugadores++;
                }
                j++;
            }
            j = 0;
            cout << "cantidad total de usuarios del juego: " << cantJugadores << endl;
            cantJugadores = 0;
        }
        i++; 
    }
}

void ordenarJuegos(ST_JUEGOS juegos[])
{
    ST_JUEGOS aux;
    int i = 0;
    bool ordenado = false;
    while (i < CANT_JUEGOS - 1 && !ordenado)
    {
        ordenado = true;

        for (int j = 0; j < CANT_JUEGOS - i - 1; j++)
        {
            if (juegos[j].nombre > juegos[j + 1].nombre)
            {
                aux = juegos[j];
                juegos[j] = juegos[j + 1];
                juegos[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

int main()
{
    ST_JUEGOS juegos[CANT_JUEGOS];
    ST_USUARIO jugadores[CANT_USUARIOS];
    ST_RELACION relacion[RANGO_MAX];
    ordenarJuegos(juegos);
    imprimirListado(juegos, jugadores, relacion);

    return 0;
}