#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

typedef struct{
    int legajo;
    int nota;
    char nombre[20];
} ALUMNO;

FILE * abrirArchivo(char * nombre, char * modo){
    FILE * archivo = fopen(nombre, modo);
    if (archivo == NULL)
    {
        EXIT_FAILURE;
    }
    return archivo;
}



int main () {
    FILE * archivo = abrirArchivo("archivo.txt", "r");
    ALUMNO alumno;
    fread(&alumno, sizeof(ALUMNO), 1, archivo);
    int leg = alumno.legajo;
    char *name= (char*)malloc(sizeof(char)*20);
    strcpy(name, alumno.nombre);
    int nota = alumno.nota;
    system("pause");
    return 0;
}