#include <iostream>
#include "string.h"
#include "ctype.h"
using namespace std;

// void valido(char pal[]){
//     int token;
//     token = atoi(strtok(pal, "."));
//     while(token != NULL){
//         token = atoi(strtok(NULL, "."));

//     }
// }

void valido(char pal[]){
    char *token;
    token = strtok(pal, ".");
    while (token != NULL)
    {
        int number = atoi(token);
        if (isdigit(number) || number == 0)
        {
            printf("No es ip valido\n");
            return;
        }
        token = strtok(NULL, ".");
    }
    printf("ip valido\n");
    return;
}

int main () {
    char pal[15];
    printf("ingrese ip: ");
    fgets(pal, 15, stdin);
    valido(pal);
    system("pause");
    return 0;
}