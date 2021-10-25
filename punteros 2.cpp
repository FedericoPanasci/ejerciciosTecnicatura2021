#include <iostream>
#include "stdlib.h"
using namespace std;

int main () {
    int num = 10;
    int *ptrnum = NULL;
    ptrnum = &num;

    printf("valor %d en pos %p\n", *ptrnum/*direccion de memoria guardada*/, ptrnum/*imprimo la dir de la memoria*/);
    free(ptrnum);
    ptrnum = (int*)malloc(sizeof(int));
    *ptrnum = 5;
    printf("valor %d en pos %p\n", *ptrnum, ptrnum);
    system("pause");
    return 0;
}