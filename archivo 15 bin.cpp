#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

/**
 * StockEnLocal.dat, ordenado por código del libro, con un registro por cada libro que se
encuentra en el local, con el siguiente diseño:
a.1) Código de libro ( 4 dígitos )
a.3) Autor (20 caracteres)
a.6) Stock en el local (char)
a.2) Título del libro (30 caracteres)
a.4) Editorial (20 caracteres)
a.7) Genero ( 10 caracteres)
b) StockEnDeposito.dat, ordenado por código del libro, con un registro por cada libro que se
encuentra en el depósito, con el siguiente diseño:
b.1) Código de libro ( 4 dígitos ) b.2) Stock en depósito (unsigned char)
*/

typedef struct{
    int codigo;
    char autor[21];
    char stock;
    char titulo[11];
    char editorial[21];
    char genero[11];
} ST_LOCAL;

typedef struct{
    int codigo;
    char stock;
} ST_DEPOSITO;

FILE * abrirArchivo(char * nombre, char * modo){
    FILE * archivo = fopen(nombre, modo);
    if (archivo == NULL)
    {
        EXIT_FAILURE;
    }
    return archivo;
}

void titulo(FILE * file){
    fprintf(file, "libros faltantes\n");
    fprintf(file, "codigo\tobservacion\n");
}

void apareo(FILE * local,FILE * deposito,FILE * faltante){
    ST_LOCAL libroLoc;
    ST_DEPOSITO libroDepos;

    fread(&libroLoc, sizeof(ST_LOCAL), 1, local);
    fread(&libroDepos, sizeof(ST_DEPOSITO), 1, deposito);

    while (!feof(local) && !feof(deposito))
    {
        if (libroLoc.stock == libroDepos.stock)
        {
            fread(&libroLoc, sizeof(ST_LOCAL), 1, local);
            fread(&libroDepos, sizeof(ST_DEPOSITO), 1, deposito);
        } else if (libroLoc.stock < libroDepos.stock){
            fprintf(faltante, "%d\tfalta en local\n", libroDepos.stock - libroLoc.stock);
            fread(&libroLoc, sizeof(ST_LOCAL), 1, local);
            fread(&libroDepos, sizeof(ST_DEPOSITO), 1, deposito);
        } else {
            fprintf(faltante, "%d\tfalta en deposito\n", libroLoc.stock - libroDepos.stock);
            fread(&libroLoc, sizeof(ST_LOCAL), 1, local);
            fread(&libroDepos, sizeof(ST_DEPOSITO), 1, deposito);
        }
    }
}

int main () {
    FILE * local = abrirArchivo("local.dat", "rb");
    FILE * deposito = abrirArchivo("deposito.dat", "rb");
    FILE * faltante = abrirArchivo("faltante.txt", "w");

    titulo(faltante);

    apareo(local, deposito, faltante);

    system("pause");
    return 0;
}