#include <iostream>

using namespace std;
/*2. Ingresar un valor entero N (< 30) y a continuación un conjunto de N elementos. Si el último
elemento del conjunto tiene un valor menor que 10 imprimir los negativos y en caso contrario los
demás.

vec={-1, 5, -4, 2, 10}  ->  [5, 2, 10]

vec={-1, 5, -4, 2, 8}  ->  [-1, -4]
*/

void imprimirValores(int vec[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
    if (vec[cantidad-1] > 10)
    {
        if (vec[i] > 0)
        {
            cout << vec[i];
        }
        else
        {
            cout << vec[i];
        }
    }
    }
    return;
}

int main () {
    int cantidad = 0;

    cout << "ingrese la cantidad de valores que va a iniciar: ";
    cin >> cantidad;

    int vec[cantidad] = [0];

    for (int i = 0; i < cantidad; i++)
    {
        cout << "ingrese un valor: ";
        cin >> vec[i];
    }
    imprimirValores(vec, cantidad);

    system("pause");
    return 0;
}