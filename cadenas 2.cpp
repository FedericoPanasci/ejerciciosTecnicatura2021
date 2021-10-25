#include <iostream>
#include "string.h"
using namespace std;

void palindromo(char pal[]){
    int largo = 0;
    largo = strlen(pal) - 2;
    // while (pal[largo] != '\0')
    // {
    //     largo++;
    // }
    // largo--;
    int medio = largo /2, i = 0;
    while (i < medio)
    {
        if (*(pal+i) == *(pal + largo-i))
        {
            i++;
        }else{
            printf("no es palindromo\n");
            return;
        }
    }
    printf("es palindromo\n");
}

int main () {
    char pal[80];
    printf("escriba la palabra a verificar si es palindromo: ");
    fgets(pal, 80, stdin);
    palindromo(pal);
    
    system("pause");
    return 0;
}