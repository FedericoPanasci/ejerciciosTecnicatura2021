#include <iostream>
using namespace std;

int factorial(int numero){
    if (numero == 0 || numero == 1) {
        return 1;
    }

    return numero * factorial(numero - 1);
}

void leer(int& cantidad, string mensaje) {
    cout << mensaje;
    cin >> cantidad;
    return;
}

void cargarVector(int vector[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese un valor del vector: " << endl;
        cin >> vector[i];
    }
    return;
}

void vectorFactorial(int vec[], int fact[], int cant) {
    for (int i = 0; i < cant; i++) {
        fact[i] = factorial(vec[i]);
    }

    return;
}

void imprimir(int vec[], int fact[], int cant){
    for (int i = 0; i < cant; i++) {
        cout << vec[i] << " " << fact[i] << endl;
    }
    return;
}

int main () {
    // Leemos la cantidad de elementos
    int cantidad;
    leer(cantidad, "Ingrese cantidad de elementos: ");

    // Declaramos y cargamos el vactor
    int vec[cantidad];
    cargarVector(vec, cantidad);

    // Declaramos y cargamos el vector factorial
    int fact[cantidad];
    vectorFactorial(vec, fact, cantidad);

    // Imprimimos
    imprimir(vec, fact, cantidad);

    system("pause");
    return 0;
}