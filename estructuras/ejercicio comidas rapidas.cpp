#include <iostream>

using namespace std;

#define CANT_MAXINGREDIENTES 5
#define CANT_RECETAS 3
#define CANT_INGREDIENTES_RECETA 3

/*
Una casa de comidas rápidas necesita un sistema que le permita administrar su stock de
materias primas. Esta casa sólo cocina platos simples, por lo que la cantidad de
ingedientes utilizados son pocos, por ejemplo para cocinar una hamburguesa utiliza 2
panes, 1 hamburguesa, 1 feta de queso y 1 de jamón.
De cada ingrediente utilizado se sabe:

Nombre
stock: int
stock_maximo: int

Cada vez que se realiza una comida, se debe descontar del "stock" del ingrediente la
cantidad utilizada.
Para cada receta, la casa cuenta con la siguiente información:

Nombre
Ingrediente 1 y su cantidad
Ingrediente 2 y su cantidad
Ingrediente 3 y su cantidad
Precio: float

Se pide:
1. Cuando un cliente realiza su pedido (siempre se pide un único plato):
1. Analizar si se puede realizar el pedido del cliente, es decir que se tenga el stock
correspondiente de cada materia prima. En caso contrario mostrar un mensaje
informando lo ocurrido.
2. Si se puede realizar el pedido, descontar el stock correspondiente de cada
ingrediente.
3. Si el stock de algún ingrediente desciende por debajo del 30% del "stock_maximo"
emitir un mensaje de aviso.
4. Realizar un menú que le permita al usuario del sistema:
1. Vender un plato
2. Consultar si algún producto tiene un stock crítico que deba ser recargado
3. Recargar el stock del producto.
*/


struct ST_INGREDIENTES
{
    string nombre;
    int cantidad;
    int cantMax;
};

struct ST_RECETA
{
    string nombre;
    ST_INGREDIENTES ingrediente1;
    ST_INGREDIENTES ingrediente2;
    ST_INGREDIENTES ingrediente3;
    float precio;
};

void ingresarIngredientes(ST_INGREDIENTES ingredientes[]){
    ingredientes[0].nombre = "hamburguesa";
    ingredientes[0].cantidad = 100;
    ingredientes[0].cantMax = 100;

    ingredientes[1].nombre = "pan";
    ingredientes[1].cantidad = 200;
    ingredientes[1].cantMax = 200;

    ingredientes[2].nombre = "tomate";
    ingredientes[2].cantidad = 50;
    ingredientes[2].cantMax = 50;

    ingredientes[3].nombre = "jamon";
    ingredientes[3].cantidad = 75;
    ingredientes[3].cantMax = 75;

    ingredientes[4].nombre = "chedar";
    ingredientes[4].cantidad = 150;
    ingredientes[4].cantMax = 150;

    return;
}

void ingresarRecetas(ST_RECETA recetas[]){
    recetas[0].nombre = "chedar Lovers";
    recetas[0].ingrediente1.nombre = "pan";
    recetas[0].ingrediente1.cantidad = 2;
    recetas[0].ingrediente2.nombre = "hamburguesa";
    recetas[0].ingrediente2.cantidad = 1;
    recetas[0].ingrediente3.nombre = "chedar";
    recetas[0].ingrediente3.cantidad = 4;
    recetas[0].precio = 550;

    recetas[1].nombre = "española";
    recetas[1].ingrediente1.nombre = "pan";
    recetas[1].ingrediente1.cantidad = 2;
    recetas[1].ingrediente2.nombre = "hamburguesa";
    recetas[1].ingrediente2.cantidad = 1;
    recetas[1].ingrediente3.nombre = "jamon";
    recetas[1].ingrediente3.cantidad = 4;
    recetas[1].precio = 500;

    recetas[2].nombre = "italiana";
    recetas[2].ingrediente1.nombre = "pan";
    recetas[2].ingrediente1.cantidad = 2;
    recetas[2].ingrediente2.nombre = "hamburguesa";
    recetas[2].ingrediente2.cantidad = 1;
    recetas[2].ingrediente3.nombre = "tomate";
    recetas[2].ingrediente3.cantidad = 4;
    recetas[2].precio = 525;
}



bool analizarStock(ST_RECETA receta[], ST_INGREDIENTES ingrediente[], int eleccion){
    int cantidadTrue = 0;
    for (int i = 0; i < CANT_MAXINGREDIENTES; i++)
    {
        if (receta[eleccion - 1].ingrediente1.nombre == ingrediente[i].nombre && receta[eleccion - 1].ingrediente1.cantidad <= ingrediente[i].cantidad)
        {
            cantidadTrue++;
        }
        if (receta[eleccion - 1].ingrediente2.nombre == ingrediente[i].nombre && receta[eleccion - 1].ingrediente2.cantidad <= ingrediente[i].cantidad)
        {
            cantidadTrue++;
        }
        if (receta[eleccion - 1].ingrediente3.nombre == ingrediente[i].nombre && receta[eleccion - 1].ingrediente3.cantidad <= ingrediente[i].cantidad)
        {
            cantidadTrue++;
        }
    }
    if (cantidadTrue == 3)
    {
        return true;
    }
    return false;    
}

void menuUsuario(int &accion, string mensaje){
    cout << mensaje;
    cin >> accion;
}

void descontarStock(ST_RECETA receta[], ST_INGREDIENTES ingrediente[], int eleccion) {
    for (int i = 0; i < CANT_MAXINGREDIENTES; i++)
    {
        if (receta[eleccion - 1].ingrediente1.nombre == ingrediente[i].nombre)
        {
            ingrediente[i].cantidad = ingrediente[i].cantidad - receta[eleccion - 1].ingrediente1.cantidad;
        }
        if (receta[eleccion - 1].ingrediente2.nombre == ingrediente[i].nombre)
        {
            ingrediente[i].cantidad = ingrediente[i].cantidad - receta[eleccion - 1].ingrediente2.cantidad;
        }
        if (receta[eleccion - 1].ingrediente3.nombre == ingrediente[i].nombre)
        {
            ingrediente[i].cantidad = ingrediente[i].cantidad - receta[eleccion - 1].ingrediente3.cantidad;
        }
    }
    return;
}

void armarPedido(ST_RECETA receta[], ST_INGREDIENTES ingredietes[], int eleccion){
    cout << "realizando pedido: " << receta[eleccion - 1].nombre << ", su importe es: " << receta[eleccion - 1].precio << endl;
    descontarStock(receta, ingredietes, eleccion);
    return;
}

void conocerProductoCritico(ST_INGREDIENTES ingrediente[]){
    float promedio = 0;
    string nombre = " ";
    for (int i = 0; i < CANT_MAXINGREDIENTES; i++)
    {
        float promedioMinimo = 30 * 100 / ingrediente[i].cantMax;
        promedio = (ingrediente[i].cantidad * 100 / ingrediente[i].cantMax) * 1.0;
        if (promedio < promedioMinimo)
        {
            nombre = ingrediente[i].nombre;
            cout << "La cantidad de productos de " << nombre << " que quedan esta por debajo del 25%, la cantidad es de: " << promedio << "%." << endl;
        }
        else
        {
            cout << "el producto " << ingrediente[i].nombre << " no necesita ser recargado." << endl;
        }
    }
}

void recargarStock(ST_INGREDIENTES ingrediente[]){
    string ingredienteARecargar = " ";
    cout << "¿que ingrediente desea recargar? ";
    cin >> ingredienteARecargar;
    int agregar = 0;
    for (int i = 0; i < CANT_MAXINGREDIENTES; i++)
    {
        if (ingredienteARecargar == ingrediente[i].nombre)
        {
            cout << "al ingrediente " << ingrediente[i].nombre << "le falta " << ingrediente[i].cantMax - ingrediente[i].cantidad << endl; 
            cout << "¿cuanto desea agregar al stock? ";
            cin >> agregar;
            ingrediente[i].cantidad += agregar;
            cout << "ahora su stock del producto " << ingrediente[i].nombre << "tiene: " << ingrediente[i].cantidad << " de stock." << endl;
        }
    }
}

void realizarAccion(int accion, ST_INGREDIENTES ingredientes[], int cantIngredientes, ST_RECETA receta[], int cantRecetas) {
    int eleccionUsuario = 0;
    while (accion < 4)
    {   
    switch (accion)
    {
    case 1:
        cout << "¿que plato lleva? (1 chedar Lovers, (2 española o (3 italiana: ";
        cin >> eleccionUsuario;
        if (!analizarStock(receta, ingredientes, eleccionUsuario)){
            cout << "no se puede armar el pedido xq faltan elementos." << endl;
        }
        else
        {
        armarPedido(receta, ingredientes, eleccionUsuario);
        }
        break;
    case 2:
        conocerProductoCritico(ingredientes);
        break;
    case 3:
        recargarStock(ingredientes);
        break;
    }
    cout << "que accion desea realizar (1 vender plato, (2 conocer producto con stock critico, (3 recargar stock, (4 finalizar programa. ";
    cin >> accion;
    }
        cout << "gracias por utilizar el programa" << endl;
    return;
}

int main () {
    ST_INGREDIENTES ingredientes[CANT_MAXINGREDIENTES];
    ST_RECETA recetas[CANT_RECETAS];
    ingresarIngredientes(ingredientes);
    ingresarRecetas(recetas);

    int accion = 0;
    menuUsuario(accion, "que accion desea realizar (1 vender plato, (2 conocer producto con stock critico, (3 recargar stock, (4 finalizar programa ");
    realizarAccion(accion, ingredientes, CANT_INGREDIENTES_RECETA, recetas, CANT_RECETAS);

    system("pause");
    return 0;
}