#include <iostream>

using namespace std;

bool primos (int cantidad) {
    for (int i = 1; i <= cantidad - 1; i++)
    {
        if (cantidad == 2 || cantidad == 3 || cantidad == 5 || cantidad == 7)
        {
            return true;
        }
        if (cantidad % cantidad == 0 && cantidad % 2 != 0 && cantidad % 3 != 0 && cantidad % 5 != 0 && cantidad % 7 != 0)
        {
            return true;
        }   
        
    }
    return false;
}
int main () {

    int cantidad = 0;

    cout << "ingrese la cantidad de numeros primos que quiere saber: ";
    cin >> cantidad;

    int i = 0;
    int numero = 1;
    while (i<cantidad)
    {
        if (primos(numero) == true)
        {
            i = i + 1;
            cout << "num =" << numero << endl;
        }
    numero = numero + 1;
    }
    
    system ("pause");
    return 0;
}