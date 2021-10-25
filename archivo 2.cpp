#include <iostream>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

FILE * abrirArchivo(char * nombre, char * modo){
    FILE * archivo = fopen(nombre, modo);
    if (archivo == NULL)
    {
        EXIT_FAILURE;
    }
    return archivo;
}

int main () {
    FILE * archivo = abrirArchivo("curso.txt", "r");
    FILE * escritura = abrirArchivo("2021/aprob.txt", "w");
    int legajo;
    float prom;

    fprintf(escritura, "alumnos aprobados\n");
    while (fscanf(archivo, "%d %f", &legajo, &prom) != EOF)
    {
        if (prom >= 6)
        {
            fprintf(escritura, "%d %f\n", legajo, prom);
        }
    }
    fclose(archivo);
    fclose(escritura);
    system("pause");
    return 0;
}