#include <iostream>

using namespace std;
#define MULTIPLO_SUCURSAL 100000000000000
#define MULTIPLO_FACTURA 10000
#define CANT_MAX 10

/* Punto de Venta: número entero de 2 dígitos entre 10 y 30. El 10 representa la casa central, 20 y 30 a las sucursales.
● Nro. de factura: número entero entre 1 y 99999999.
● Código de producto vendido: número entre 1000 y 5300
● Cantidad de producto vendido
● Precio unitario: número real. */

// PUNTO 1: estructuras del ejercicio
struct ST_PUNTO_DE_VENTA
{
    int sucursal;
    long int factura;
    int codProd;
    int cantProd;
    float precio;
    long int codCatenado;
};

//PUNTO 2: los conjuntos brindados por cada sucursal tienen que estar ordenados por numero de factura. Para lograr el numero de "codigo" se necesita:
//sucursal * MULTIPLO_SUCURSAL + factura * MULTIPLO_FACTURA + codigo de producto


//PUNTO 3: con ambos grupos ordenados por numero de factura se realiza un anexo. Agrupando de menor a mayor el numero de sucursal

void anexar(ST_PUNTO_DE_VENTA sucursalA[], int A, ST_PUNTO_DE_VENTA sucursalB[], int B, ST_PUNTO_DE_VENTA grupo[], int &k) {
    
    for(int i = 0; i < A; i ++) {
        grupo[i] = sucursalA[i];
    }

    for(int i = 0; i < B; i ++) {
        grupo[A + i] = sucursalB[i];
        k = A + i;
    }
    return;
}

//PUNTO 4: con los conjuntos ordenados por factura en cada sucursal, y anexado por sucursales, realizo la impresion.
void facturacion(ST_PUNTO_DE_VENTA grupo[], int k){
    int sucursalKey, i = 0, facturaKey, totalFactura, totalSucursal, mayorMonto = 0, mayorPunto = 0, sucursalMasVentas;
    while (i < k)
    {
        sucursalKey = grupo[i].sucursal;
        cout << "Punto de venta: " << sucursalKey << endl;
        totalSucursal = 0;
        while (i < k && sucursalKey == grupo[i].sucursal)
        {
            facturaKey = grupo[i].factura;
            cout << "Numero de factura " << facturaKey << endl;
            cout << "Producto | Cantidad | P. U. " << endl;
            totalFactura = 0;
            while (i < k && sucursalKey == grupo[i].sucursal && facturaKey == grupo[i].factura)
            {
                cout << grupo[i].codProd << " | " << grupo[i].cantProd << " | " << grupo[i].precio << endl;
                totalFactura += grupo[i].precio * grupo[i].cantProd;
                i++;
            }
            cout << "Total de la factura: " << totalFactura << endl;
        }
        cout << "Total del punto de venta: " << totalSucursal << endl;
        if (totalSucursal > mayorMonto)
        {
            mayorMonto = totalSucursal;
            sucursalMasVentas = sucursalKey;
        }
    }
    cout << "El punto de venta con mayor monto facturado es: " << sucursalMasVentas << " Y su monto es: " << mayorMonto << endl;
}

int main()
{

    system("pause");
    return;
}
