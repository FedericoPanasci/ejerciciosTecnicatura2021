#include <iostream>
using namespace std;



/*
Un buque de carga traslada 100 contenedores a tres diferentes puertos del país.
Los puertos se identifican con los números 1, 2 y 3.
De cada contenedor que el buque traslade se registran los siguientes datos:
- Identificación del contenedor
- Peso del contenedor en kg
- Puerto de arribo (un valor de 1 a 3).
Se pide calcular e informar:
1) El peso total que el buque debe trasladar
2) La identificación del contenedor de mayor peso
3) La cantidad de contenedores que debe trasladar a cada puerto
*/

struct Contenedor {
    int id;
    float peso;
    int puerto;
};

Contenedor cargarContenedor() {
    Contenedor contenedor;
    cout <<"Id:";
    cin >> contenedor.id;

    cout <<"Peso (Kg.):";
    cin >> contenedor.peso;

    cout <<"Puerto (1,2,3):";
    cin >> contenedor.puerto;

    return contenedor;
}

int main () {

    int cant = 5;
    Contenedor contenedores[cant];

    int cantPorPuerto[3] = {0};

    for (int i = 0; i < cant; i++) {
        contenedores[i] = cargarContenedor();
    }

    float pesoTotal = 0;
    for (int i = 0; i < cant; i++) {
        pesoTotal += contenedores[i].peso;
    }

    Contenedor maxPeso = contenedores[0];
    for (int i = 1; i < cant; i++){
        if(maxPeso.peso < contenedores[i].peso) {
            maxPeso = contenedores[i];
        }
    }

    for (int i = 0; i < cant; i++) {
        int puerto = contenedores[i].puerto;
        cantPorPuerto[puerto - 1]++;
    }

    cout << "Peso total: " << pesoTotal << endl;
    cout << "El contenedor de mayor peso es: " << maxPeso.id << "(" << maxPeso.peso << " Kg.)" << endl;

    for (int i = 0; i < 3; i++) {
            cout << "Cantidad contenedores puerto " << i + 1 << ": " << cantPorPuerto[i] << endl;
    }








    system("pause");
    return 0;
}