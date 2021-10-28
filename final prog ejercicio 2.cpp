#include <iostream>

using namespace std;
#define MAX 100

void llenarVec(int vec[MAX][MAX], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        for (int j = 0; j < cant; j++)
        {
            cout << "ingrese valor: ";
            cin >> vec[i][j];
        }
    }
}

bool validar(int vec[MAX][MAX], int cant)
{
    int result1 = 0, result2 = 0, k = 0;
    while (k < cant)
    {
        result1 = result1 + vec[0][k];
        k++;
    }
    //filas
    for (int i = 1; i < cant; i++)
    {
        for (int j = 0; j < cant; j++)
        {
            result2 = result2 + vec[i][j];
        }
        if (result1 != result2)
        {
            return false;
        }
        result2 = 0;
    }
    //columnas
    for (int i = 1; i < cant; i++)
    {
        for (int j = 0; j < cant; j++)
        {
            result2 = result2 + vec[j][i];
        }
        if (result1 != result2)
        {
            return false;
        }
        result2 = 0;
    }
    //diagonal principal
    for (int i = 0; i < cant; i++)
    {
        result2 = result2 + vec[i][i];
    }
    if (result1 != result2)
    {
        return false;
    }
    result2 = 0;
    //diagonal secundaria
    k = 0;
    for (int i = cant - 1; i < 0; i--)
    {
        result2 = result2 + vec[k][i];
        k++;
    }
    if (result1 != result2)
    {
        return false;
    }
    return true;
}

void imprimir(int vec[MAX][MAX], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        for (int k = 0; k < cant; k++)
        {
            cout << "| " << vec[i][k] << " |";
        }
        cout << endl;
        cout << "---------------" << endl;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "ingrese la cantidad de filas y columnas que desea (hasta 100): ";
    cin >> n;

    int vec[MAX][MAX];
    llenarVec(vec, n);
    bool valido = validar(vec, n);
    imprimir(vec, n);
    if (valido == true)
    {
        cout << "Es magico." << endl;
    }
    else
    {
        cout << "No es magico." << endl;
    }
        
    system("pause");
    return 0;
}