#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

typedef struct
{
    char codigoPedido[11];
    int codigoCliente;
    char recibido[];
} ST_PEDIDOS;

typedef struct
{
    int codigoCliente;
    char nombre[21];
    char apellido[21];
    char email[21];
} ST_CLIENTES;

typedef struct
{
    char email[21];
    char mensaje[257];
} ST_MENSAJE;


FILE *abrirArchivo(char *nombre, char *modo)
{
    FILE *archivo = fopen(nombre, modo);
    if (archivo == NULL)
    {
        EXIT_FAILURE;
    }
    return archivo;
}

ST_PEDIDOS leerTXT(FILE *file)
{
    ST_PEDIDOS pedido;
    char buffer[255];
    if (fgets(buffer, 255, file) == NULL)
    {
        return pedido;
    }

    strcpy(pedido.codigoPedido, strtok(buffer, ","));
    pedido.codigoCliente = atoi(strtok(NULL, ","));
    strcpy(pedido.recibido, strtok(NULL, ","));

    return pedido;
}

void escribirMensaje(ST_CLIENTES cliente, ST_PEDIDOS pedido, FILE * mensajes){
    ST_MENSAJE mensaje;
    strcpy(cliente.email, mensaje.email);
    strcat(mensaje.mensaje, "estimado/a ");
    strcat(mensaje.mensaje, cliente.nombre);
    strcat(mensaje.mensaje, " su pedido ");
    strcat(mensaje.mensaje, pedido.codigoPedido);
    strcat(mensaje.mensaje, " se encuentra disponible para ser retirado.");
}

int main () {
    FILE * pedidos = abrirArchivo("pedidos.txt", "r");
    FILE * clientes = abrirArchivo("clientes.dat", "rb");
    FILE * mensajes = abrirArchivo("mensajes.dat", "wb");
    
    ST_PEDIDOS pedido;
    ST_CLIENTES cliente;
    ST_MENSAJE mensaje;

    pedido = leerTXT(pedidos);
    while (!feof(pedidos))
    {
        if (strcmp(pedido.recibido, "s") == 0)
        {
            fseek(clientes, sizeof(ST_CLIENTES) * (pedido.codigoCliente-1), SEEK_SET);
            fread(&cliente, sizeof(ST_CLIENTES), 1, clientes);
            escribirMensaje(cliente, pedido, mensajes);
        }   
        pedido = leerTXT(pedidos);
    }
    
    fclose(pedidos);
    fclose(clientes);
    fclose(mensajes);

    system("pause");
    return 0;
}