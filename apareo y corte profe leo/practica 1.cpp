#include <iostream>

using namespace std;
#define CANT_VENDEDORES 10
struct ST_VENDEDOR
{
    string nombre;
    float monto;
    int fecha;
};

void corte(ST_VENDEDOR vendedor[]){
    int i = 0;
    string nomVendedor = " ";
    float montoTotal = 0;
    while (i < CANT_VENDEDORES)
    {
        montoTotal = 0;
        nomVendedor = vendedor[i].nombre;
        while (i < CANT_VENDEDORES && vendedor[i].nombre == nomVendedor)
        {
            montoTotal = montoTotal + vendedor[i].monto;
            i++;
        }
        cout << nomVendedor << ": " << montoTotal << endl;
    }
}


int main () {
    ST_VENDEDOR vendedor[CANT_VENDEDORES];
    corte(vendedor);
    system("pause");
    return 0;
}