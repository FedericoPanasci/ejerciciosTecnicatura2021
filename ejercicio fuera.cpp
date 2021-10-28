#include <iostream>

using namespace std;

bool esDivisor (int y) {

    bool resultado;
    if (y > 0)
    {
        resultado = true;
    }
    else
    {
        resultado = false;
    }
    return resultado;
}

int main () {

    int num1, num2;

    cout << "ingrese num 1 ";
    cin >> num1;
    cout << "ingres el 2 ";
    cin >> num2;

    bool resultado = esDivisor (num2);

    if (resultado == true){ 
        cout << "es divisible" << endl;
    }
    else
    {
        cout << "no es divisible" << endl;
    }
    
    system ("pause");
    return 0;
}