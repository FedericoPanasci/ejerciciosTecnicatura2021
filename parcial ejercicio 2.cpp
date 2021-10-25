#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;
#define MAXDESTINOS 999

/**
 * destinos
 * Número de destino (3 dígitos).
 * Distancia en kilómetros (float).

viajes
Patente del camión (6 caracteres, no son más de 200 camiones).
Número de destino.
Número de chofer (1..150).


*/

typedef struct
{
    int destino;
    float distancia;
} ST_DESTINOS;

typedef struct
{
    char patente[7];
    int destino;
    int chofer;
} ST_VIAJES;

typedef struct
{
    char codMateria[5] = "";
    int aprobados = 0;
    int desaprobados = 0;
    int cantAlumnos = 0;
} ST_AUXILIAR;

FILE *abrirArchivo(char *nombre, char *modo)
{
    FILE *archivo = fopen(nombre, modo);
    if (archivo == NULL)
    {
        EXIT_FAILURE;
    }
    return archivo;
}

//--------------------------------------
//1. Cantidad de viajes realizados a cada destino
void imprimirDestinos(int auxiliar[MAXDESTINOS])
{
    for (int i = 0; i < MAXDESTINOS; i++)
    {
        //si es distinto de 0 (inicializado) se imprime en pantalla
        if (auxiliar[i] != 0)
        {
            printf("el destino %d tiene: %d\n", i + 1, auxiliar[i]);
        }
    }
}

void sumarDestinos(FILE *lecturaViajes)
{
    int auxiliar[MAXDESTINOS] = {0};
    ST_VIAJES viaje;
    fread(&viaje, sizeof(ST_VIAJES), 1, lecturaViajes);
    while (!feof(lecturaViajes))
    {
        //incremento en posicion pup de auxiliar la cantidad de viajes a un destino
        auxiliar[viaje.destino - 1]++;
        fread(&viaje, sizeof(ST_VIAJES), 1, lecturaViajes);
    }
    imprimirDestinos(auxiliar);
}
//--------------------------------------

//--------------------------------------
//2. Número de chofer con menor cantidad de km recorridos
float buscarDestino(ST_VIAJES viaje)
{
    FILE *lecturaDestino = abrirArchivo("destinos.dat", "rb");
    ST_DESTINOS destino;
    fread(&destino, sizeof(ST_DESTINOS) * viaje.destino, 1, lecturaDestino);
    fclose(lecturaDestino);
    return destino.distancia;
}

void imprimrChofer(int numeroChofer)
{
    printf("el chofer que recorrio menor distancia es: %d", numeroChofer);
}

void calcularMenorDistancia(float chofer[150])
{
    float menorDistancia = -1000;
    int numeroChofer = 0;

    for (int i = 0; i < 150; i++)
    {
        //aca se guarda el primer chofer que tenga una distancia mayor a 0
        if (menorDistancia == -1000 && chofer[i] > 0)
        {
            menorDistancia = chofer[i];
            numeroChofer = i + 1;
        }
        //si la distancia del chofer es menor guardo con su posicion
        if (chofer[i] < menorDistancia)
        {
            menorDistancia = chofer[i];
            numeroChofer = i + 1;
        }
    }
    imprimrChofer(numeroChofer);
}

void sumarKmChofer(FILE *lecturaViajes)
{
    float chofer[150] = {0};
    ST_VIAJES viaje;
    fread(&viaje, sizeof(ST_VIAJES), 1, lecturaViajes);
    while (!feof(lecturaViajes))
    {
        //obtengo la distancia del archivo destinos que tiene la informacion
        float distancia = buscarDestino(viaje);

        //la guardo en mi variable de choferes
        chofer[viaje.chofer - 1] = distancia;
        fread(&viaje, sizeof(ST_VIAJES), 1, lecturaViajes);
    }
    calcularMenorDistancia(chofer);
}
//--------------------------------------

//--------------------------------------
//3. Patente de los camiones que viajaron al destino 116 sin repeticiones de las mismas.
void imprimirPatentes(char patentes[200][7], int cant){
        printf("las patentes que viajaron al destino 116 son:\n");
    for (int i = 0; i < cant; i++)
    {
        printf("%s\n", patentes[i]);
    }
    
}

void sumarPorDestino(FILE *lectura)
{
    int cantPatentes = 0;
    char patentes[200][7] = {'\0'};
    int i = 0;
    ST_VIAJES viaje;
    fread(&viaje, sizeof(ST_VIAJES), 1, lectura);
    while (!feof(lectura))
    {
        //si el numero de destino es 116 entro al if
        if (viaje.destino == 116)
        {
            //empiezo por el principio del array inicializado en '\0', si las patentes son diferentes
            int i;
            for (i = 0; i < cantPatentes; i++)
            {
                //si lo encuentro salgo del for
                if (strcmp(viaje.patente, patentes[i]) == 0)
                {
                    return;
                }
            }
            //si no lo encuentro guardo la patente en el ultimo lugar y aumento en 1 la cantidad de patentes
            strcpy(viaje.patente, patentes[i]);
            cantPatentes++;
        }
        fread(&viaje, sizeof(ST_VIAJES), 1, lectura);
    }
    imprimirPatentes(patentes, cantPatentes);
}
//--------------------------------------

int main()
{
    //FILE * lecturaDestinos = abrirArchivo("destinos.dat", "rb");
    FILE *lecturaViajes = abrirArchivo("viajes.dat", "rb");

    //1. Cantidad de viajes realizados a cada destino
    sumarDestinos(lecturaViajes);
    fseek(lecturaViajes, 0, SEEK_SET);

    //2. Número de chofer con menor cantidad de km recorridos
    sumarKmChofer(lecturaViajes);

    //3. Patente de los camiones que viajaron al destino 116 sin repeticiones de las mismas.
    sumarPorDestino(lecturaViajes);

    system("pause");
    return 0;
}