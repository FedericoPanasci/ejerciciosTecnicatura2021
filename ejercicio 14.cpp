#include <iostream>
using namespace std;
int main () {
    int numero;
    float promedio;
    int sumatoria;
    int cantidadmayores;
numero = 0, promedio = 0, sumatoria = 0, cantidadmayores = 0;

    
for (int i = 0; i < 5; i++) {
    cout << "ingrese un numero" << endl;
    cin >> numero;

    if (numero > 100) {
        promedio = promedio + numero;
        cantidadmayores++;
    }
    if (numero < -10) {
        sumatoria = sumatoria + numero;
    }
    
}
promedio = promedio / cantidadmayores;
cout << "el promedio de los mayores que 100 es: " << promedio << endl;
cout << "la sumatoria de los menores que - 10 es: " << sumatoria << endl;

return 0;
}