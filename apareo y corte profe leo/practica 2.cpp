#include <iostream>

using namespace std;
#define CANT_EMPLEADOS 10

struct ST_EMPLEADOS
{
    string nombre;
    int cantegoria;
};

void armarLista(ST_EMPLEADOS empleados[], int cant){
    int i = 0;
    int keyCate = 0;
    int cantEmpleados = 0;
    while (i < cant)
    {
        keyCate = empleados[i].cantegoria;
        cantEmpleados = 0;
        cout << "categoria: " << keyCate << endl;
        while (i < cant && keyCate == empleados[i].cantegoria)
        {
            empleados[i].nombre;
            cantEmpleados++;
            i++;
        }
        cout << "-----------" << endl;
        cout << "total de empleados de la categoria: " << cantEmpleados << endl;
        cout << endl;
    }
    

}

int main () {
    ST_EMPLEADOS empleados[CANT_EMPLEADOS];
    armarLista(empleados, CANT_EMPLEADOS);
    system("pause");
    return 0;
}