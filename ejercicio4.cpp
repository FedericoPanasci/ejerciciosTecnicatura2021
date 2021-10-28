#include <iostream>
using namespace std;
int main()
{
    int valorEntero; 
    float resA, resB, resC;
    cout << "ingrese un valor ENTERO" << endl;

    cin >> valorEntero;

    resA = valorEntero/5;

    resB = valorEntero%5;

    resC = resA/7;

    cout << "los resultados son: A: ", cout << resA, cout << ". B: ", cout << resB, cout << ". C: ", cout << resC << endl;

}

