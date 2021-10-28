#include <iostream>
using namespace std;
int main () {
    int mes = 0, anio = 0;

    cout << "ingrese un mes en numero correspondiente: " << endl;
    cin >> mes;

    cout << "ingrese año del mes: " << endl;
    cin >> anio;

switch (mes) {
    case 1:
    case 3: 
    case 5: 
    case 7: 
    case 8: 
    case 10: 
    case 12: cout << "su mes tiene 31 dias";
    break;
    case 4:
    case 6:
    case 9:
    case 11: cout << "su mes tiene 30 dias";
    break;
    case 2: if (anio % 4 == 0 || anio % 400 == 0) 
    {
       cout << "su mes tiene 29 dias";
    }
    else
    {
        cout << "su mes tiene 28 dias";
    }
}
system("pause");
return 0;
}
