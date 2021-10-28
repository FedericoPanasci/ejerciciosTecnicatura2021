#include <iostream>

using namespace std;

struct ST_DOMICILIO 
{
    string calle;
    int altura;
};


struct ST_CASA
{
    string duenio;
    struct ST_DOMICILIO domicilio; 
};

void llenarPorConsola(ST_CASA casas[], int cantcasas, ST_DOMICILIO domicilio){
    for (int i = 0; i < cantcasas; i++)
    {
        cout << "ingrese el nombre del propietario: ";
        cin >> casas[i].duenio;
        cout << endl;
        cout << "ingrese la calle donde vive: ";
        cin >> casas[i].domicilio.calle;
        cout << endl;
        cout << "ingrese la altura de la calle: ";
        cin >> casas[i].domicilio.altura;
        cout << endl;
    }
    return;
}
/*
void llenarCasas0(ST_CASA casas[], int posicion){
    casas[0].duenio = "fede";
    casas[0].calle = "jose hernandez";
    casas[0].altura = 4896;
    return;
}

void llenarCasas1(ST_CASA casas[], int posicion){
    casas[1].duenio = "gabi";
    casas[1].calle = "fleming";
    casas[1].altura = 3500;
    return;
}

void llenarCasas2(ST_CASA casas[], int posicion){
    casas[2].duenio = "jere";
    casas[2].calle = "velez sarfield";
    casas[2].altura = 2000;
    return;
}*/

void imprimir(ST_CASA casas[], int cantCasas){
    for (int i = 0; i < cantCasas; i++)
    {
        cout << casas[i].duenio << " vive en la calle " << casas[i].domicilio.calle << " al " << casas[i].domicilio.altura << endl;
    }
    return;
}

int main () {
    int cantCasas = 3;
    ST_CASA casas[cantCasas];
    ST_DOMICILIO domicilio;
    llenarPorConsola(casas, cantCasas, domicilio);
    // llenarCasas0(casas, 0);
    // llenarCasas1(casas, 1);
    // llenarCasas2(casas, 2);
    imprimir(casas, cantCasas);

    
    system("pause");
    return 0;
}