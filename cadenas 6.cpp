#include <iostream>
#include "string.h"
#include "stdio.h"
using namespace std;

void puntoB(char linea[20]){
    int i = 0, letras = 0, inicio = 0, fin = 0, max = 0, inicioMax = 0, finMax = 0;
    while (linea[i] != '\0')
    {
        if(linea[i] != ' '){
            letras++;
        } else {
            inicio = i - letras;
            fin = i - 1;
            letras;
            if (letras>max)
            {
                max = letras;
                inicioMax = inicio;
                finMax = fin;
            }
            inicio = 0, fin = 0, letras=0;
        }
        i++;
    }
    inicio = i - letras;
    fin = i - 1;
    letras;
    if (letras>max)
    {
        max = letras;
        inicioMax = inicio;
        finMax = fin;
    }
    printf("palabra: ");
    for (int i = inicioMax; i <= finMax; i++)
    {
        printf("%c", linea[i]);
    }
}

void contador(char linea[80]){
    int cant = 1, i = 0;
    while (linea[i] != '\0' && linea[i] != '\n')
    {
        if (linea[i] == ' ')
        {
            cant++;
        }
        i++;
    }
    printf("cantidad de palabras: %d", cant);
}


int main () {
    char linea[80];
    printf("escribir: ");
    fgets(linea, 80, stdin);
    contador(linea);
    puntoB(linea);

    system("pause");
    return 0;
}