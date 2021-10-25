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

void ordenar(ST_ALUMNO alumno, FILE * escritura){
    int pos = alumno.legajo - 80001;
    fseek(escritura, pos*sizeof(ST_ALUMNO), SEEK_SET);
    fwrite(&alumno, sizeof(ST_ALUMNO), 1, escritura);
}

int main () {
    FILE * lectura = abrirArchivo("materias.dat", "rb");
    FILE * escritura = abrirArchivo("ordenado.dat", "rb+");
    ST_ALUMNO alumno;
    
    fread(&alumno, sizeof(ST_ALUMNO), 1, lectura);
    while (!feof(lectura))
    {
        ordenar(alumno, escritura);
    }
    
    system("pause");
    return 0;
}