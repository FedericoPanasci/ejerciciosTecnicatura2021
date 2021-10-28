#include <iostream>
#include <time.h>
#define CANTMAX 100

using namespace std;

void generarVector(int vec[], int n)
{
    int k = 0;
    while (k < CANTMAX)
    {

        n = rand() % 1000 + 1;
        int x = 2;
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                x++;
            }
        }

        bool esP = true;
        if (x > 2)
        {
            esP = false;
        }

        if (esP)
        {
            vec[k] = n;
            k++;
        }
    }
}

void imprimirVectorOriginal(int vec[]){
    cout << "Vector Original: " << endl;
    for (int i = 0; i < CANTMAX; i++)
    {
        cout << "Numero: " << vec[i] << endl;
    }
}

void imprimirNuevoVector(int vec[]){
        cout << "Nuevo vector: " << endl;
        for (int i = 0; i < CANTMAX; i++)
        {
            cout << "Numero: " << vec[i] << endl;
        }
}

void ordenarVector(int vec[]){
    int aux;
        for (int i = 0; i < CANTMAX - 1; i++)
        {
            for (int j = 0; j < CANTMAX - i - 1; j++)
            {
                if (vec[j] <= vec[j + 1])
                {
                    aux = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = aux;
                }
            }
        }
    imprimirNuevoVector(vec);
}

void imprimirVector(int vec[])
{
    imprimirVectorOriginal(vec);
    ordenarVector(vec);    
}

int main()
{
    int vec[CANTMAX];
    int numero;
    srand(time(NULL));

    generarVector(vec, numero);

    imprimirVector(vec);

    system("pause");
    return 0;
}