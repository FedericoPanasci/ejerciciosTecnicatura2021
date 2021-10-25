#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

typedef struct
{
    int legajo;
    char nomYApe[31];
    char docilio[21];
    int codigoPostal;
    int telefono;
    int anio;
} ST_ALUMNOS;

typedef struct
{
    int legajo;
    char nomYApe[31];
    char docilio[21];
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

ST_ALUMNOS leer1(FILE *file)
{
    ST_ALUMNOS alumno;
    char buffer[255];
    if (fgets(buffer, 255, file) == NULL)
    {
        return alumno;
    }

    alumno.legajo = atoi(strtok(buffer, "\t"));
    strcpy(alumno.nomYApe, strtok(NULL, "\t"));
    strcpy(alumno.docilio, strtok(NULL, "\t"));
    alumno.codigoPostal = atoi(strtok(NULL, "\t"));
    alumno.telefono = atoi(strtok(NULL, "\t"));
    alumno.anio = atoi(strtok(NULL, "\t"));

    return alumno;
}

ST_ALUMNOS2 leer2(FILE *file)
{
    ST_ALUMNOS2 alumno;
    char buffer[255];
    if (fgets(buffer, 255, file) == NULL)
    {
        return alumno;
    }

    alumno.legajo = atoi(strtok(buffer, "\t"));
    strcpy(alumno.nomYApe, strtok(NULL, "\t"));
    strcpy(alumno.docilio, strtok(NULL, "\t"));
    alumno.codigoPostal = atoi(strtok(NULL, "\t"));
    alumno.telefono = atoi(strtok(NULL, "\t"));
    alumno.anio = atoi(strtok(NULL, "\t"));
    strcpy(alumno.modificacion, strtok(NULL, "\t"));

    return alumno;
}

int main()
{
    FILE *lectura1 = abrirArchivo("alumnos.dat", "r");
    FILE *lectura2 = abrirArchivo("novedades.dat", "r");
    FILE *escritura = abrirArchivo("alumnosnovedades.dat", "wb");

    char alta[] = "A";         //si es alta va directamente al archivo
    char modificacion[] = "M"; //se la novedad
    char baja[] = "B";         //se saltea

    ST_ALUMNOS alumno1;
    ST_ALUMNOS2 alumno2;

    alumno1 = leer1(lectura1);
    alumno2 = leer2(lectura2);

    while (!feof(lectura1) && !feof(lectura2))
    {
        if (alumno1.legajo < alumno2.legajo)
        {
            fwrite(&alumno1, sizeof(ST_ALUMNOS), 1, escritura);
            alumno1 = leer1(lectura1);
        }
        else
        {
            if (strcmp(alumno2.modificacion, baja) == 0) //si es baja salteo
            {
                alumno1 = leer1(lectura1);
                alumno2 = leer2(lectura2);
            }
            else //cualquier otra opcion imprimo la novedad
            {
                fwrite(&alumno2, sizeof(ST_ALUMNOS2), 1, escritura);
                alumno1 = leer1(lectura1);
                alumno2 = leer2(lectura2);
            }
        }
    }

    while (!feof(lectura1))
    {
        fwrite(&alumno1, sizeof(ST_ALUMNOS), 1, escritura);
        alumno1 = leer1(lectura1);
    }

    while (!feof(lectura2))
    {
        fwrite(&alumno2, sizeof(ST_ALUMNOS2), 1, escritura);
        alumno2 = leer2(lectura2);
    }

    system("pause");
    return;
}