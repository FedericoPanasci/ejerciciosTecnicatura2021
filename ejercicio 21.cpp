#include <iostream>
using namespace std;
int main () 
{
    float valor = 0;
    float mayor = 0;
    float menor = 0;
    int n = 0, posicionMenor = 0, posicionMayor = 0;
    int contador = 0;

    cout << "ingrese N" << endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
    contador = contador + 1;

    cout << "ingrese valor: " << endl;
    cin >> valor;

    
    if (valor > mayor || i == 0) {
        mayor = valor;
        posicionMayor = i;
    }
    if (valor < menor || i == 0) {
        menor = valor;
        posicionMenor = i;
    }
    }
    cout << "el mayor es: " << mayor << " y fue ingresado en la posicion: " << posicionMayor + 1 << " del conjunto" << endl;   
    cout << "el menor es: " << menor << " y fue ingresado en la posicion: " << posicionMenor + 1 << " del conjunto" << endl;

    system ("pause");
    return 0;
}