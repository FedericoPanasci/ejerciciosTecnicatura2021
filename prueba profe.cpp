#include <iostream>
using namespace std;
int main ()
{
int nro;
int cantidad = 0;
int total = 0;
float promedio;

cout << "ingrese un numero: ";
cin >> nro;

while (nro != 0)
{
    cout << endl;
    cantidad = cantidad + 1;
    total = total + nro;

    cout << "ingrese un numero: ";
    cin >> nro;

}

promedio = (float) total / cantidad;
cout << "promedio: " << promedio << endl;


}