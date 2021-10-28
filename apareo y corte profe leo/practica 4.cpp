#include <iostream>

using namespace std;
#define CANT_PROV 21

struct ST_PROVINCIA
{
    string nombre;
    string categoria;
    string impuesto;
    int importe;
};

void imprimirProv(ST_PROVINCIA provincias[], int cant){
    int i = 0;
    string provinciaKey = " ";
    string cateKey = " ";
    int cantImpuestos = 0;
    int totalImporte = 0;
    int cantCate = 0;
    int totalProv = 0;
    while (i < cant)
    {
        provinciaKey = provincias[i].nombre;
        cout << "prov. : " << provinciaKey << endl;
        totalProv = 0;
        cantCate = 0;
        while (i < cant && provincias[i].nombre == provinciaKey)
        {
            cateKey = provincias[i].categoria;
            cout << "categoria: " << cateKey;
            cantImpuestos = 0;
            totalImporte = 0;
            while (i < cant && provincias[i].nombre == provinciaKey && provincias[i].categoria == cateKey)
            {
                cantImpuestos++;
                totalImporte = totalImporte + provincias[i].importe;
                i++;
            }
            cout << "cantidad impuestos  " << cantImpuestos << "  " << "importe " << totalImporte << endl;
            cout << endl;
            cantCate++;
            totalProv = totalProv + totalImporte;
        }
        cout << "-------" << endl;
        cout << "cant categorias: " << cantCate << "   importe: " << totalProv << endl;   
    }
    
}

int main () {
    ST_PROVINCIA provincias[CANT_PROV];
    imprimirProv(provincias, CANT_PROV);
    system("pause");
    return 0;
}