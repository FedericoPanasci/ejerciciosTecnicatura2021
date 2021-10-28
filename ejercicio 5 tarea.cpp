#include <iostream>

using namespace std;

int esMaximo (int x, int y) {
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
    
}
int main () {

    int num1 = 0, num2 = 0;

    cout << "ingrese un numero: ";
    cin >> num1;

    cout << "ingrese otro numero: ";
    cin >> num2;

    int resultado = esMaximo (num1, num2);

    cout << "su numero maximo es " << resultado << endl;

    system ("pause");
    return 0;
}