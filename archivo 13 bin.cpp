#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

typedef struct {
    int legajo;
    int codigo;
    char NomApe[26];
} ST_ALUMNO;

FILE * abrirArchivo(char * nombre, char * modo){
    FILE * archivo = fopen(nombre, modo);
    if (archivo == NULL)
    {
        EXIT_FAILURE;
    }
    return archivo;
}

void apareo(FILE * arcA,FILE * arcB,FILE * arcC){
    ST_ALUMNO alumnoA, alumnoB;

    fread(&alumnoA, sizeof(ST_ALUMNO), 1, arcA);
    fread(&alumnoB, sizeof(ST_ALUMNO), 1, arcB);
    while (!feof(arcA) && !feof(arcB))
    {
        if (alumnoA.codigo < alumnoB.codigo)
        {
            fwrite(&alumnoA, sizeof(ST_ALUMNO), 1, arcC);
            fread(&alumnoA, sizeof(ST_ALUMNO), 1, arcA);
        } else 
        {
            fwrite(&alumnoB, sizeof(ST_ALUMNO), 1, arcC);
            fread(&alumnoB, sizeof(ST_ALUMNO), 1, arcB);
        }    
    }
    while (!feof(arcA))
    {
        fwrite(&alumnoA, sizeof(ST_ALUMNO), 1, arcC);
        fread(&alumnoA, sizeof(ST_ALUMNO), 1, arcA);
    }
    while (!feof(arcB))
    {
        fwrite(&alumnoB, sizeof(ST_ALUMNO), 1, arcC);
        fread(&alumnoB, sizeof(ST_ALUMNO), 1, arcB);
    }
}

int main () {
    FILE * arcA = abrirArchivo("arcA.dat", "rb");
    FILE * arcB = abrirArchivo("arcB.dat", "rb");
    FILE * arcC = abrirArchivo("arcC.dat", "rb");

    apareo(arcA, arcB, arcC);

    fclose(arcA);
    fclose(arcB);
    fclose(arcC);
    system("pause");
    return 0;
}