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
    FILE * lectura = abrirArchivo("lectura.dat", "rb");
    FILE * escritura = abrirArchivo("escritura.dat", "wb");
    ST_ALUMNO alumno;

    fread(&alumno, sizeof(ST_ALUMNO),1,lectura);
    while (!feof(lectura))
    {
        if (alumno.legajo != NULL)
        {
            fwrite(&alumno, sizeof(ST_ALUMNO),1,escritura);
        }
        fread(&alumno, sizeof(ST_ALUMNO),1,lectura);    
    }
    remove("lectura.dat");
    rename("escritura.dat", "lectura.dat");
    system("pause");
    return 0;
}