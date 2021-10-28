#include <iostream>

using namespace std;
#define PEDIDOS_MAX 100
#define CANT_GUSTOS 50
#define HORARIO 180000

struct ST_GUSTOS
{
    string nombre;
    int cod;
};

struct ST_PEDIDOS
{
    int hora;
    int cod;
    int cant;
};

struct ST_FACTURACION
{
    int cod;
    int facturacion;
    int cant;
};


void llenarSucursal(ST_PEDIDOS local[PEDIDOS_MAX], int &cant){
    int continuar = 1, i = 0;
    while (continuar == 1)
    {
        cout << "ingrese hora del pedido: ";
        cin >> local[i].hora;
        cout << "ingrese codigo del helado: ";
        cin >> local[i].cod;
        cout << "ingrese cantidad pedida: ";
        cin >> local[i].cant;

        cout << "desea ingresar un nuevo pedido? (1 para continuar/0 para salir) ";
        cin >> continuar;
    }
}

//punto A
void apareo(ST_PEDIDOS todos[PEDIDOS_MAX*2], ST_PEDIDOS sucursal1[PEDIDOS_MAX], ST_PEDIDOS sucursal2[PEDIDOS_MAX], int cant1, int cant2, int &cant3){
    int i = 0, j = 0;
    int k = 0;

    while (i < cant1 && j < cant2)
    {
        if (sucursal1[i].hora < sucursal2[j].hora)
        {
            todos[k] = sucursal1[i];
            k++;
            i++;
        }
        if (sucursal1[i].hora == sucursal2[j].hora)
        {
            i++;
            j++;
        }
        if (sucursal2[j].hora < sucursal1[i].hora)
        {
            todos[k] = sucursal2[j];
            j++;
            k++;
        }
        while (i < cant1)
        {
            todos[k] = sucursal1[i];
            i++;
            k++;
        }
        while (j < cant2)
        {
            todos[k] = sucursal2[j];
            j++;
            k++;
        }
    }
}

//punto B
void calcularFacturacion(ST_PEDIDOS todos[PEDIDOS_MAX*2], int cant, ST_FACTURACION facturacion[CANT_GUSTOS]){
    int total = 0, i = 0, gusto = 0, precioMen = 300, precioMay = 400;
    while (i < cant)
    {
        gusto = todos[i].cod-1;
        if (todos[i].hora < HORARIO)
        {
            total = (todos[i].cant/1000) * precioMen;
            facturacion[gusto].cant = facturacion[gusto].cant + todos[i].cant;
            facturacion[gusto].facturacion = facturacion[gusto].facturacion + total;
            total = 0;
        }
        else
        {
            total = (todos[i].cant/1000) * precioMay;
            facturacion[gusto].cant = facturacion[gusto].cant + todos[i].cant;
            facturacion[gusto].facturacion = facturacion[gusto].facturacion + total;
            total = 0;
        }       
    }
}

void imprimirFac(ST_FACTURACION fact[]){
    cout << "codigo de helado - facturacion total" << endl;
    for (int i = 0; i < CANT_GUSTOS; i++)
    {
        cout << fact[i].cod << " - " << fact[i].facturacion << endl;
    }
    cout << endl;
}

//punto C
void ordenarFact(ST_FACTURACION facturacion[]);
// ordena por burbujeo la estructura facturacion teniendo en cuenta los kilos vendidos y llama a imprimir imprimirFactPorK

int main () {
    ST_PEDIDOS sucursal1[PEDIDOS_MAX];
    ST_PEDIDOS sucursal2[PEDIDOS_MAX];
    ST_GUSTOS gustos[CANT_GUSTOS];
    int local, cantPedidos1 = 0, cantPedidos2 = 0, cantPedidos3;
    cout << "ingrese su sucursal 1/2 (otro para finalizar): ";
    cin >> local;
    while (local < 3 && local > 0)
    {
        if (local == 1)
        {
            llenarSucursal(sucursal1, cantPedidos1);
        }
        else
        {
            llenarSucursal(sucursal2, cantPedidos2);
        }
    }
    
    ST_PEDIDOS todos[PEDIDOS_MAX*2];
    //punto A
    apareo(todos, sucursal1, sucursal2, cantPedidos1, cantPedidos2, cantPedidos3);
    //punto B
    ST_FACTURACION facturacion[CANT_GUSTOS];
    calcularFacturacion(todos, cantPedidos3, facturacion);
    imprimirFac(facturacion);

    //punto C
    ordenarFact(facturacion);
    
    system("pause");
    return 0;
}