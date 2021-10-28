#include <iostream>

using namespace std;
/*
5. Ingresar un valor entero N (< 30). A continuación ingresar un conjunto UNO y luego otro conjunto DOS,
ambos de N componentes. Generar e imprimir otro conjunto TRES intercalando los valores de posición
impar de DOS y los valores de posición par de UNO.
*/

void llenarConjunto(int conjunto[], int cantidad, string mensaje){
    cout << "vamos a llenar el conjunto: " << mensaje << endl;
    for (int i = 0; i < cantidad; i++)
    {
        cout << "intrese un elemento a su conjunto: ";
        cin >> conjunto[i];
    }
    return;
}

void imprimirConjuntoC(int C[], int cant){
    cout << "el conjunto C esta formado por: ";
    for (int i = 0; i < cant; i++)
    {
        cout << C[i] << " ";
    }
    return;
}

void armarConjuntoC(int C[], int A[], int B[], int cant) {
    int i = 0;
    while (i < cant)
    {
        if (i == 0)
        {
            C[i];
        }
        
            if (i%2 != 0)
            {
                C[i-1] = B[i-1];
                i++;
            }
            else
            {
                C[i-1] = A[i-1]; 
                i++;
            }
    }
    imprimirConjuntoC(C, cant);
    return;
}

int main () {
    int cantidad = 0;
    cout << "ingrese la cantidad de valores que tendra sus conjuntos A y B: ";
    cin >> cantidad;
    int conjuntoA[cantidad];
    int conjuntoB[cantidad];
    llenarConjunto(conjuntoA, cantidad, "A");
    llenarConjunto(conjuntoB, cantidad, "B");
    int conjuntoC[cantidad];
    armarConjuntoC(conjuntoC, conjuntoA, conjuntoB, cantidad);
    system("pause");
    return 0;
}