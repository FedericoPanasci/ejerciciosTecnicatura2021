#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

int noEsVocal(char pal[]){
    int cantidad = 0, i = 0;
    while (*(pal+i) != '\n')
    {
        if (*(pal+i) == 'a' || *(pal+i) == 'e' || *(pal+i) == 'i' || *(pal+i) == 'o'  || *(pal+i) == 'u')
        {
        }
        else
        {
            cantidad++;
        }        
        i++;
    }
    return cantidad;
}


int main () {
    char pal[80];
    printf("escriba la palabra a verificar la cantidad de vocales: ");
    fgets(pal, 80, stdin);

    int cantidad = noEsVocal(pal);

    printf("la cantidad de no vocales son: %d", cantidad);

    system("pause");
    return 0;
}