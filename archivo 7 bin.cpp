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
    FILE * archivo = abrirArchivo("diafinales.dat", "rb");
    ST_ALUMNO alumno;
    int codigo = 0;
    printf("escribe el codigo a buscar: ");
    scanf("%d", codigo);
    FILE * guardar = abrirArchivo("matfinales.dat", "wb");
    fread(&alumno, sizeof(ST_ALUMNO), 1, archivo);
    while (!feof(archivo))
    {
        if (codigo == alumno.codigo)
        {
            fwrite(&alumno, sizeof(ST_ALUMNO), 1, guardar);
        }       
        fread(&alumno, sizeof(ST_ALUMNO), 1, archivo);
    }
    fclose(archivo);
    fclose(guardar);
    
    system("pause");
    return 0;
}