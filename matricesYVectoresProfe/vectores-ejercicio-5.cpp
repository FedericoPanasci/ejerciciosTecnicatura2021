
#include <iostream>
using namespace std;

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

void imprimir(int vec[], int cant){
    for (int i = 0; i < cant; i++) {
        cout << vec[i] << endl;
    }
    return;
}

bool esPar (int valor) {
    return valor % 2 == 0;
}

int main() {
     // Leemos la cantidad de elementos
    int cantidad, suma;
    leer(cantidad, "Ingrese cantidad de elementos: ");

    // Declaramos y cargamos el vactor 1
    int vec1[cantidad];
    cargarVector(vec1, cantidad);

    // Declaramos y cargamos el vactor 2
    int vec2[cantidad];
    cargarVector(vec2, cantidad);

    // Declaramos el vector 3
    int vec3[cantidad];

    for (int i = 0; i < cantidad; i++) {
        if (esPar(i)) {
            vec3[i] = vec1[i];
        } else {
            vec3[i] = vec2[i];
        }
    }

    imprimir(vec3, cantidad);
    system("pause");
    return 0;
}
