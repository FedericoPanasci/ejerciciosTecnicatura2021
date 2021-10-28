#include <iostream>
using namespace std;

#define MAX_COLS 25
#define MAX_FILAS 30

void imprimir(int vec[], int cant){
    for (int i = 0; i < cant; i++) {
        cout << vec[i] << endl;
    }
    return;
}

// Carga la matriz por filas
void cargar(int mat[MAX_FILAS][MAX_COLS], int cantFilas, int cantColumnas) {
    for(int i = 0; i < cantFilas; i++) {
        for(int j = 0;  j < cantColumnas; j++){
            cout << "Ingrese valor: "<<endl;
            cin >> mat[i][j];
        }
     }
}

int sumatoria(int vec[], int cant) {
    int suma = 0;
    for (int i = 0; i < cant; i++) {
        suma += vec[i];
    }

    return suma;
}

int main(){
    int cantFilas = 0;
    int cantColumnas = 0;
    int suma = 0;
    int promedio = 0;
    int mayorFila = 0;
    int numeros[MAX_FILAS][MAX_COLS];

    cout << "Ingrese filas (<25)"<<endl;
    cin >> cantFilas;

    cout << "Ingrese columnas (<30)"<<endl;
    cin >> cantColumnas;

    int sumaColumas[cantColumnas] = {0};
    int maxFilas[cantFilas]={0};

    cargar(numeros, cantFilas, cantColumnas);

    cout << endl;
    for(int i = 0; i < cantFilas; i++) {
        for(int j = 0;  j < cantColumnas; j++){
            cout << numeros[i][j] << "   ";
        }
        cout << endl;
     }

    // Imprime la matriz por columnas
    for(int j = 0;  j < cantColumnas; j++){
        for(int i = 0; i < cantFilas; i++) {
            cout << numeros[i][j] << "   ";
        }
        cout << endl;
    }

    // Sumatoria de todos los elementos
    for(int i = 0; i < cantFilas; i++) {
        suma += sumatoria(numeros[i], cantColumnas); // Ejemplo de uso del subvector de la fila
    }

    // Promedio de los elementos
    promedio = (float) suma/(cantFilas * cantColumnas);
    cout << "El promedio es: " << promedio << endl;


    // Guardo sumatoria por columnas
    for(int j = 0;  j < cantColumnas; j++) {
        for(int i = 0; i < cantFilas; i++) {
            sumaColumas[j] += numeros [i][j];
        }
    }

    cout << "La sumatoria por columnas es" << endl;
    imprimir(sumaColumas, cantColumnas);

    // Guardo maximos por filas
    for(int i = 0; i < cantFilas; i++) {
        mayorFila = numeros[i][0];
        for(int j = 1;  j < cantColumnas; j++){
            if (mayorFila < numeros[i][j]) {
                mayorFila = numeros[i][j];
            }
        }
        maxFilas[i] = mayorFila;
     }

     // Imprimo los maximos por fila
     cout << "Maximos por fila" << endl;
     imprimir(maxFilas, cantFilas);

     system("pause");
     return 0;
}
