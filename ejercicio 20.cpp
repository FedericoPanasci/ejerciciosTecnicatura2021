#include <iostream>

using namespace std;

int main () {

    int valor = 0, mayor = 0, menor = 0, posicionMay = 0, posicionMen = 0;

    for (int i = 1; i < 4; i++)
    {
        cout << "ingrese un numero: ";
        cin >> valor;
        
        if (valor < menor || i == 1)
        {
            menor = valor;
            posicionMen = i;
        }     
        if (valor>mayor || i == 1)
        {
            mayor=valor;
            posicionMay = i;
        }
    }
    cout << "su numero mayor es: " << mayor << ", y fue ingresado en la posicion: " << posicionMay << endl;
    cout << "su numero menor es: " << menor << ", y fue ingresado en la posicion: " << posicionMen << endl;

    system("pause");


    return 0;
}