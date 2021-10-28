#include <iostream>

using namespace std;
#define CANT_DIAS 5
#define CANT_COLUMNAS 4
/*
void cargarDias(int dias[CANT_DIAS]){
    for (int i = 0; i < CANT_DIAS; i++)
    {
        cout << "ingrese la temperatura del dia: ";
        cin >> dias[i];
    }
    return;
}

    
}
int main () {
    string nombre;
    cout << "ingrese un nombre ";
    cin >> nombre;
    cout << endl;
    cout << nombre;
    int dia[CANT_DIAS] = {0};
    cargarDias(dia);
    tendencia(dia, 0, 7);
    
    system("pause");
    return 0;
}*/
struct Documento {
    string tipo;
    int numero;
};

struct Alumno {
    string nombre;
    int legajo;
    Documento documento;
    int nota1;
    int nota2;
    int nota3;
};
float promedio(Alumno alumno){
    return (alumno.nota1 + alumno.nota2 + alumno.nota3) / 3.0;
}

void imprimir(Alumno vector[], int cant){
    for (int i = 0; i < cant; i++)
    {
    cout << "nombre: " << vector[i].nombre << endl;
    cout << "legajo: " << vector[i].legajo << endl;
    cout << "nota 1: " << vector[i].nota1 << endl;
    cout << "nota 2: " << vector[i].nota2 << endl;
    cout << "nota 3: " << vector[i].nota3 << endl;
    cout << "promedio: " << promedio(vector[i]) << endl;  
    }
    cout << endl;
}

void cargarDocumento(Documento& Documento){ 
    cout << "ingrese el tipo de documento; ";
    cin >> documento.tipo;
    cout << "ingrese el numero de decoumento: ";
    cin >> documento.numero;
    return;
}

void imprimirDocumento(Documento documento){
    cout << "documento: " << documento.tipo << " - " << documento.numero;
}

int main() {
    int cantAlumnos = 0;

    cout << "ingrese la cantidad de alumnos: ";
    cin >> cantAlumnos;

    Alumno alumnos[cantAlumnos];

    for (int i = 0; i < cantAlumnos; i++)
    {
        cargarDocumento(alumnos[i].documento);

        cout << "ingrese el nombre del alumno: ";
        cin >> alumnos[i].nombre;

        cout << "ingrese el legajo del alumno: ";
        cin >> alumnos[i].legajo;

        for (int j = 1; j < CANT_COLUMNAS; j++)
        {
            cout << "ingrese las nota 1: ";
            cin >> alumnos[i].nota1;

            cout << "ingrese las nota 2: ";
            cin >> alumnos[i].nota2;

            cout << "ingrese las nota 3: ";
            cin >> alumnos[i].nota3;

            cout << endl;
        }
    }
    
    imprimir(alumnos, cantAlumnos);
    imprimirDocumento(alumnos.documento);
    system("pause");
    return 0;
    }