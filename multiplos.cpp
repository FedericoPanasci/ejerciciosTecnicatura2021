#include <iostream>

using namespace std;

int main () {

    int num = 0;
    int resultado = 0;
    cout << "ingrese el numero del que quiere saber la tabla: ";
    cin >> num;

    for (int i = 1; i < 11; i++)
    {
        resultado = num * i;
        cout << num << "x" << i << "=" << resultado << endl;
    }
    
    system("pause");
    return 0;
}