#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

typedef struct{
    int id;
    char titulo[21];
    char genero[11];

} ST_SERIES;

FILE * abrirArchivo(char * nombre, char * modo){
    FILE * archivo = fopen(nombre, modo);
    if (archivo == NULL)
    {
        EXIT_FAILURE;
    }
    return archivo;
}

void apareo(FILE * fileA,FILE * fileB,FILE * fileC){
    ST_SERIES serieA;
    ST_SERIES serieB;
    fread(&serieA,sizeof(ST_SERIES),1,fileA);
    fread(&serieB,sizeof(ST_SERIES),1,fileB);
    while (!feof(fileA) && !feof(fileB))
    {
        if (serieA.id < serieB.id)
        {
            fwrite(&serieA, sizeof(ST_SERIES), 1, fileC);
            fread(&serieA,sizeof(ST_SERIES),1,fileA);

        }
        else
        {
            fwrite(&serieB, sizeof(ST_SERIES), 1, fileC);
            fread(&serieB,sizeof(ST_SERIES),1,fileB);
        }
    }
    while (!feof(fileA))
    {
        fwrite(&serieA, sizeof(ST_SERIES), 1, fileC);
        fread(&serieA,sizeof(ST_SERIES),1,fileA);
    }
    while (!feof(fileB))
    {
        fwrite(&serieB, sizeof(ST_SERIES), 1, fileC);
        fread(&serieB,sizeof(ST_SERIES),1,fileB);
    }
}

int main () {
    FILE * viejo = abrirArchivo("series.dat", "rb");
    FILE * nuevo = abrirArchivo("novSeries.dat", "rb");
    FILE * actualizado = abrirArchivo("actSeries.dat", "wb");

    apareo(viejo, nuevo, actualizado);

    fclose(viejo);
    fclose(nuevo);
    fclose(actualizado);

    system("pause");
    return 0;
}