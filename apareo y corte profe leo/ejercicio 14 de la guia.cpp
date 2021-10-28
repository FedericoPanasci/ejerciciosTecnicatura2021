#include <iostream>

using namespace std;
#define CANT_DISCOS 1000
#define CANT_ANIOS 10
#define CANT_BANDAS 100
struct ST_VENTAXBANDA
{
    int cant;
    string nombreBanda;
};

struct ST_VENTA
{
    string idDisco;
    int cantidad;
};

struct ST_VENTAANUAL
{
    int anio;
    ST_VENTA ventas[CANT_DISCOS];
};

struct ST_DISCO
{
    string IdDisco;
    string nombreDisco;
    int idBanda;
    string nombreBanda;
};

void obtenerListado(ST_DISCO discos[], ST_VENTA ventas[][CANT_ANIOS]){
    int ventaXBandas[CANT_BANDAS] = {0};
    
}

int main () {
    ST_DISCO discos[CANT_DISCOS]; //ordenado por id
    ST_VENTA ventas[CANT_DISCOS][CANT_ANIOS];

    

    obtenerListado(discos, ventas);

    system("pause");
    return 0;
}