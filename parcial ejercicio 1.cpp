#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

/**
 * materias
 * Código de materia ( 4 caracteres).
 * Cantidad de alumnos ( número entero). 
*/

/**
 * alumnos
 * Código de materia (4 caracteres).
 * Número de legajo del alumno (6 caracteres).
 * Nota (1 a 10) de cada alumno.
*/

typedef struct
{
    char codMateria[5];
    int cantAlumnos;
} ST_MATERIAS;

typedef struct
{
    char codMateria[5];
    char legajo[7];
    int nota;
} ST_ALUMNOS;

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


//---------------------------------------------------------
//informar la cantidad de alumnos que obtuvieron las notas del 0 al 10;
void informarNotas(int notas[11]){
    for (int i = 0; i <= 10; i++)
    {
        printf("la cantidad de alumnos con nota %d son: %d\n", i, notas[i]);
    }
    
}

void contarAlumnos(FILE * lecturaAlumnos, ST_ALUMNOS alumno){
    int notas[11] = {0};
    fread(&alumno, sizeof(ST_ALUMNOS), 1, lecturaAlumnos);
    while (!feof(lecturaAlumnos))
    {
        notas[alumno.nota-1]++;
    }
    fseek(lecturaAlumnos, 0, SEEK_SET);
    informarNotas(notas);
}
//------------------------------------------------------------


//------------------------------------------------------------
//informar al final del proceso el código de materia, el % de aprobados y el de insuficientes de cada materia.
void imprimirEstadisticas(ST_AUXILIAR auxiliar[20]){
    for (int i = 0; i < 20; i++)
    {
        if (auxiliar[i].codMateria != "")
        {
            printf("Materia: %s - Aprobados %f - Reprobados %f\n", auxiliar[i].codMateria, (float)(auxiliar[i].aprobados * 100 / auxiliar[i].cantAlumnos), (float)(auxiliar[i].desaprobados * 100 / auxiliar[i].cantAlumnos));
        }
    }
}


void estadisticasMaterias(FILE * lecturaAlumnos, FILE * lecturaMaterias){
    ST_MATERIAS materia;
    ST_ALUMNOS alumno;
    ST_AUXILIAR auxiliar[20];
    //leo las materias
    fread(&materia, sizeof(ST_MATERIAS), 1, lecturaMaterias);
    int i = 0;
    //mientras el archivo de materias no este finalizado sigo el bucle
    while (!feof(lecturaMaterias))
    {
        //copio el codigo de materia en la variable auxiliar y guardo la cantidad de alumnos total que tiene la materia
        strcpy(materia.codMateria, auxiliar[i].codMateria);
        auxiliar[i].cantAlumnos = materia.cantAlumnos;
        i++;
        fread(&materia, sizeof(ST_MATERIAS), 1, lecturaMaterias);
    }

    //leo el archivo de alumnos
    fread(&alumno, sizeof(ST_ALUMNOS), 1, lecturaAlumnos);
    while (!feof(lecturaAlumnos))
    {
        //por cada alumno leido busco el codigo de materia que le corresponde en el array auxiliar
        for (i = 0; i < 20; i++)
        {
            //cuando lo encuentro sumo un alumno a aprobados o desaprobados
            if (strcmp(alumno.codMateria, auxiliar[i].codMateria))
            {
                if (alumno.nota > 6)
                {
                    auxiliar[i].aprobados++;
                }else
                {
                    auxiliar[i].desaprobados++;
                }                
            }
        }
        fread(&alumno, sizeof(ST_ALUMNOS), 1, lecturaAlumnos);
    }
    imprimirEstadisticas(auxiliar);
}


//------------------------------------------------------------
int main () {
    FILE * lecturaMaterias = abrirArchivo("materias.dat", "rb");
    FILE * lecturaAlumnos = abrirArchivo("materias.dat", "rb");

    ST_MATERIAS materia;
    ST_ALUMNOS alumno;

    
    //informar la cantidad de alumnos que obtuvieron las notas del 0 al 10;
    contarAlumnos(lecturaAlumnos, alumno);

    //informar al final del proceso el código de materia, el % de aprobados y el de insuficientes de cada materia.
    estadisticasMaterias(lecturaAlumnos, lecturaMaterias);

    fclose(lecturaAlumnos);
    fclose(lecturaMaterias);

    system("pause");
    return 0;
}