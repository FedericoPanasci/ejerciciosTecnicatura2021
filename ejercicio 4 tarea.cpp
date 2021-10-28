#include <iostream>

using namespace std;

bool siEsDigito (char caracter) {

    return (caracter == 'A' || caracter == 'E' ||caracter == 'I' || caracter == 'O' || caracter == 'U');
    }

int main () {

    char tecla;

    cout << "ingrese una letra (solo en mayuscula): " << endl;
    cin >> tecla;

    bool esDigito = siEsDigito(tecla); 

    if (esDigito == true) {
        cout << "su letra es vocal." << endl;
    }
    else
    {
        cout << "su letra no es una vocal." << endl;
    }
    system("pause");
    return 0;
}