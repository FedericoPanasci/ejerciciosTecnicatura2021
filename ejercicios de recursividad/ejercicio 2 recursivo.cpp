#include <iostream>

using namespace std;

/* Ejercicio 2 - Número “e”
La constante matemática “e” puede aproximarse según la siguiente serie numérica:
`e = 1 + 1/1! + 1/2! + 1/3! + .... + 1/n! = 2,718...`
Desarrollar una función recursiva que permita obtener el valor aproximado del número “e” según una cantidad de términos
determinada por el usuario.
Nota: puede desarrollar funciones auxiliares si lo necesita.
*/
int factorial(int N){
    if (N == 0)
    {
        return 1;
    }
    else
    {
        return N * factorial(N-1);
    }
}

float terminoE(float X) {
        if (X == 1){
            return 1;
        }
        else
        {
            return 1.0 / factorial(X - 1) + terminoE(X - 1);
        }
        return 0;
}


int main () {
    int termino = 0;
    float resultado = 0;

    cout << "ingrese la cantidad de terminos a calcular con 'e': ";
    cin >> termino;

    resultado = terminoE(termino);
    cout << "su resultado es: " << resultado << endl;
    system("pause");
    return 0;
}