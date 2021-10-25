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
    FILE * archivo = abrirArchivo("diafinales.dat", "ab+");
    ST_ALUMNO alumno;
    
    printf("nombre y apellido del alumno: (nulo para terminar) ");
    fgets(alumno.NomApe, 26, stdin);
    while (strcmp(alumno.NomApe, "nulo\n"))
    {
        printf("legajo del alumno: ");
        scanf("%d", &alumno.legajo);
        fflush(stdin);
        printf("codigo de materia: ");
        scanf("%d", &alumno.codigo);
        fflush(stdin);
        printf("dia del examen: ");
        scanf("%d", &alumno.dia);
        fflush(stdin);
        printf("mes del examen: ");
        scanf("%d", &alumno.mes);
        fflush(stdin);
        printf("anio del examen: ");
        scanf("%d", &alumno.anio);
        fflush(stdin);

        fwrite(&alumno, sizeof(ST_ALUMNO), 1, archivo);

        printf("nombre y apellido del alumno: (nulo para terminar) ");
        fgets(alumno.NomApe, 26, stdin);        
    }
    fclose(archivo);
    
    system("pause");
    return 0;
}