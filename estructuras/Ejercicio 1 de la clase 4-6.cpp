#include <iostream>

using namespace std;

#define CANT_CLIENTES 2

/*
1. Desarrollar las estructuras que permitan construir el sistema
2. Desarrollar una función que permita ordenar el conjunto de clientes por su código
3. Desarrollar una función que permita buscar un cliente a partir de su código.
4. Desarrolle el procedimiento que permita actualizar el monto de compra de un cliente
(suponga que los clientes ya están todos cargados)
5. Desarrollar una función que permita ordenar los clientes por el monto de sus compras.
6. Genere un listado de los N mejores clientes según su monto de compras.
*/
struct ST_CLIENTE {
    int codigo;
    string nombre;
    string mail;
    int montonCompra;
};
ST_CLIENTE cargarCliente(){
    ST_CLIENTE cliente;

        cout << "ingrese el nombre del cliente: ";
        cin >> cliente.nombre;
        cout << "ingrese el codigo del cliente: ";
        cin >> cliente.codigo;
        cout << "ingrese el mail del cliente: ";
        cin >> cliente.mail;
        cout << "ingrese el monto de compras del cliente: ";
        cin >> cliente.montonCompra;
        cout << endl;
        return cliente;
}
void ordenarClientesXCodigo(ST_CLIENTE clientes[CANT_CLIENTES]){
    ST_CLIENTE aux; //tiene que ser del mismo tipo x eso es st

    for (int i = 0; i < CANT_CLIENTES - 1; i++)
    {
        for (int j = 0; j < CANT_CLIENTES; j++)
        {
            if (clientes[j].codigo >= clientes[j + 1].codigo) //se acomoda el punto necesario
            {
                aux = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = aux;
            }
        }
    }
    
    return;
}

int busquedaBinariaXCodigo(ST_CLIENTE cliente[CANT_CLIENTES], int codigo){
    int inferior = 0;
    int superior = CANT_CLIENTES - 1;
    int medio = -1;
    int pos = -1;

    while (inferior < superior)
    {
        medio = (inferior + superior) / 2;
        if (cliente[medio].codigo == codigo)
        {
            pos = medio;
        }
        
        if (cliente[medio].codigo < codigo){
            inferior = medio + 1;
        }
        else
        {
            superior = medio - 1;
        }
        
    }

    return pos;
}

void actualizarMontoCompra(ST_CLIENTE clientes[CANT_CLIENTES]){

}

void ordenarPorMontoDeCompra(ST_CLIENTE clientes[CANT_CLIENTES]){
    ST_CLIENTE aux; //tiene que ser del mismo tipo x eso es st

    for (int i = 0; i < CANT_CLIENTES - 1; i++)
    {
        for (int j = 0; j < CANT_CLIENTES; j++)
        {
            if (clientes[j].montonCompra >= clientes[j + 1].montonCompra) //se acomoda el punto necesario
            {
                aux = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = aux;
            }
        }
    }
    
    return;
}

int main () {
    ST_CLIENTE cliente[CANT_CLIENTES];

    cout << "hola, vamos a iniciar el programa, primero carguemos los clientes: " << endl;
    for (int i = 0; i < CANT_CLIENTES; i++) {
        cliente[i] = cargarCliente();
    }
    ordenarClientesXCodigo(cliente);
    int codigo = 0;
    cout << "ingrese el codigo del cliente buscado: ";
    cin >> codigo;
    int pos = busquedaBinariaXCodigo(cliente, codigo);
    actualizarMontoCompra() /*le perdi el ritmo, resolver x cuenta propia*/
    ordenarPorMontoDeCompra(cliente);


    system("pause");
    return 0;
}