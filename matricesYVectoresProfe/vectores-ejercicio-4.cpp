#include <iostream>

using namespace std;
/*4. Ingresar un valor entero N (< 25). A continuación ingresar un conjunto VEC de N componentes. Si la
suma de las componentes resulta mayor que cero imprimir las de índice impar, sino los otros
elementos.

vec={1, -3, 5, 10, -9} - > res={-3, 10 }

vec={1,- 12 , -3, 5, -10, -9} - > res={1, -3, -10 }*/

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

int sumatoria(int arreglo[], int n){
    int sumatoria = 0;
    for (int i = 0; i < n; i++) {
        sumatoria += arreglo[i];
    }
    return sumatoria;
}

bool esPar (int valor) {
    return valor % 2 == 0;
}

int main()
{
    // Leemos la cantidad de elementos
    int cantidad, suma;
    leer(cantidad, "Ingrese cantidad de elementos: ");

    // Declaramos y cargamos el vactor
    int vec[cantidad];
    cargarVector(vec, cantidad);

    suma = sumatoria(vec, cantidad);

    for (int i = 0; i < cantidad; i++) {
        if (suma <= 0 && esPar(i)) {
            cout << vec[i];
        }

        if (suma > 0 && !esPar(i)) {
            cout << vec[i];
        }
    }

    system("pause");
    return 0;
}