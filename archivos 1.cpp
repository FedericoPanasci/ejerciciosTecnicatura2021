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
    FILE * archivo = abrirArchivo("2021/curso.txt", "w");
    
    int legajo = 0, nota[2] = {0,0};
    float prom = 0;
    printf("escriba el legajo: ");
    scanf("%d", &legajo);
    fflush(stdin);
    while (legajo > 0)
    {
        printf("escriba las 2 notas del alumno: ");
        scanf("%d %d", &nota[0], &nota[1]);
        prom = (float)(nota[0] + nota[1]) / 2;
        fflush(stdin);
        fprintf(archivo, "%d %.2f\n", legajo, prom);
        printf("escriba el legajo: ");
        scanf("%d", &legajo);
        fflush(stdin);
    }    
    fclose(archivo);
    system("pause");
    return 0;
}