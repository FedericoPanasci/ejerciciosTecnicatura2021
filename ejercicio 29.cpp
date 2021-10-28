#include <iostream>
using namespace std;

int main () {
    int numero = 0;
    int unidad = 0, decena = 0, centena = 0, unidadDeMil = 0;

    cout << "ingrese un numero entre 1 y 3999" << endl;
    cin >> numero;

    unidad = numero % 10;
    decena = (numero % 100) / 10;
    centena = (numero % 1000) / 100;
    unidadDeMil = (numero % 10000) / 1000;

    string romano = "";

    for (int i = 0; i < unidadDeMil; i++){
        romano += "M";
    }

switch (centena)
{
    case 1:
    case 2:
    case 3: 
        for (int i = 0; i < centena; i++)
        {
            romano += "C";
        }
        break;
    case 4:
        romano += "D";
        break;
    case 5:
        romano == "V";

default:
    break;
}
}