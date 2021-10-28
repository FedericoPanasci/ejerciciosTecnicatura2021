#include <iostream>
using namespace std;
int main ()
{
    int fecha8, dia1, mes2, anio3;
    

    cout << "ingrese fecha de 8 digitos" << endl;

    cin >> fecha8;
    
    dia1 = (fecha8/1000000);

    mes2 = (fecha8/10000)-dia1*100;

    anio3 = fecha8%10000;

    cout << dia1, cout << "/", cout << mes2, cout << "/", cout << anio3 << endl;
    
system("pause");
return 0;
}