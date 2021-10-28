#include <iostream>

using namespace std;

/* 1. Ingresar un valor N (< 25). Generar un arreglo de N componentes en el cual las mismas contengan los
primeros números naturales pares e imprimirlo.
*/
void imprimir(int vec[], int cantidad)
{
    for (int i = 0; i <= cantidad; i++)
    {
        if (vec[i] != 0)
        {
            cout << vec[i] << endl;
        }
        
    }
    return;
}

int main () {
    int cantidad;

    cout << "ingrese cantidad de elementos (<25): ";
    cin >> cantidad;

    int vec[cantidad];

    for (int i = 0; i <= cantidad; i++)
    {
        vec[i] = i * 2;
    }

    imprimir(vec, cantidad);
    
    system("pause");
    return 0;
}