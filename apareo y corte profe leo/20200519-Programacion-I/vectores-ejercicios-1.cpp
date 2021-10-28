/* 1. Ingresar un valor N (< 25). Generar un arreglo de N componentes en el cual las mismas contengan los
primeros números naturales pares e imprimirlo.*/

#include <iostream>

using namespace std;

void imprimir(int vec[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        cout << vec[i] << endl;
    }

    return;
}

void imprimir(string vec[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        cout << vec[i] << endl;
    }

    return;
}

int main()
{
    int cantidad;
    cout << "Ingrese catidad de elementos (<25): ";
    cin >> cantidad;

    int vec[cantidad];

    for (int i = 0; i < cantidad; i++)
    {
        vec[i] = i * 2;
    }

    imprimir(vec, cantidad);

    system("pause");
    return 0;
}
