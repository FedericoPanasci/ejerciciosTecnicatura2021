#include <iostream>

using namespace std;
/*Ingresar un valor entero N (< 40). A continuación ingresar un conjunto A y luego otro conjunto B
ambos de N elementos. Generar un arreglo C donde cada elemento se forme de la siguiente forma: C[1] =
A[1]+B[N] C[2] = A[2]+B[N-1]*/

void valorConjuntos(int conjuntoA[], int cantidad) {
    for (int i = 0; i < cantidad; i++)
    {
        cout << "ingrese el valor del elemento: ";
        cin >> conjuntoA[i];
    }
    return;
}

void resultadoC(int conjuntoA[], int conjuntoB[], int conjuntoC[], int cantidad) {
    for (int i = 0; i < cantidad; i++)
    {
        conjuntoC[i] = conjuntoA[i] + conjuntoB[cantidad-1-i];
    }
    return;   
}

void imprimirResultado(int A[], int B[], int C[], int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        cout << "C[" << C[i] << "] = A[" << A[i] << "] + B[" << B[cantidad-1-i] << "]" << endl;
    }
    return;
}
int main () {
    int cantidad = 0;
    cout << "indique la cantidad de elementos que van a tener sus conjuntos: ";
    cin >> cantidad;

    int conjuntoA[cantidad] = {0};
    int conjuntoB[cantidad] = {0};
    int conjuntoC[cantidad] = {0};

    valorConjuntos(conjuntoA, cantidad);
    valorConjuntos(conjuntoB, cantidad);
    resultadoC(conjuntoA, conjuntoB, conjuntoC, cantidad);
    imprimirResultado(conjuntoA, conjuntoB, conjuntoC, cantidad);
    system("pause");
    return 0;
}

