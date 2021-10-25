#include <iostream>
#include "string.h"
#include <stdlib.h>
using namespace std;

int main () {
    //char *miPuntero = (char*)malloc(sizeof(char)*10);
    char *ptrChar = (char*)malloc(sizeof(char)*10);
    ptrChar = strcpy(ptrChar, "hola");

    //char miChar[10] = "hola";
    //char *ptrChar = miChar;

    
    /*a) Imprimir por pantalla el puntero con el formateador %s.
    b) Imprimir la dirección de memoria del puntero.
    c) Imprimir el valor del puntero.
    d) Imprimir la dirección de memoria miPuntero[0] y relaciónelo con el punto anterior.
    e) Imprimir el valor miPuntero[0], luego ejecute miPuntero++ y vuelva a imprimir miPuntero[0].
    Analice el resultado y concluya.    */
    //punto A
    printf("palabra %s\n", ptrChar);
    //punto B
    printf("direccion de memoria %p\n", &ptrChar);
    //punto C
    printf("valor %c\n", *ptrChar);
    //punto D
    printf("direccion de memoria [0] %p\n", ptrChar[0]);
    //punto E
    printf("valor de posicion [0] con miPuntero++ %c\n", ptrChar[0]);
    ptrChar++;
    printf("nuevo valor avanzado con ++ %s\n", ptrChar);

    system("pause");
    return 0;
}