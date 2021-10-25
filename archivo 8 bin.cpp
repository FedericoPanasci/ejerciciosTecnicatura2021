#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

typedef struct {
    int legajo;
    int codigo;
    int dia; 
    int mes;
    int anio; 
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

int main () {
    FILE * lectura = abrirArchivo("finales.bin", "rb");
    FILE * escritura = abrirArchivo("listado.txt", "w");
    fprintf(escritura, "legajo\tnombre y apellido\tfecha\tcodigo de materia\n");
    ST_ALUMNO alumno;
    fread(&alumno, sizeof(ST_ALUMNO), 1, lectura);
    while (!feof(lectura))
    {
        fprintf(escritura, "%d\t%s\t%d/%d/%d\t%d\n", alumno.legajo, alumno.NomApe, alumno.dia, alumno.mes, alumno.anio, alumno.codigo);
        fread(&alumno, sizeof(ST_ALUMNO), 1, lectura);
    }
    fclose(lectura);
    fclose(escritura);
    system("pause");
    return 0;
}