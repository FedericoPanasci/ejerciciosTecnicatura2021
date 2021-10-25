#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

typedef struct
{
    int legajo;
    char nomYApe[31];
    int docilio[21];
    int codigoPostal;
    int telefono;
    int anio;
} ST_ALUMNOS;

typedef struct
{
    int legajo;
    char nomYApe[31];
    int docilio[21];
    int codigoPostal;
    int telefono;
    int anio;
    char modificacion[];
} ST_ALUMNOS2;

FILE *abrirArchivo(char *nombre, char *modo)
{
    FILE *archivo = fopen(nombre, modo);
    if (archivo == NULL)
    {
        EXIT_FAILURE;
    }
    return archivo;
}

ST_ALUMNOS leer(FILE *file)
{
    ST_ALUMNOS episodio;
    char buffer[255];
    if (fgets(buffer, 255, file) == NULL)
    {
        return episodio;
    }

    // episodio.idSerie = atoi(strtok(buffer, ","));
    // episodio.temporada = atoi(strtok(NULL, ","));
    // episodio.cantDescargas = atoi(strtok(NULL, ","));
    // strcpy(episodio.tituloDeEpisodio, strtok(NULL, ","));
    // episodio.episodio = atoi(strtok(NULL, ","));
    // episodio.fecha = atoi(strtok(NULL, ","));

    return episodio;
}

int main()
{
    FILE *lectura1 = abrirArchivo("alumnos.dat", "rb");
    FILE *lectura2 = abrirArchivo("novedades.dat", "rb");
    FILE *escritura = abrirArchivo("alumnosnovedades.dat", "wb");

    char alta[] = "A";         //si es alta va directamente al archivo
    char modificacion[] = "M"; //se la novedad
    char baja[] = "B";         //se saltea

    ST_ALUMNOS alumno1;
    ST_ALUMNOS2 alumno2;

    fread(&alumno1, sizeof(ST_ALUMNOS), 1, lectura1);
    fread(&alumno2, sizeof(ST_ALUMNOS2), 1, lectura2);
    while (!feof(lectura1) && !feof(lectura2))
    {
        if (alumno1.legajo < alumno2.legajo)
        {
            fwrite(&alumno1, sizeof(ST_ALUMNOS), 1, escritura);
            fread(&alumno1, sizeof(ST_ALUMNOS), 1, lectura1);
        }
        else
        {
            if (strcmp(alumno2.modificacion, baja) == 0) //si es baja salteo
            {
                fread(&alumno1, sizeof(ST_ALUMNOS), 1, lectura1);
                fread(&alumno2, sizeof(ST_ALUMNOS2), 1, lectura2);
            }
            else //cualquier otra opcion imprimo la novedad
            {
                fwrite(&alumno2, sizeof(ST_ALUMNOS2), 1, escritura);
                fread(&alumno1, sizeof(ST_ALUMNOS), 1, lectura1);
                fread(&alumno2, sizeof(ST_ALUMNOS2), 1, lectura2);
            }
        }
    }

    while (!feof(lectura1))
    {
        fwrite(&alumno1, sizeof(ST_ALUMNOS), 1, escritura);
        fread(&alumno1, sizeof(ST_ALUMNOS), 1, lectura1);
    }

    while (!feof(lectura2))
    {
        fwrite(&alumno2, sizeof(ST_ALUMNOS2), 1, escritura);
        fread(&alumno2, sizeof(ST_ALUMNOS2), 1, lectura2);
    }

    system("pause");
    return 0;
}