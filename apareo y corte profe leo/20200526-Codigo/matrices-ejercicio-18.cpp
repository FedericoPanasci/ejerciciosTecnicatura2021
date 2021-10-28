#include <iostream>
using namespace std;

/*
Ingresar un valor N (< 25) y luego por filas una matriz cuadrada CUADRA de N filas y columnas.

Desarrollar un programa que determine e imprima:
a) Todos los elementos de la diagonal principal o secundaria según de cual resulte mayor la sumatoria de elementos.
b) Los elementos del cuarto (N/2 filas y N/2 columnas) cuya sumatoria resulte mayor (considerando que N fuera par).
c) Los elementos de la triangular superior o inferior dependiendo de cual tenga mayor sumatoria de elementos.
*/

#define MAX_FILAS 25
#define MAX_COLS 25

void leer(int& cantidad, string mensaje) {
    cout << mensaje;
    cin >> cantidad;
    return;
}

void cargar(int matriz[MAX_FILAS][MAX_COLS], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < cantidad; j++) {
            leer(matriz[i][j], "Ingrese un elemento de la matriz: ");
        }

    }
    return;
}

void imprimir(int matriz[MAX_FILAS][MAX_COLS], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < cantidad; j++) {
            cout << matriz[i][j] << "   ";
        }
        cout << endl;
    }
}

int sumatoriaPrincipal(int matriz[MAX_FILAS][MAX_COLS], int cantidad) {
    int suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += matriz[i][i];
    }
    return suma;
}

int sumatoriaSecundaria(int matriz[MAX_FILAS][MAX_COLS], int cantidad) {
    int suma = 0;
    int ultimaPos = cantidad - 1;
    for (int i = 0; i < cantidad; i++) {
        suma +=  matriz[i][ultimaPos - i];
    }
    return suma;
}

void imprimirDiagonalPrincipal(int matriz[MAX_FILAS][MAX_COLS], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << matriz[i][i] << "   ";
    }
}

void imprimirDiagonalSecundaria(int matriz[MAX_FILAS][MAX_COLS], int cantidad) {
    int ultimaPos = cantidad - 1;
    for (int i = 0; i < cantidad; i++) {
        cout << matriz[i][ultimaPos - i] << "   ";
    }
}

void imprimir(int vector[], int cant) {
    for (int i = 0; i < cant; i++) {
        cout << vector[i] << "   ";
    }
}

int sumarCuarto(int matriz[MAX_FILAS][MAX_COLS], int despFila, int despCol, int cant, int cuarto[]) {
    int suma = 0;
    int pos = 0;
    for (int i = despFila; i < (despFila + cant); i++) {
        for (int j = despCol; j < (despCol + cant); j++) {
            suma += matriz[i][j];
            cuarto[pos] = matriz[i][j];
            pos++;
        }
    }

    return suma;
}

int main () {

    int cant = 0;
    leer(cant, "Ingrese la cantidad de filas y columnas (<25): ");

    int matriz[MAX_FILAS][MAX_COLS];
    cargar(matriz, cant);

    imprimir(matriz, cant);
    cout << endl << endl;

    int diagonalPrincipal[cant];
    int diagonalSecundaria[cant];

    if(sumatoriaPrincipal(matriz, cant) > sumatoriaSecundaria(matriz,cant)) {
        cout << "La sumatoria principal es mayor, imprimimos la diagonal principal:" << endl;
        imprimirDiagonalPrincipal(matriz, cant);
    } else {
        cout << "La sumatoria secundaria es mayor, imprimimos la diagonal secundaria:" << endl;
        imprimirDiagonalSecundaria(matriz, cant);
    }

    cout << endl << endl;

    int cuartos[4][cant];

    int max, aux = 0;
    int maxPos = 0;

    max = sumarCuarto(matriz,0,0,cant/2, cuartos[0]);

    aux = sumarCuarto(matriz,0,cant/2,cant/2, cuartos[1]);
    if(aux > max) {
        max = aux;
        maxPos = 1;
    }

    aux = sumarCuarto(matriz,cant/2,0,cant/2, cuartos[2]);
    if(aux > max) {
        max = aux;
        maxPos = 2;
    }

    aux = sumarCuarto(matriz,cant/2,cant/2,cant/2, cuartos[3]);
    if(aux > max) {
        max = aux;
        maxPos = 3;
    }

    cout << "El cuarto con mayor sumatoria es: ";
    imprimir(cuartos[maxPos], cant);
    cout << endl;


    system("pause");
    return 0;
}