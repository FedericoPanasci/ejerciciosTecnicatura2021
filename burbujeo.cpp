#include "stdio.h"
void ordenar(int arr[], int n)
{
    int aux;
    int i = 0;
    bool ordenado = false;
    while (i < n && !ordenado)
    {
        ordenado = true;
        
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                ordenado = false; 
            }
        }
        i++;
    }
}

void mostrar(int arr[]){
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
}