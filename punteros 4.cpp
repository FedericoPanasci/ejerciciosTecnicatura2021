#include <iostream>
#include "string.h"
using namespace std;

typedef struct{
    char name[30];
    int edad;
}persona;

void cambio(persona x){
    printf("n = %s y edad = %d\n", x.name, x.edad);
    x.edad = 28;
    strcpy(x.name, "fede");
    printf("n = %s y edad %d\n", x.name, x.edad);
}

int main () {
    persona alguien;
    alguien.edad = 30;
    strcpy(alguien.name, "kokumo");
    cambio(alguien);
    printf("n = %s y edad = %d\n", alguien.name, alguien.edad);
    system("pause");
    return 0;
}