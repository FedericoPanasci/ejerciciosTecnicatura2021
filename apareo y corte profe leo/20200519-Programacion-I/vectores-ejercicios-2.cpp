/*2. Ingresar un valor entero N (< 30) y a continuación un conjunto de N elementos. Si el último
elemento del conjunto tiene un valor menor que 10 imprimir los negativos y en caso contrario los
demás.

vec={-1, 5, -4, 2, 10}  ->  [5, 2, 10]

vec={-1, 5, -4, 2, 8}  ->  [-1, -4]

*/

#include <iostream>
using namespace std;

void cargarVector(int vector[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese un valor del vector: " << endl;
        cin >> vector[i];
    }
    return;
}

void imprimirPositivos(int vec[], int cant) {
    for (int i = 0; i < cant; i++) {
        if (vec[i] >= 0) {
            cout << vec[i] << endl;
        }
    }
}

void imprimirNegativos(int vec[], int cant) {
    for (int i = 0; i < cant; i++) {
        if (vec[i] < 0) {
            cout << vec[i] << endl;
        }
    }
}

void leer(int& cantidad, string mensaje) {
    cout << mensaje;
    cin >> cantidad;
    return;
}

int main () {

    // Leemos la cantidad de elementos
    int cantidad;
    leer(cantidad, "Ingrese cantidad de elementos: ");

    // Declaramos y cargamos el vactor
    int vec[cantidad];
    cargarVector(vec, cantidad);

    // Segun el valor en la ultima posicion imprimimos negativos o positivos
    if (vec[cantidad - 1] < 10) {
        imprimirPositivos(vec, cantidad);
    } else {
        imprimirNegativos(vec, cantidad);
    }
    system("pause");
    return 0;
}