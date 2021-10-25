#include <iostream>
#include "funcioneje2.h"
/*Implementar un sistema que solicite indefinidamente números por pantalla hasta que se
ingrese un valor de corte e...
a) Imprimir el número más alto.
b) Imprimir el número más bajo.
c) Imprimir el promedio.
*/
using namespace std;


int main () {
    int num = 0, alto = 0, bajo = 0, promedio = 0, i = 0, suma = 0;
    printf("ingrese un numero (0 para finalizar): ");
    scanf("%d", &num);
    while (num > 0)
    {
        alto = numAlto(num, alto);
        bajo = numBajo(num, bajo);
        i++;
        suma = suma + num;
        promedio = promedioSum(promedio, suma, i);
        

        printf("ingrese un numero (0 para finalizar): ");
        scanf("%d", &num);
    }
    printf("el numero mas alto es %d, el mas bajo es %d y el promedio es %d", alto, bajo, promedio);

    system("pause");
    return 0;
}