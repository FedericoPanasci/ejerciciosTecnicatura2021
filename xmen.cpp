#include <iostream>

using namespace std;
#define MAX 6

bool comprobarFila(string xmen[][MAX], int N)
{
    int contador = 0;
    int i = 0;
    int j = 0;
    string key = "a";
    while (i < N && j < N)
    {
        key = xmen[i][j];
        while (i < N && j < N && key == xmen[i][j + 1])
        {
            contador++;
            j++;
        }
        if (contador == 4)
        {
            return true;
        }
        else
        {
            contador = 0;
            j = 0;
        }
        i++;
    }
    return false;
}

bool comprobarColumnas(string xmen[][MAX], int N)
{
    int contador = 0;
    int i = 0;
    int j = 0;
    string key = "a";
    while (i < N && j < N)
    {
        key = xmen[i][j];
        while (i < N && j < N && key == xmen[i + 1][j])
        {
            contador++;
            i++;
        }
        if (contador == 3)
        {
            return true;
        }
        else
        {
            contador = 0;
            i = 0;
        }
        j++;
    }
    return false;
}

bool comprobarDiagonalesParalelasPrincipal(string xmen[][MAX], int N)
{
    int contador = 0;
    int vueltaFila = 0;
    int vueltaColumna = 0;
    int i = vueltaFila;
    int j = vueltaColumna;
    string key = "a";
    while (i < N && j < N)
    {
        key = xmen[i][j];
        while (i < N && j < N && key == xmen[i + 1][j + 1])
        {
            contador++;
            i++;
            j++;
        }
        if (contador == 3)
        {
            return true;
        }
        else
        {
            contador = 0;
            i++;
            j++;
        }
        if (j == N)
        {
            i = vueltaFila;
            j = vueltaColumna++;
        }
        if (vueltaColumna == N)
        {
            vueltaFila++;
            vueltaColumna = 0;
        }
    }
    return false;
}

bool comprobarDiagonalesParalelasSecundaria(string xmen[][MAX], int N)
{
    int contador = 0;
    int vueltaFila = 0;
    int vueltaColumna = N - 1;
    int i = vueltaFila;
    int j = vueltaColumna;
    string key = "a";
    while (i < N && j < N)
    {
        key = xmen[i][j];
        while (i < N && j > 0 && key == xmen[i + 1][j - 1])
        {
            contador++;
            i++;
            j--;
        }
        if (contador == 3)
        {
            return true;
        }
        else
        {
            contador = 0;
            i++;
            j--;
        }
        if (j == 0)
        {
            i = vueltaFila;
            j = --vueltaColumna;
        }
        if (vueltaColumna == 0)
        {
            i = vueltaFila++;
            vueltaColumna = N - 1;
            j = vueltaColumna;
        }
    }
    return false;
}

int main()
{
    int N = 6;
    string xmen[MAX][MAX] = {
        {"A", "A", "E", "G", "D", "A"},
        {"C", "Y", "G", "F", "T", "S"},
        {"T", "H", "F", "A", "T", "C"},
        {"G", "I", "P", "J", "P", "E"},
        {"F", "C", "T", "P", "L", "R"},
        {"F", "T", "P", "T", "L", "R"}};

    if (comprobarFila(xmen, N))
    {
        cout << "Bienvenido a X-Men" << endl;
    }
    if (comprobarColumnas(xmen, N))
    {
        cout << "Bienvenido a X-Men" << endl;
    }
    if (comprobarDiagonalesParalelasPrincipal(xmen, N))
    {
        cout << "Bienvenido a X-Men" << endl;
    }
    if (comprobarDiagonalesParalelasSecundaria(xmen, N))
    {
        cout << "Bienvenido a X-Men" << endl;
    }

    system("pause");
    return 0;
}