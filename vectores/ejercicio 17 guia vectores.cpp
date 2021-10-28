#include <iostream>

using namespace std;

#define CANT_COLUMNAS 30
#define CANT_FILAS 25
/*17. Ingresar dos valores, M (< 30) y N (< 25) y a continuación por filas todos los componentes de una matriz
MATRIZA de M filas y N columnas. Desarrollar un programa que:
a) Imprima la matriz MATRIZA por columnas.
b) Calcule e imprima el valor promedio de los componentes de la matriz.
c) Genere e imprima un vector VECSUMCOL donde cada componente sea la suma de la columna
homóloga.
d) Genere e imprima un vector VECMAXFIL donde cada componente sea el valor máximo de cada fila.*/

int main()
{
    int filas = 0, columnas = 0;
    int cantidadValores = 0;

    cout << "ingrese la cantidad de filas que va a tener su matriz: ";
    cin >> filas;

    cout << "ingrese la cantidad de columnas que va a tener su matriz: ";
    cin >> columnas;

    cantidadValores = filas * columnas;
    int suma = 0;
    int matriz[filas][columnas] = {0};

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "ingrese el valor de su matriz: ";
            cin >> matriz[i][j];
            suma = suma + matriz[i][j];
        }
    }

    cout << "su matriz: " << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << matriz[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "su matriza es: " << endl;
    for (int j = 0; j < columnas; j++)
    {
        for (int i = 0; i < filas; i++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    float promedio = (float)suma / cantidadValores;
    cout << "el promedio de la matriz es: " << promedio << endl;

    int VECSUMCOL[columnas] = {0};

    for (int i = 0; i < columnas; i++)
    {
        for (int j = 0; j < filas; j++)
        {
            VECSUMCOL[i] = VECSUMCOL[i] + matriz[j][i];
        }
        cout << VECSUMCOL[i] << "  ";
    }
    cout << endl;

    int VECMAXFIL[filas] = {0};

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (VECMAXFIL[i] < matriz[i][j])
            {
                VECMAXFIL[i] = matriz[i][j];
            }
        }
        cout << "su maximo de la fila " << i + 1 << " es: " << VECMAXFIL[i] << endl;
    }

    cout << endl;

    system("pause");
    return 0;
}