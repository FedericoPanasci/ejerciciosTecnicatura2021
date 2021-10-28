#include <iostream>
using namespace std;

void cargar(int vec[], int cant) {
    for(int i = 0; i < cant; i++) {
        cout << "Ing. un valor:";
        cin >> vec[i];
    }
    return;
}

void imprimir(int vec[], int cant) {
    for(int i = 0; i < cant; i++) {
        cout << vec[i] << endl;
    }
    return;
}

void anexar(int vecA[], int n, int vecB[], int m, int vecC[]) {
    // Lleno C con el vector A
    for(int i = 0; i < n; i ++) {
        vecC[i] = vecA[i];
    }

    // Lleno C con el vector B
    for(int i = 0; i < m; i ++) {
        vecC[n + i] = vecB[i];
    }
    return;
}

void apareo(int vecA[],int n,int vecB[], int m, int vecC[], int &k) {
    int i = 0, j = 0;
    k = 0;
    while( i < n && j < m  ){
        if (vecA[i] < vecB[j]) {
            vecC[k] = vecA[i];
            i++;
        } else {
            vecC[k] = vecB[j];
            j++;
        }
            k++;
    }

    while(i < n) {
        vecC[k] = vecA[i];
        i++;
        k++;
    }

    while(j < m) {
        vecC[k] = vecB[j];
        j++;
        k++;
    }
    return;
}

int main () {
    int n, m;
    cout << "Ingrese la cantidad de elementos de A (N):";
    cin >> n;
    cout << "Ingrese la cantidad de elementos de B (M):";
    cin >> m;

    int vecA[n];
    int vecB[m];
    int vecC[n + m];

    cout << "Ingrese los elementos de A" << endl;
    cargar(vecA, n);

    cout << "Ingrese los elementos de A" << endl;
    cargar(vecB, m);

    anexar(vecA, n, vecB, m, vecC);

    int k = 0;
    apareo(vecA, n, vecB, m, vecC, k);

    cout << "Cantidad de elementos en C:" << k << endl;
    imprimir(vecC, k);

    system("pause");
    return 0;
}











































































struct Alumno {
    int legajo;
    string apellido;
    int nota1;
    int nota2;
};

void cargarAlumno(Alumno& alumno) {
    cout << "Legajo:";
    cin >> alumno.legajo;
    cout << "Nombre:";
    cin >> alumno.apellido;
    alumno.nota1 = 0;
    alumno.nota2 = 0;
    return;
}