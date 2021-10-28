#include <iostream>

using namespace std;
/*
Crápulo
Dado un número entero positivo, su crápulo es un número que se obtiene sumando los dígitos que lo componen, si el valor de la suma
es menor que 10. Si la suma es mayor que 10, el crápulo es el crápulo de la suma de los dígitos.
Ejemplo:
Número Suma Crápula
7 7 7
13 4 4
492 15 6
Se pide, dados trés números:
Realizar una función que calcule su crápulo.
Realizar una función que permita Imprimir los crápulos de menor a mayor
*/

int elCrapulo(int num){
    int resultado = 0;
    
    while (num >= 10)
    {
        resultado = resultado + (num % 10);
        num = num / 10;
    }
    if (num < 10)
    {
        resultado = resultado + num;
    }
    if (resultado >= 10)
    {
        resultado = elCrapulo(resultado);
    }
    
    return resultado;
}
void suOrden(int num1, int num2, int num3){
    int crapuloMay = 0, crapuloMen = 0, crapuloIntermedio = 0, num = 0;
    if (num1 >= num2 && num1 >= num3)
    {
        if (num2 > num3 || num2 == num3)
        {
            crapuloMay = num1;
            crapuloIntermedio = num2;
            crapuloMen = num3;
        }
        else
        {
            crapuloMay = num1;
            crapuloIntermedio = num3;
            crapuloMen = num2;
        }
    }
    if (num2 >= num1 && num2 >= num3)
    {
        if (num1 > num3 || num1 == num3)
        {
            crapuloMay = num2;
            crapuloIntermedio = num1;
            crapuloMen = num3;
        }
        else
        {
            crapuloMay = num2;
            crapuloIntermedio = num3;
            crapuloMen = num1;
        }
    }
    if (num3 >= num1 && num3 >= num2)
    {
        if (num1 > num2 || num1 == num2)
        {
            crapuloMay = num3;
            crapuloIntermedio = num1;
            crapuloMen = num2;
        }
        else
        {
            crapuloMay = num3;
            crapuloIntermedio = num2;
            crapuloMen = num1;
        }
    }    
    cout << "su orden de menor a mayor es " << crapuloMen << ", " << crapuloIntermedio << ", " << crapuloMay << endl;
    return;
}

int main () {

    int num = 0, i = 0, crapula = 0, suma = 0, crapula1 = 0, crapula2 = 0, crapula3 = 0;

    for (i = 1; i < 4; i++)
    {  
    cout << "ingrese un numero al cual calcular su crapulo: ";
    cin >> num;
    if (num > 0)
    {
        if (i == 1) {
            crapula1 = elCrapulo(num);
            cout << "Del numero ingresado el crapulo es " << crapula1 << endl;
        } 
        if (i == 2 )
        {
            crapula2 = elCrapulo(num);
            cout << "Del numero ingresado el crapulo es " << crapula2 << endl;
        }
        if (i == 3)
        {
            crapula3 = elCrapulo(num);
            cout << "Del numero ingresado el crapulo es " << crapula3 << endl;
        }
    }
    }
    suOrden(crapula1, crapula2, crapula3);   
    system ("pause");
    return 0;
}