#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

typedef struct
{
    char identificador[31];
    float peso;
    bool entrega;
    int calificacion;
} ST_ENTREGAS;

typedef struct
{
    int codigo;
    char apellido[26];
    char nombre[26];
    char fecha[11];
    float calificacion;
    int paquetes;
} ST_REPARTIDOR;

typedef struct
{
    int horas;
    int codigo;
    int dni;
} ST_DATOS;

FILE *abrirArchivo(char *nombre, char *modo)
{
    FILE *archivo = fopen(nombre, modo);
    if (archivo == NULL)
    {
        EXIT_FAILURE;
    }
    return archivo;
}

ST_ENTREGAS leer1(FILE *file)
{
    ST_ENTREGAS entrega;
    fread(&entrega, sizeof(ST_ENTREGAS), 1, file);

    return entrega;
}

ST_REPARTIDOR leer2(FILE *file)
{
    ST_REPARTIDOR repartidor;
    char buffer[255];
    if (fgets(buffer, 255, file) == NULL)
    {
        return repartidor;
    }

    repartidor.codigo = atoi(strtok(buffer, ";"));
    strcpy(repartidor.nombre, strtok(NULL, ";"));
    strcpy(repartidor.apellido, strtok(NULL, ";"));
    strcpy(repartidor.fecha, strtok(NULL, ";"));
    repartidor.calificacion = atoi(strtok(NULL, ";"));

    return repartidor;
}

void leer3(ST_ENTREGAS entrega, int dato[3])
{
    dato[0] = atoi(strtok(entrega.identificador, "-"));
    dato[1] = atoi(strtok(entrega.identificador, "-"));
    dato[2] = atoi(strtok(entrega.identificador, "-"));
}

int main()
{
    FILE *lecturaB = abrirArchivo("diarias.dat", "rb+");
    FILE *lecturaT = abrirArchivo("nomina.txt", "r");

    ST_ENTREGAS entrega;
    ST_REPARTIDOR repartidor;
    entrega = leer1(lecturaB);
    //repartidor = leer2(lecturaT);
    int datos[3];
    //ST_DATOS dato;

    //FILE * diarias = abrirArchivo("nomina2.txt" , "w");

    while (!feof(lecturaB))
    {
        leer3(entrega, datos);
        if (entrega.entrega)
        {
            fseek(lecturaT, (datos[1] - 1) * sizeof(ST_REPARTIDOR), SEEK_SET);
            int posicion = ftell(lecturaT);
            repartidor = leer2(lecturaT);
            repartidor.calificacion = (repartidor.calificacion + entrega.calificacion) / 2;
            repartidor.paquetes++;
            fseek(lecturaT, 0, posicion);
            fwrite(&repartidor, sizeof(ST_REPARTIDOR), 1, lecturaB);

            //fread(&repartidor, sizeof(ST_REPARTIDOR), 1)
        }
        else
        {
            
        }
        entrega = leer1(lecturaB);
        repartidor = leer2(lecturaT);
    }

    system("pause");
    return 0;
}