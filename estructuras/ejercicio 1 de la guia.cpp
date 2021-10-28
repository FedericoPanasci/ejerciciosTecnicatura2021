#include <iostream>

using namespace std;
/*
1. Ingresar un valor N (< 25). Generar un arreglo de N componentes en el cual las mismas contengan los
primeros números naturales pares e imprimirlo.
*/
void imprimirNaturales(int naturales[], int corte){
    cout << "los numeros naturales que eligio son: ";
    for (int i = 1; i <= corte; i++)
    {
        cout << naturales[i] << " ";
    }
    return;
}

void obtenerNaturales(int naturales[], int valor){
    for (int i = 0; i <= valor; i++)
    {
        naturales[i] = i * 2;
    }
    imprimirNaturales(naturales, valor);
    return;
}

int main () {
    int valor = 0;
    cout << "ingrese la cantidad de numeros pares que quiere saber: ";
    cin >> valor;
    int naturales[valor];
    obtenerNaturales(naturales, valor);
    system("pause");
    return 0;
}