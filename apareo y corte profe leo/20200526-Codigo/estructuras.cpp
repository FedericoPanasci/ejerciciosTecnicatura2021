#include <iostream>
using namespace std;

#define MAX_NOTAS 4
    /*
    nombre legajo   n1 n2 n3
    "Leo"  1170909  7  8  5
    "Pepe" 1234122  4  2  8
    "Caro" 2121121  8  9  7
    */

struct Documento {
    string tipo;
    int numero;
};

struct Alumno {
    string nombre;
    int legajo;
    Documento documento;
    int notas[MAX_NOTAS];
    int cantNotas;
    float promedio;
};

void cargarNotas(int vector[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese una nota: " << endl;
        cin >> vector[i];
    }
    return;
}

void imprimirNotas(int vec[], int cant){
    for (int i = 0; i < cant; i++) {
        cout << "Nota " << i + 1 << ": " << vec[i] << endl;
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

float promedio(int vector[],int cant) {
    return sumatoria(vector, cant) / (float) cant;
}

void calcularPromedio(Alumno alumno) {
    alumno.promedio = promedio(alumno.notas, alumno.cantNotas);
}

void cargarDocumento(Documento& documento) {
    cout << "Ingrese el tipo de documento: ";
    cin >> documento.tipo;
    cout << "Ingrese el numero de documento: ";
    cin >> documento.numero;
    return;
}

Documento cargarDocumento() {
    Documento documento;
    cout << "Ingrese el tipo de documento: ";
    cin >> documento.tipo;
    cout << "Ingrese el numero de documento: ";
    cin >> documento.numero;
    return documento;
}

void imprimir(Documento documento) {
    cout << "Documento: " << documento.tipo << " - " << documento.numero;
    return;
}

void imprimir(Alumno vector[], int cant) {
    for (int i = 0; i < cant; i++) {
        cout << "Nombre: " << vector[i].nombre << endl;

        imprimir(vector[i].documento);
        cout << endl;

        cout << "Legajo: " << vector[i].legajo << endl;
        imprimirNotas(vector[i].notas, vector[i].cantNotas);
        cout << "Promedio: " << promedio(vector[i].notas, vector[i].cantNotas) << endl;
    }
    cout << endl;
}

int main () {

    int cantAlumnos = 0, cantNotas = 0;

    cout << "Ingrese la cantidad de alumnos: ";
    cin >> cantAlumnos;

    cout << "Ingrese la cantidad de notas por alumno (max 4): ";
    cin >> cantNotas;

    Alumno alumnos[cantAlumnos];

    Alumno alumno;

    for (int i = 0; i < cantAlumnos; i++) {

        cargarDocumento(alumnos[i].documento);

        cout << "Ingrese el nombre del alumno: ";
        cin >> alumnos[i].nombre;

        cout << "Ingrese el legajo del alumno: ";
        cin >> alumnos[i].legajo;

        alumnos[i].cantNotas = cantNotas;

        cargarNotas(alumnos[i].notas, cantNotas);

        cout << endl;
    }

    imprimir(alumnos, cantAlumnos);

    system("pause");
    return 0;
}