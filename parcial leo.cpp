#include <iostream>
#include <math.h> 

#define MAX_ROW 300
#define MAX_COL 300

using namespace std;
/*

Completar la función faltante para que el programa realice lo siguiente:

Dada una matriz BINARIOS de N x M, completa con 1 y 0, donde cada fila representa un numero binario, se desea obtener un vector PRIMOS con los numeros de la matriz, pero en base decimal, que sean números primos.

ej: 

Si tenemos un N de 5 y M de 4 y la siguiente matriz de numeros binarios



            1 0 1 0
            0 0 1 1
BINARIOS =  1 0 0 0   Entonces PRIMOS = { 3, 13, 0} 
            1 1 0 1
            0 0 0 0
         
Ejemplo de pasar un numero de binario a decimal:

1 0 1 0 = 10  Ya que (1 * 2^3) + (0 * 2^2) + (1 * 2^1) + (0 * 2^0)

Nota: puede usar la funcion pow(base, exponte) ya esta math incluido.

Recuerde que un numero es primo si solamente tiene dos divisores: 1 y el mismo numero. Ejemplo:
15 no es primo, 13 sí lo es.

*/


void primosDecimales(int mat[MAX_COL][MAX_ROW], int cant, int numeros, int vecC[MAX_ROW], int &cantC) {
    int potencia = numeros - 1;
    int contador = 0;
    for (int i = 0; i < MAX_COL; i++)
    {
        for (int j = 0; j < numeros; j++)
        {
            contador = contador + (mat[i][j] * pow(2, potencia));
            potencia--;
        }
        if (contador % contador == 0 && contador % 2 != 0 && contador % 3 != 0 && contador % 5 != 0 && contador % 7 != 0)
        {
            vecC[cantC] = contador;
            cantC++;
            contador = 0;
        }

        contador = 0;
        potencia = numeros-1;
    }
    
}

void imprimir(int vec[], int cant)
{
    cout << "Copiar los valores entre numerales #99999999#" << endl
         << "=========================================="
         << endl
         << "#";
    for (int i = 0; i < cant; i++)
    {
        cout << vec[i] << "";
    }
    cout <<"#"
         << endl
         << "==========================================" << endl;
}

int main() {
    int mat[MAX_ROW][MAX_COL] = {{1,1,0,0,0,1,1,1,1,0},{1,1,1,1,0,1,1,0,0,0},{0,1,0,0,1,1,1,1,1,0},{0,0,1,0,0,1,1,0,1,0},{1,0,1,0,0,1,1,1,0,1},{0,1,1,1,1,0,0,0,0,1},{0,1,0,0,0,0,0,1,1,1},{0,1,1,1,1,0,0,1,1,1},{1,0,0,0,0,1,0,0,0,0},{0,0,1,0,1,0,0,0,0,0},{1,0,1,0,1,1,0,1,1,0},{0,0,1,1,1,0,0,1,0,0},{1,1,0,1,0,0,0,0,0,1},{0,1,1,0,0,0,0,0,1,0},{0,0,1,0,0,1,1,0,0,0},{1,1,0,0,0,0,1,1,0,1},{1,1,0,0,1,0,0,1,0,0},{0,1,0,0,1,0,1,0,0,0},{0,1,1,1,1,1,0,0,0,0},{1,0,0,1,1,1,1,0,0,1},{0,0,0,1,0,0,0,0,1,0},{0,1,0,1,1,1,0,1,0,1},{0,0,1,0,1,1,1,0,0,0},{0,0,0,1,0,1,1,1,1,0},{1,0,0,1,1,1,0,0,0,1},{1,1,1,0,1,0,1,0,1,1},{0,1,1,0,1,0,1,0,0,1},{1,1,0,0,1,1,0,0,1,0},{0,0,0,1,1,1,0,1,1,1},{1,1,0,1,1,0,1,1,0,0},{0,1,1,1,0,0,0,1,0,1},{1,1,1,0,1,1,0,0,1,1},{1,0,0,1,1,1,1,1,1,1},{0,0,1,0,1,1,1,1,1,0},{0,0,1,0,0,1,0,1,0,1},{0,1,0,0,1,1,1,1,0,0},{1,0,0,1,1,0,1,0,0,0},{1,0,0,1,0,0,0,1,1,0},{0,1,1,0,0,0,0,1,1,1},{1,1,0,1,0,1,1,0,0,1},{0,1,0,1,0,1,0,0,1,1},{0,0,0,1,1,1,1,1,0,0},{1,1,1,1,1,1,0,1,0,1},{0,0,0,1,0,0,1,1,1,1},{1,0,1,1,0,1,0,0,0,0},{1,1,1,1,0,0,1,1,1,1},{1,0,1,0,0,0,1,0,1,0},{1,0,1,0,1,0,1,0,1,0},{0,0,1,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,0,1,0},{1,1,1,0,0,0,0,1,0,0},{0,1,0,0,1,0,1,1,0,0},{1,1,1,1,0,1,0,1,0,1},{1,0,1,0,1,1,0,1,1,1},{1,0,1,0,1,1,1,0,1,1},{1,1,1,1,1,1,0,1,1,1},{0,1,1,0,0,0,0,1,1,0},{1,1,1,1,0,1,1,1,1,0},{0,0,1,1,1,0,0,0,1,0},{1,0,1,0,0,1,1,0,0,0},{0,0,0,0,1,0,1,1,1,0},{0,0,1,1,0,1,1,1,0,1},{0,0,0,1,1,1,0,0,1,0},{0,0,1,1,1,0,0,1,1,0},{0,0,0,1,0,0,1,0,1,0},{0,1,1,0,1,1,0,0,1,1},{0,1,1,1,1,1,1,0,1,1},{0,0,0,1,0,0,0,0,1,0},{0,0,1,0,0,1,1,0,0,0},{0,0,0,0,1,1,1,1,0,0},{0,0,0,1,0,0,1,1,1,1},{1,1,0,0,1,0,0,0,1,1},{1,1,0,0,1,1,0,0,0,1},{0,1,0,1,0,0,0,1,0,0},{1,1,0,0,0,0,1,1,0,0},{1,0,1,1,1,1,1,0,1,0},{1,0,1,0,0,1,1,0,1,0},{1,1,0,1,0,1,1,1,0,1},{0,0,0,1,0,1,0,0,0,1},{1,0,0,1,0,0,0,1,0,0},{0,1,0,0,1,1,0,0,1,0},{1,0,1,1,1,0,1,0,1,1},{1,0,0,0,0,0,1,1,0,0},{0,0,0,1,1,0,1,1,1,0},{1,1,0,0,1,0,1,1,0,1},{0,0,0,1,1,1,1,0,1,1},{0,1,0,0,1,1,1,1,0,0},{0,0,0,0,0,1,1,0,0,1},{1,0,0,0,0,1,0,1,0,0},{1,0,1,0,0,1,0,1,0,0},{1,1,0,0,0,1,1,0,1,0},{1,0,1,0,1,0,1,0,1,1},{0,0,0,1,1,0,1,0,1,0},{1,0,0,1,0,1,0,0,0,0},{1,0,1,1,0,0,0,1,1,1},{1,0,1,0,1,1,0,1,0,0},{0,1,1,1,1,0,1,1,0,1},{0,0,0,1,0,1,0,1,1,1},{1,1,0,0,1,0,1,0,1,0},{1,1,1,0,1,0,1,1,0,0},{1,1,0,1,1,1,0,1,1,1},{0,0,0,0,0,1,1,0,1,1},{0,0,0,0,0,0,1,1,0,0},{1,1,0,1,0,1,1,0,1,0},{0,0,1,0,0,1,1,1,0,1},{1,0,1,1,1,0,0,0,1,0},{0,0,0,0,1,0,0,0,0,0},{1,1,1,0,0,0,0,1,1,0},{0,1,0,1,1,1,0,1,0,0},{0,0,0,1,0,1,0,0,1,0},{1,0,1,0,1,1,1,1,0,1},{1,1,1,0,1,1,0,0,0,1},{0,1,1,1,0,0,0,0,1,0},{1,0,0,0,0,1,0,0,0,0},{0,0,0,0,1,0,0,0,1,1},{1,0,0,1,1,1,0,0,0,0},{0,1,0,1,1,0,0,0,0,1},{0,0,1,0,0,1,1,1,1,0},{0,0,1,0,1,1,1,0,1,1},{0,0,1,0,1,0,0,0,1,1},{0,1,1,0,1,0,1,0,1,0},{0,1,0,0,0,0,0,0,1,1},{1,0,1,0,1,0,0,1,1,1},{1,0,0,0,1,1,0,0,0,1},{0,0,1,1,1,0,0,1,0,0},{0,0,1,1,0,1,1,1,1,1},{1,1,0,1,1,1,0,1,1,1},{1,1,0,0,0,0,1,1,0,0},{0,0,1,0,1,0,0,0,1,1},{0,0,1,0,1,1,0,1,1,1},{0,0,0,0,1,1,1,1,1,0},{1,0,1,1,0,1,1,1,0,0},{1,0,1,1,1,1,0,1,0,1},{1,1,1,1,1,0,1,0,1,1},{0,0,1,1,1,0,0,1,0,0},{0,1,0,0,0,0,0,0,0,0},{1,0,1,1,1,0,0,0,1,1},{0,0,0,1,0,1,1,0,0,1},{1,1,1,1,1,0,1,1,1,1},{0,1,0,1,1,1,1,1,0,0},{0,1,0,1,1,0,0,1,0,1},{0,0,0,1,0,0,1,1,0,1},{0,1,1,1,0,1,1,0,1,1},{0,1,0,0,1,1,1,1,1,0},{1,1,0,0,1,1,1,0,0,1},{0,1,1,0,1,1,0,0,0,0},{1,1,0,0,1,0,0,1,1,1},{1,0,1,1,1,0,1,1,0,1},{1,0,0,1,0,0,0,0,0,0},{1,1,0,0,0,1,0,1,1,1},{0,0,1,0,1,1,1,0,0,0},{0,1,0,1,1,1,1,1,0,0},{0,1,0,1,0,0,0,1,0,0},{0,1,1,1,1,0,0,0,1,0},{0,1,0,0,0,1,0,0,0,1},{1,0,0,0,1,0,0,0,1,1},{0,0,0,1,1,0,1,0,1,0},{0,1,0,1,1,0,1,0,0,0},{0,1,0,1,1,1,0,1,0,1},{1,1,1,0,0,1,1,0,0,1},{0,1,1,0,1,0,0,1,0,0},{0,1,1,0,0,1,0,0,1,1},{1,0,1,0,1,0,0,1,1,1},{0,1,0,1,0,1,0,1,0,1},{1,0,0,0,0,1,1,1,0,1},{0,0,0,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,1,0},{1,1,0,0,1,0,0,1,0,1},{0,0,1,1,0,1,1,1,0,1},{0,1,0,0,0,1,0,1,1,0},{0,0,1,1,0,0,0,1,1,0},{0,0,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,1,1},{0,1,0,0,0,0,1,0,1,0},{1,0,0,0,0,0,1,0,0,0},{0,1,1,0,0,0,1,0,0,0},{1,0,1,0,0,1,1,1,0,0},{1,1,1,0,0,0,0,1,0,1},{1,0,1,1,0,1,0,1,1,0},{1,0,1,1,0,1,1,1,0,1},{1,0,0,1,0,1,1,0,1,0},{1,0,0,1,0,1,1,0,1,1},{1,1,0,1,0,1,1,0,0,0},{1,0,1,1,0,0,0,0,0,0},{0,1,0,0,0,1,0,1,0,0},{0,0,1,0,0,0,1,1,1,1},{1,0,0,0,0,0,0,0,0,0},{1,0,1,1,1,1,0,1,1,1},{0,1,0,1,0,1,0,1,0,1},{0,1,0,1,1,1,1,0,0,0},{0,1,0,0,0,1,0,1,1,0},{0,1,1,0,0,0,1,1,0,0},{1,1,1,1,0,0,0,1,1,0},{1,1,0,1,1,0,0,0,0,0},{0,0,0,1,0,0,1,1,0,0},{0,0,0,1,1,1,1,0,1,0},{1,0,0,1,1,1,1,0,0,0},{1,0,1,0,0,1,1,0,1,0},{0,0,0,0,1,0,1,0,0,0},{0,1,0,0,1,1,1,0,0,0},{0,0,1,0,0,1,1,0,0,0},{0,1,0,1,0,0,0,1,0,0},{0,1,0,1,1,0,0,0,1,0},{0,1,0,1,1,0,0,1,1,0},{1,0,1,0,0,0,1,1,0,0},{1,0,1,0,1,0,1,1,1,1},{1,1,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,1,1,1,1},{1,1,0,0,0,1,0,1,0,1},{0,1,0,0,1,1,1,0,0,0},{1,0,1,0,1,0,1,1,0,1},{0,0,0,0,1,1,1,1,1,0},{1,0,1,0,1,1,0,0,1,0},{1,1,0,1,0,0,0,1,1,0},{1,1,0,0,1,1,0,1,0,0},{1,1,0,1,0,0,1,0,1,1},{1,1,0,1,1,1,1,0,1,0},{1,1,0,0,0,0,1,0,0,0},{1,1,1,0,1,0,1,1,0,1},{0,1,1,1,0,1,1,0,0,1},{1,1,0,1,0,0,0,0,0,0},{1,0,1,1,0,0,1,1,0,1},{0,1,1,0,0,1,1,0,1,0},{1,1,0,0,0,1,0,0,1,0},{0,1,1,0,0,0,0,1,1,0},{0,1,1,1,0,0,1,0,1,0},{1,0,1,0,0,0,1,0,1,0},{1,1,0,0,0,1,0,0,1,0},{1,0,0,1,1,0,0,1,1,1},{1,1,1,1,1,0,1,1,0,1},{0,0,1,0,0,0,1,1,0,1},{0,1,0,0,1,0,0,0,0,0},{1,0,0,1,1,0,1,1,1,1},{1,1,0,0,0,0,1,1,0,0},{0,1,0,0,1,0,0,0,0,0},{0,1,0,1,1,0,0,0,1,0},{0,0,1,1,0,0,0,0,1,1},{1,0,1,0,0,0,0,0,0,1},{1,0,0,0,0,1,0,0,0,1},{1,0,0,0,0,0,1,1,1,1},{1,1,0,1,1,1,1,0,0,0},{0,0,1,1,0,0,0,1,0,1},{1,1,1,1,0,1,1,0,1,0},{0,0,0,0,1,0,0,0,0,1},{0,0,0,1,0,1,0,0,0,0},{0,1,1,0,1,1,1,0,1,0},{1,1,0,0,0,0,1,0,1,1},{0,0,1,1,0,0,0,1,1,0},{1,1,0,1,0,1,1,1,0,1},{0,1,0,1,1,0,0,1,1,1},{1,1,1,0,1,0,1,1,1,0},{1,1,1,1,1,0,1,1,0,0},{0,1,0,0,0,1,0,0,0,0},{1,1,0,0,1,0,1,0,0,0},{1,0,0,1,0,0,1,1,1,0},{1,1,0,0,1,0,0,0,1,0},{0,0,1,0,1,0,1,0,1,1},{0,1,1,0,1,0,1,1,1,1},{1,0,1,1,1,0,0,0,1,1},{0,0,1,0,1,1,1,1,1,0},{1,0,1,0,0,1,1,0,0,0},{0,0,1,1,0,0,0,1,1,0},{1,1,0,1,1,1,0,0,1,0},{1,1,1,0,1,1,1,1,1,0},{1,0,0,0,0,1,1,0,0,0},{1,1,0,0,0,1,1,1,1,0},{0,1,1,1,1,1,1,1,0,0},{0,1,1,0,0,1,1,0,0,0},{0,0,1,0,1,0,0,0,1,1},{0,0,1,0,1,1,0,1,0,1},{0,1,1,0,1,0,0,1,0,0},{1,1,1,0,0,1,0,1,1,0},{0,1,0,0,1,0,1,1,0,1},{0,1,0,0,1,0,0,0,0,0},{1,1,1,1,0,1,1,1,1,0},{1,0,1,1,0,1,0,1,1,1},{0,0,1,1,0,0,0,1,1,1},{0,0,1,1,0,0,1,1,0,0},{0,1,1,0,0,1,0,1,1,1},{1,1,0,1,0,1,1,0,0,1},{0,0,0,0,0,0,1,1,0,1},{0,0,0,0,1,1,1,0,0,0},{0,1,1,1,1,1,1,0,1,0},{0,0,1,0,1,0,1,0,1,0},{0,0,0,0,0,1,1,1,0,0},{0,1,0,0,0,0,0,1,1,0},{0,0,1,1,1,1,1,1,1,0},{0,0,0,0,1,0,1,0,1,1},{0,0,0,0,1,0,0,0,0,0},{0,0,1,1,1,0,1,0,0,0},{1,1,1,0,1,0,1,0,0,1},{0,0,1,0,1,0,1,1,0,0},{1,0,1,1,1,0,1,0,1,0},{1,1,1,1,0,1,1,0,1,1},{0,1,0,1,1,1,0,1,1,0},{1,1,1,1,0,0,1,1,1,1},{0,0,0,0,1,1,0,1,1,1},{0,0,1,0,0,1,0,0,1,0},{0,1,1,0,1,1,1,0,1,0},{1,0,1,0,0,0,0,0,0,0}};
    
    int vecC[MAX_ROW] = {0};

    int cant = 0;
    primosDecimales(mat, 200, 10, vecC, cant);

    imprimir(vecC, cant);
    system("pause");
    return 0;
}