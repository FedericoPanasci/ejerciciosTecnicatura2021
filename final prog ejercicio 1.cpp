#include <iostream>

using namespace std;
#define TAMANIO 3

struct VALIDEZ
{
    int n;
    bool utilizado;
};

void llenarNum(VALIDEZ num[], int cant){
    for (int i = 0; i < cant; i++)
    {
        num[i].n = i+1;
        num[i].utilizado = false;
    }
}

bool validarMatriz(int vec[TAMANIO][TAMANIO], VALIDEZ num[], int cant){
    int i = 0, k = 0;
    int valor = 0;
    for (i = 0; i < TAMANIO; i++)
    {
        for (k = 0; k < TAMANIO; k++)
        {
            valor = vec[i][k];
            if (num[valor-1].utilizado == false)
            {
                num[valor-1].utilizado = true;
            }
            else
            {
                return false;
            }           
        }
    }
    return true;    
}

void imprimirMatriz(int vec[TAMANIO][TAMANIO]){
    for (int i = 0; i < TAMANIO; i++)
    {
        for (int k = 0; k < TAMANIO; k++)
        {
            cout << "| " << vec[i][k] << " |";
        }
        cout << endl;
        cout << "---------------" << endl;
    }
    cout << endl;
}

int main () {
    int vec[TAMANIO][TAMANIO] = {0};
    int cant = 9;
    VALIDEZ num[cant];
    llenarNum(num, cant);
    bool valido = validarMatriz(vec, num, cant);
    imprimirMatriz(vec);
    if (valido == true)
    {
        cout << "Es una region valida." << endl;
    }
    else
    {
        cout << "Es una region invalida." << endl;
    }
        
    system("pause");
    return 0;
}