#include <iostream>

using namespace std;

/*
Ejercicio 3 - Cuenta regresiva
Desarrolle una función recursiva que dado un número entero positivo permita obtener la sumatoria de todos los números enteros que
se encuentran entre 0 y el número ingresado. Por ejemplo:
a. Ingresado el número 5, la función debe devolver 15 porque 0 + 1 + 2 + 3 + 4 + 5 = 15
b. OPCIONAL modifique la función anterior para que se impriman los resultados parciales. Por ejemplo, para el número 5, la salida
sería:
0
1
3
6
10
15
*/

void cuentaRegresiva(int num, int X, int Y, int Z) {
    if (Y <= num)
    {
        Z = X + Y;
        cout << Z << endl;
        X = Z;
        cuentaRegresiva(num, X, Y + 1, Z);
        return;
    }
}


int main () {
    int N = 0, vuelta = 0, X = 0, Y = 0, Z = 0;
    cout << "elija un numero para realizar la serie: ";
    cin >> N;

    cuentaRegresiva(N, X, Y, Z);
    
    system("pause");
    return 0;
}