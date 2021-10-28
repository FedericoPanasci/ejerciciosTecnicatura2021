#include <iostream>

using namespace std;

bool siEsDigito (char caracter) {

    return (caracter == '0' || caracter == '1' ||caracter == '2' || caracter == '3' || caracter == '4' || caracter == '5' || caracter == '6' || caracter == '7' ||caracter == '8' ||caracter == '9');
    }

int main () {

    char tecla;

    cout << "ingrese un caracter " << endl;
    cin >> tecla;

    bool esDigito = siEsDigito(tecla); 

    if (esDigito == true) {
        cout << "su caracter es un numero" << endl;
    }
    else
    {
        cout << "su caracter no es un numero" << endl;
    }
    


    system ("pause");
    return 0;
}