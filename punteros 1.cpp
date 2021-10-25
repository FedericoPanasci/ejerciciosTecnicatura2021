#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
    int num = 5;
    char pal[10] = "palabra";
    float dec = 0.5;

    int *ptrNum = &num;
    char *ptrPal = pal;
    float *ptrDec = &dec;

    printf("num = %d - pos %p\n", *ptrNum, ptrNum);
    printf("valor %f - pos %p\n", *ptrDec, ptrDec);
    int i = 0;
    while (*(ptrPal+i) != '\0')
    {
        printf("letra %c - pos %p\n", *(ptrPal +i), ptrPal[i]);
        i++;
    }
    

    system("pause");
    return 0;
}