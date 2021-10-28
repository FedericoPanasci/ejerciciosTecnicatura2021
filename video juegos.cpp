#include <iostream>

using namespace std;
#define JUEGOS 100
#define USUARIOS 1000

struct ST_USUARIO
{
    int codigo;
    string nombre;
    int fecha;
};

struct ST_VIDEOJUEGO
{
    int codigo;
    string nombre;
};

struct ST_COMBINADO
{
    int codJuego;
    int codUsuario;
};

int buscarUsuario(ST_USUARIO vector[], int cant, int codigo)
{
    int inicio = 0;
    int fin = cant - 1;
    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;
        if (vector[mitad].codigo == codigo){
            return mitad;
            }
        if (vector[mitad].codigo > codigo)
        {
            fin = mitad - 1;
        }
        else
        {
            inicio = mitad + 1;
        }
    }

    return -1;
}

void imprimir(ST_USUARIO usuario[USUARIOS], ST_VIDEOJUEGO juego[JUEGOS], ST_COMBINADO lista[100])
{
    int codJuegoKey;
    int i = 0, codUsuario, cantUsuarios = 0;
    string nombreJuegoKey;
    while (i < 100)
    {
        codJuegoKey = lista[i].codJuego;
        nombreJuegoKey = juego[codJuegoKey - 100].nombre;
        cout << "Juego: " << nombreJuegoKey << endl;
        cantUsuarios = 0;
        while (i < 100 && codJuegoKey == lista[i].codJuego)
        {
            codUsuario = lista[i].codUsuario;
            int pos = buscarUsuario(usuario, USUARIOS, codUsuario);
            cout << usuario[pos].nombre << " - " << usuario[pos].fecha << endl;
            i++;
            cantUsuarios++;
        }
        cout << "Cantidad de usuarios del juego: " << cantUsuarios << endl;
    }
}

void ordenarLista(ST_VIDEOJUEGO juego[JUEGOS])
{
    ST_VIDEOJUEGO aux;
    int i = 0;
    bool ordenado = false;
    while (i < JUEGOS - 1 && !ordenado)
    {
        ordenado = true;
        for (int j = 0; j < JUEGOS - i - 1; j++)
        {
            if (juego[j].codigo > juego[j + 1].codigo)
            {
                aux = juego[j];
                juego[j] = juego[j + 1];
                juego[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

int main()
{
    ST_USUARIO usuario[USUARIOS];
    ST_VIDEOJUEGO juego[JUEGOS];
    ST_COMBINADO lista[1000];
    ordenarLista(juego);
    imprimir(usuario, juego, lista);
    system("pause");
    return 0;
}