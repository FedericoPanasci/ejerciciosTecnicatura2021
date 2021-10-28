#include <iostream>

using namespace std;

int tabla(int x, int y){
    int resultado = 0;
        resultado = x * y;
        return resultado;
}
int main () {
    int num = 0;
    int resultado = 0;
    cout << "ingrese el numero del que quiere saber la tabla: ";
    cin >> num;
    int x = 1;
    int cantidad = 0;
    cout << "ingrese la cantidad de numeros que quiere que tenga la tabla de multiplicar (no puede ser negativo): ";
    cin >> cantidad;
    while (x <= cantidad)
    {
        resultado = tabla(num, x);
        cout << num << "X" << x << "=" << resultado << endl; 
        x++;
    }
    system("pause");
    return 0;
}