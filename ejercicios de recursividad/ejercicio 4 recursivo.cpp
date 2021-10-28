#include <iostream>

using namespace std;

/*Ejercicio 4 - Serie Fibonacci
En matemáticas, la sucesión o serie de Fibonacci es la siguiente sucesión infinita de números naturales:
0 , 1 , 1 , 2 , 3 , 5 , 8 , 13 , 21 , 34 , 55 , ...
La sucesión comienza con los números 0 y 1, a partir de estos, cada término es la suma de los dos anteriores
Desarrolle una función recursiva que permita obtener la serie de Fibonacci a un determinado término.
Ejemplo: Para N = 5, la serie de Fibonacci será 0 , 1 , 1 , 2 , 3
*/

int serieFibonacci(int vuelta, int cantNum, int num1, int num2, int num3)
{
    while (vuelta < cantNum)
    {
        num3 = num1 + num2;
        cout << ", " << num3;
        num1 = num2;
        num2 = num3;
        serieFibonacci(vuelta + 1, cantNum, num1, num2, num3);
        return 0;
    }
    return 0;
}

int main()
{

    int N = 0, resultado = 0;
    int X = 0, Y = 1, Z = 1, vuelta = 2;

    cout << "ingrese hasta que numero mayor a 1 quiere hacer la serie Fibonacci: ";
    cin >> N;

    cout << "0, 1";
    resultado = serieFibonacci(vuelta, N, X, Y, Z);
    cout << endl;
    system("pause");
    return 0;
}