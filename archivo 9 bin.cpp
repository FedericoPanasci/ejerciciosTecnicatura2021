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

int posicion(FILE * file){
    int i = ftell(file)/sizeof(ST_ALUMNO);
    return i;
}

void escribir(FILE * escritura, FILE * lectura){
    ST_ALUMNO alumno;
    fread(&alumno, sizeof(ST_ALUMNO), 1, lectura);
    while (!feof(lectura))
    {
        fwrite(&alumno, sizeof(ST_ALUMNO), 1, escritura);
        fread(&alumno, sizeof(ST_ALUMNO), 1, lectura);
    }
}

void imprimir(FILE * lec, int pos){
    ST_ALUMNO alumno;
    fseek(lec, 0, pos*sizeof(ST_ALUMNO));
    fread(&alumno, sizeof(ST_ALUMNO), 1, lec);
    while (!feof(lec))
    {
        printf("%d\t%d\t%d\t%d\t%d\t%s", alumno.legajo, alumno.dia, alumno.mes, alumno.anio, alumno.codigo, alumno.NomApe);
        fread(&alumno, sizeof(ST_ALUMNO), 1, lec);
    }
}

int main () {
    FILE * apen = abrirArchivo("diafinales.dat", "ab");
    FILE * lectura = abrirArchivo("matfinales.dat", "rb");
    int pos = posicion(apen);

    escribir(apen, lectura);
    imprimir(apen, pos);

    system("pause");
    return 0;
}