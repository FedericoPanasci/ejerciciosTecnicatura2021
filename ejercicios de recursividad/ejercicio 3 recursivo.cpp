#include <iostream>

using namespace std;

/* Ejercicio 3 - Conjetura de Collatz
La secuencia de Collatz de un número entero se construye de la siguiente forma: * Si el número es par, se lo divide por dos; * Si es
impar, se le multiplica tres y se le suma uno; * La sucesión termina al llegar a uno.
La conjetura de Collatz afirma que, al partir desde cualquier número, la secuencia siempre llegará a 1. A pesar de ser una afirmación a
simple vista muy simple, no se ha podido demostrar si es cierta o no.
Desarrolle un programa que entregue la secuencia de Collatz de un número entero.
Ejemplo Para n = 18, la conjetura de Collatz sería:
18 9 28 14 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
*/
// y aca arranca con toda la funcion

int funcionCollatz(int X) {
    if (X == 1)
    {
        return X;
    }
    if (X % 2 != 0)
    {   
        X = X * 3 + 1;
        cout << " " << X << " ";
        return funcionCollatz(X);
    }
    if (X % 2 == 0)
    {
        X = X / 2; 
        cout << " " << X << " ";
        return funcionCollatz(X);
    }
}
int main () {
    int num = 0;
    int resultado = 0;
    cout << "ingrese un numero que desea saber la secuencia Collatz: "; 
    cin >> num;
    resultado = funcionCollatz(num);
    system("pause");
    return 0;
}