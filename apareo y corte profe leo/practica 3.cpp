#include <iostream>

using namespace std;
#define CANT_VENDEDORES 10
struct ST_VENDEDOR
{
    string nombre;
    int sucursal;
    int fecha;
    float monto;
};

void armarListado(ST_VENDEDOR vendedor[], int cant){
    int i = 0;
    string nombreVendedor = " ";
    int numSucursal = 0; 
    float montoVendedor = 0;
    float montoSucursal = 0;
    while (i < cant)
    {
        numSucursal = vendedor[i].sucursal;
        montoSucursal = 0;
        cout << "sucursal: " << numSucursal << endl;
        while (i < cant && vendedor[i].sucursal == numSucursal)
        {
            nombreVendedor = vendedor[i].nombre;
            montoVendedor = 0;
            while (i < cant && vendedor[i].sucursal == numSucursal && nombreVendedor == vendedor[i].nombre)
            {
                montoVendedor = montoVendedor + vendedor[i].monto;
                i++;
            }
            montoSucursal = montoSucursal + montoVendedor;
            cout << nombreVendedor << ": " << montoVendedor << endl; 
            montoVendedor = 0;
        }
        cout << "-------" << endl;
        cout << "total sucursal " << numSucursal << ": " << montoSucursal << endl;
        cout << endl;
    }
    
}

int main () {
    ST_VENDEDOR vendedor[CANT_VENDEDORES];
    armarListado(vendedor, CANT_VENDEDORES);
    system("pause");
    return 0;
}