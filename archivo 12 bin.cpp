#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

typedef struct{
    char codigo[4];
    int stock;
} ST_PRODUCTOS;

typedef struct{
    int pedido;
    long cliente;
    int codigo;
    int cantidad;
} ST_PEDIDOS;

FILE * abrirArchivo(char * nombre, char * modo){
    FILE * archivo = fopen(nombre, modo);
    if (archivo == NULL)
    {
        EXIT_FAILURE;
    }
    return archivo;
}

void imprimirTXT(FILE * fileA, FILE * fileB){
    fprintf(fileA, "Numero de pedidos\tNumero de cliente\tCodigo de producto\tCantidad pedida");
    fprintf(fileB, "Numero de pedidos\tNumero de cliente\tCodigo de producto\tCantidad pedida");
}

void comprobarArchivo(FILE * prod, FILE * ped, FILE * cli, FILE * noCumplidos){
    ST_PRODUCTOS productos;
    ST_PEDIDOS pedidos;
    int punteroProd = 0, punteroPed = 0;
    fread(&pedidos, sizeof(ST_PEDIDOS),1, ped);
    while (!feof(ped))
    {
        int posicion = pedidos.codigo - 1;
        fseek(prod, 0, posicion * sizeof(ST_PRODUCTOS));
        fread(&prod, sizeof(ST_PRODUCTOS),1, prod);
        if (productos.stock > pedidos.cantidad)
        {
            fseek(prod, 0, posicion * sizeof(ST_PRODUCTOS));
            productos.stock -= pedidos.cantidad;
            fwrite(&productos, sizeof(ST_PRODUCTOS), 1, prod);
            fprintf(cli, "%d\t%d\t%d\t%d", pedidos.pedido, pedidos.cliente, pedidos.codigo, pedidos.cantidad);
        }
        else {
            fprintf(noCumplidos, "%d\t%d\t%d\t%d", pedidos.pedido, pedidos.cliente, pedidos.codigo, pedidos.cantidad);
        }
    fread(&pedidos, sizeof(ST_PEDIDOS),1, ped);
    }
}

int main () {
    FILE * producto = abrirArchivo("stock.dat", "wb");
    FILE * pedido = abrirArchivo("pedido.dat", "rb");
    FILE * clientes = abrirArchivo("clientes.txt", "w");
    FILE * noCumplidos = abrirArchivo("noCumplidos.txt", "w");
    fseek(producto, 0, SEEK_SET);
    fprintf(clientes, "productos satisfechos\n");
    fprintf(noCumplidos, "productos no satisfechos\n");
    imprimirTXT(clientes, noCumplidos);
    comprobarArchivo(producto, pedido, clientes, noCumplidos);

    system("pause");
    return 0;
}