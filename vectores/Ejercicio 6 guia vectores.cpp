#include <iostream>

using namespace std;
/*Ingresar un valor entero N (< 40). A continuación ingresar un conjunto VALOR de N elementos.
Determinar e imprimir el valor máximo y la posición del mismo dentro del conjunto. Si el máximo no es
único, imprimir todas las posiciones en que se encuentra.*/

void ingresarValores(int casillas[], int cantidad) {
    for (int i = 0; i < cantidad; i++)
    {
        cout << "ingrese un valor: ";
        cin >> casillas[i];
        cout << endl;
    }
}
int saberMayor(int casillas[], int cantidad){
    int mayor = 0;
    int casillaMayor = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (casillas[i] > mayor)
        {
            mayor = casillas[i];
        }
    }
    cout << "el valor mas grande es " << mayor << endl;
    return mayor;
}
void imprimirCasillas(int casillas[], int cantidad, int mayor){
    cout << "y se encontro en la/s casilla/s: " << endl;
    for (int i = 0; i < cantidad; i++)
    {
        if (casillas[i] == mayor)
        {
            cout << i + 1 << endl;
        }
    }
    return;
}
int main () {

    int cantidad = 0;
    cout << "ingrese la cantidad de numeros que va a necesitar: ";
    cin >> cantidad;

    int valores[cantidad] = {0};

    ingresarValores(valores, cantidad);
    int mayor = saberMayor(valores, cantidad);
    imprimirCasillas(valores, cantidad, mayor);

    system("pause");
    return 0;
}