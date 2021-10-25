#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

void numeroValido(char telefono[]){
    int i = 0, cantidad = 0;
    if (*(telefono) == '+')
    {
        i++;
    }
    else
    {
        printf("no es valido");
        return;
    }   
    
    while (*(telefono+i) != '\n')
    {
       
        if (isdigit(*(telefono+i)) || *(telefono+i) == '-')
        {
            cantidad++;
        }
        else
        {
            printf("no es valido");
            return;
        } 
    }
    i = cantidad - 9;
    int guion = 0;
    while (*(telefono+i) != '\n')
    {
        if (isdigit(*(telefono+i))){
            i++;
        } else if (*(telefono+i) == '-')
        {
            guion++;
            i++;
            if (guion <= 1)
            {
                printf("no es valido");
                return;
            }
        } else
        {
            printf("no es valido");
            return;
        }        
    }
}

int main () {
    char telefono[80];
    printf("escriba la palabra a verificar la cantidad de vocales: ");
    fgets(telefono, 80, stdin);

    numeroValido(telefono);

    system("pause");
    return 0;
}