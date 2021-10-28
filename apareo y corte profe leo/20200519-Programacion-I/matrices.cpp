#include <iostream>
using namespace std;

#define CANT_COLUMNAS 4


void imprimirNotas(int notas[][CANT_COLUMNAS], int cantAlumnos) {
    for (int i = 0; i < cantAlumnos; i++) {
        int suma = 0;
        for (int j = 1; j < CANT_COLUMNAS; j++) {
            suma += notas[i][j];
        }
        cout << "Legajo: " << notas[i][0] << " promedio: " << (float) suma / (CANT_COLUMNAS - 1) << endl;
    }
}

int main () {

    /*legajo   n1 n2 n3
    1170909  7  8  5
    1234122  4  2  8
    2121121  8  9  7*/

    int cantAlumnos = 0;

    cout << "Ingrese la cantidad de alumnos: ";
    cin >> cantAlumnos;
    int notas[cantAlumnos][CANT_COLUMNAS];

    for (int i = 0; i < cantAlumnos; i++) {
        cout << "Ingrese el legajo del alumno: ";
        cin >> notas[i][0];
        for (int j = 1; j < CANT_COLUMNAS; j++) {
            cout << "Ingrese las notas: ";
            cin >> notas[i][j];
        }
        cout << endl;
    }

    imprimirNotas(notas, cantAlumnos);

    system("pause");
    return 0;
}