#include <iostream>
#include "stdio.h"
using namespace std;

void multiplicar(int vec[]){
    
    for (int i = 1; i < 10; i++)
    {
        vec[i] = vec[i] * vec[i-1];
        
        printf("%d\n", vec[i]);
    }
}

int main () {
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    multiplicar(vec);
    for (int i = 0; i < 10; i++)
    {
        printf("posicion: %d, valor: %d\n", i+1, vec[i]);
    }
    printf("\n");
    int j = 1;
    for (int i = 9; i >= 0; i--)
    {
        printf("posicion: %d, valor: %d\n", j, vec[i]);
        j++;
    }
    
    system("pause");
    return 0;
}