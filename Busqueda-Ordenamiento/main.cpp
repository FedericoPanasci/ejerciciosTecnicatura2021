#include <iostream>
using namespace std;

#define CANT_VENDEDORES 5
#define MAX_PRODUCTOS 50

struct Vendedor
{
    int legajo;
    string apellido;
    string nombre;
};

struct Venta
{
    int legajoVendedor;
    int codigoProducto;
    float cantidad;
};

struct Producto
{
    int codigo;
    string descripcion;
    float precio;
    int stock;
};

struct FacturacionXVendedor
{
    int legajo;
    float facturacion;
};

/**
 * Valida la venta confirmando que haya stock del producto
 */
bool esValida(Venta venta);

/**
 * Procesa una venta: Valida que haya stock, si no hay devuelve false.
 * Si hay stock actualiza la facturacion del vendedor
*/
bool procesarVenta(Venta venta, Producto productos[], int cantProductos, float facturaciones[], int cantVendedores);

/**
 * Busca un vendedor por legajo
 */
int buscar(Vendedor vendedores[], int cant, int legajo);

/**
 * Busca un producto por codigo
 */
int buscar(Producto productos[], int cant, int codigo);

/**
 * Ordena el vector de productos por codigo
*/
void ordenarXCodigo(Producto productos[], int cantidad);

/**
 * Imprime la facturacion de todos los vendedores mostrando:
 * LEGAJO    APELLIDO   NOMBRE   FACTURACION
 * Ordenado ascendente por numero de legajo
*/
void imprimirFactuacionXLegajo(FacturacionXVendedor facturacionVendedores[], int cantidad);

void imprimirFactuacionXMonto(FacturacionXVendedor facturacionVendedores[], int cantidad);

Venta cargarVenta();

void leer(int& valor, string mensaje);

int main()
{
    Vendedor vendedores[CANT_VENDEDORES];
    float facturaciones[CANT_VENDEDORES] = {0};
    Producto productos[MAX_PRODUCTOS];

    // Carga de todos los vectores

    ordenarXCodigo(productos, MAX_PRODUCTOS);

    int cantVentas = 0;
    leer(cantVentas, "Ingrese cuantas ventas va a cargar:");
    for (int i = 0; i < cantVentas; i++)
    {
        if(procesarVenta(cargarVenta(), productos,MAX_PRODUCTOS, facturaciones, CANT_VENDEDORES)) {
            cout << "Venta cargada con éxito!";
        } else {
            cout << "No se pudo cargar la venta";
        }
    }




    system("pause");
    return 0;
}

void leer(int& val, string mensaje) {
    cout << mensaje;
    cin >> val;
}

int buscar(Producto vector[], int cant, int codigo)
{
    for (int i = 0; i < cant; i++)
    {
        if (vector[i].codigo == codigo)
        {
            return i;
        }
    }

    return -1;
}

int buscarBinaria(Producto vector[], int cant, int codigo)
{
    // Cuando arranco evalúo todo el vector de 0 a n - 1
    int inicio = 0;
    int fin = cant - 1;
    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;
        // Si el elemento es el del medio, devolvemos la posicion
        if (vector[mitad].codigo == codigo)
            return mitad;
        // Si el elemento es menor entonces solo puede estar en la primer mitad
        if (vector[mitad].codigo > codigo)
        {
            fin = mitad - 1; //Cambio el limite superior
        }
        else
        {
            inicio = mitad + 1; // Cambio el limite inferior
        }
    }
    // Si llegamos hasta aca es que el elemento no estaba
    return -1;
}

bool procesarVenta(Venta venta, Producto productos[], int cantProductos, float facturaciones[], int cantVendedores)
{
    int posProducto = buscarBinaria(productos, cantProductos, venta.codigoProducto);

    // No encontro el producto
    if (posProducto == -1)
    {
        return false;
    }

    Producto prod = productos[posProducto];

    // No hay stock para la venta
    if (prod.stock < venta.cantidad)
    {
        return false;
    }

    prod.stock = prod.stock - venta.cantidad;
    float fact = prod.precio * venta.cantidad;

    facturaciones[venta.legajoVendedor - 1] += fact;

    return true;
}

void ordenarXCodigo(Producto productos[], int cant)
{
    Producto aux;
    int i = 0;
    bool ordenado = false;
    while(i < cant - 1 && !ordenado){
        ordenado = true;
        // Los ultimos i elementos ya estan ordenados
        for (int j = 0; j < cant - i - 1; j++) {
            if (productos[j].codigo > productos[j + 1].codigo) {
                aux = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

Venta cargarVenta() {
    Venta venta;
    venta.cantidad = 5;
    venta.codigoProducto = 1;
    venta.legajoVendedor = 1;
    return venta;
}

void imprimirVendedor(Vendedor vendedor) {
    cout << vendedor.legajo << vendedor.apellido << vendedor.nombre;
}

void imprimirFactuacionXLegajo(float facturaciones[], Vendedor vendedores[], int cantidad) {
    cout << "LEGAJO     APELLIDO     NOMBRE    FACTURACION";
    for (int i = 0; i < cantidad; i++) {
        imprimirVendedor(vendedores[i]);
        cout << facturaciones[i];
    }
}


void ordenarPorApellido(Vendedor vendedores[], int cant) {
    Vendedor aux;
    int i = 0;
    bool ordenado = false;
    while(i < cant - 1 && !ordenado){
        ordenado = true;
        // Los ultimos i elementos ya estan ordenados
        for (int j = 0; j < cant - i - 1; j++) {
            if (vendedores[j].apellido > vendedores[j + 1].apellido) {
                aux = vendedores[j];
                vendedores[j] = vendedores[j + 1];
                vendedores[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

void imprimirFactuacionXApellido(float facturaciones[], Vendedor vendedores[], int cantidad) {
    cout << "LEGAJO     APELLIDO     NOMBRE    FACTURACION";
    ordenarPorApellido(vendedores, cantidad);
    for (int i = 0; i < cantidad; i++) {
        imprimirVendedor(vendedores[i]);
        cout << facturaciones[vendedores[i].legajo - 1];
    }
}