#include <iostream>

using namespace std;

struct Contenedor
{
    int id;
    float peso;
    int puerto;
};
Contenedor cargarContenedores() {
    Contenedor contenedor;
    cout << "ingrese num de contenedor ";
    cin >> contenedor.id;
    
    cout << "ingrese peso ";
    cin >> contenedor.peso;
    
    cout << "ingrese opuerto ";
    cin >> contenedor.puerto;

    return contenedor;
}

int main () {
    int cant = 5;
    Contenedor contenedores[cant];

    int cantPorPuerto[3] = {0};

    for (int i = 0; i < cant; i++) {
        contenedores[i] = cargarContenedores();
    }
    
    float pesoTotal = 0;

    for (int i = 0; i < cant; i++)
    {
        pesoTotal += contenedores[i].peso;
    }
    
    Contenedor maxPeso = contenedores[0];
    for (int i = 0; i < cant; i++)
    {
        if (maxPeso.peso > contenedores[i].peso) {
        maxPeso = contenedores[i];
        }
    }

    for (int i = 0; i < cant; i++)
    {   
        int puerto = contenedores[i].puerto;
        cantPorPuerto[puerto - 1]++;
    }
    
    cout << "Peso total: " << pesoTotal << endl;
    cout << "identificacion de contenedor de mayor peso: " << maxPeso.id << "(" << maxPeso.peso << " Kg.)" << endl;
    
    for (int i = 0; i < 3; i++)
    {
        cout << "cantidad de contenedores por puerto: " << i + 1 << ": " << cantPorPuerto[i] << endl;
    }
system("pause");
return 0;
}