#include <iostream>

using namespace std;

/*Ejercicio 1 - Serie L
Desarrollar una función recursiva que permita dada la cantidad de términos generar la siguiente serie:
`N = 5 ==> {0, 1, 3, 6, 10, 15}`
*/

int serieL(int X) {
    if (X == 0)
    {
        return 0;
    }
    else
    {
        return X + serieL(X - 1);
    }
}

int main () {
    int num = 0;
    int resultado = 0;
    cout << "ingrese un numero a calcular: ";
    cin >> num;
    
    resultado = serieL(num);
    cout << resultado << endl;
    system ("pause");
    return 0;

}