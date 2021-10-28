#include <iostream>

using namespace std;

/*18. Ingresar un valor N (< 25) y luego por filas una matriz cuadrada CUADRA de N filas y columnas.
Desarrollar un programa que determine e imprima:
a) Todos los elementos de la diagonal principal o secundaria según de cual resulte mayor la sumatoria de
elementos.
b) Los elementos del cuarto (N/2 filas y N/2 columnas) cuya sumatoria resulte mayor (considerando
que N fuera par).
c) Los elementos de la triangular superior o inferior dependiendo de cual tenga mayor sumatoria de
elementos.*/
#define CANT_MATRIZ 25

void ingreso(int &filas, int &columnas, string mensaje)
{
    cout << mensaje;
    cin >> filas;
    columnas = filas;
    return;
}
void cargarMatriz(int matriz[][CANT_MATRIZ], int filas, int columnas)
{
    matriz[filas][columnas];
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "asigne valor a su matriz: ";
            cin >> matriz[i][j];
        }
    }
    return;
}
int sumatoriaDiagonalPrin(int matriz[][CANT_MATRIZ], int filas, int columnas)
{
    matriz[filas][columnas];
    int suma = 0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            suma = suma + matriz[i][j];
            i++;
        }
    }
    return suma;
}
int sumatoriaDiagonalSec(int matriz[CANT_MATRIZ][CANT_MATRIZ], int filas, int columnas)
{
    matriz[filas][columnas];
    int suma = 0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = columnas - 1; j >= 0; j--)
        {
            suma = suma + matriz[i][j];
            i++;
        }
    }
    return suma;
}
void imprimirDiagonalPrincipal(int matriz[CANT_MATRIZ][CANT_MATRIZ], int filas, int columnas){
    matriz[filas][columnas];
    cout << "los elementos de la diagonal principal son: " << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << matriz [i][j] << "  ";
            i++;
        }
    }
    cout << endl;
    return;
}
void imprimirDiagonalSecundaria(int matriz[CANT_MATRIZ][CANT_MATRIZ], int filas, int columnas){
    matriz [filas][columnas];
    cout << "los elementods de la diagonal secundaria son: " << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = columnas - 1; j >= 0; j--)
        {
            cout << matriz[i][j] << "  ";
            i++;
        }
    }
    cout << endl;
    return;
}
void calcular1Cuartos(int matriz[CANT_MATRIZ][CANT_MATRIZ], int filas, int columnas, int sumacuartos[0]){
    matriz[filas][columnas];
    for (int i = 0; i < filas/2; i++)
    {
        for (int j = 0; j < columnas/2; j++)
        {
            sumacuartos[0] += matriz[i][j];
        }
    }
    return;    
}
void calcular2Cuartos(int matriz[CANT_MATRIZ][CANT_MATRIZ], int filas, int columnas, int sumacuartos[1]){
    matriz[filas][columnas];
    for (int i = filas/2; i < filas; i++)
    {
        for (int j = 0; j < columnas/2; j++)
        {
            sumacuartos[1] += matriz [j][i];
        }
    }
    return;
}
void calcular3Cuartos(int matriz[CANT_MATRIZ][CANT_MATRIZ], int filas, int columnas, int sumacuartos[2]) {
    matriz [filas][columnas];
    for (int i = filas/2; i < filas; i++)
    {
        for (int j = 0; j < columnas/2; j++)
        {
            sumacuartos[2] += matriz[i][j];
        }
    }
    return;
}
void calcular4Cuartos(int matriz[CANT_MATRIZ][CANT_MATRIZ], int filas, int columnas, int sumacuartos[3]){
    matriz [filas][columnas];
    for (int i = filas/2; i < filas; i++)
    {
        for (int j = columnas/2; j < columnas; j++)
        {
            sumacuartos[3] += matriz[i][j];
        }
    }
    return;
}
void imprimirCuartos(int matriz[CANT_MATRIZ][CANT_MATRIZ], int filas, int columnas, int imprimir){
    matriz[filas][columnas];
    cout << "los elementos que utilizan este cuarto son: " << endl;
    switch (imprimir)
    {
    case 1:
    for (int i = 0; i < filas/2; i++)
    {
        for (int j = 0; j < columnas/2; j++)
        {
            cout << matriz[i][j] << "  ";
        }
    }
    cout << endl;
        break;
    case 2:
    for (int j = 0; j < columnas/2; j++)
    {
        for (int i = filas/2; i < filas; i++)
        {
            cout << matriz [j][i] << "  ";
        }
    }
    cout << endl;
        break;
    case 3:
    for (int i = filas/2; i < filas; i++)
    {
        for (int j = 0; j < columnas/2; j++)
        {
            cout << matriz[i][j] << "  ";
        }
    }
    cout << endl;
        break;
    case 4:
    for (int i = filas/2; i < filas; i++)
    {
        for (int j = columnas/2; j < columnas; j++)
        {
            cout << matriz[i][j] << "  ";
        }
    }
    cout << endl;
        break;
    }
return;
}
int sumaTriangularSuperior(int matriz[CANT_MATRIZ][CANT_MATRIZ], int filas, int columnas){
    matriz[filas][columnas];
    int suma = 0;
    for (int i = 0; i < filas-1; i++)
    {
        for (int j = i+1; j < columnas; j++)
        {
            suma += matriz[i][j];         
        }
    }
    return suma;
}
int sumaTriangularInferior(int matriz[CANT_MATRIZ][CANT_MATRIZ], int filas, int columnas){
    matriz[filas][columnas];
    int suma = 0;
    for (int i = 1; i < filas; i++)
    {
        for (int j = 0; j <= i-1; j++)
        {
            suma += matriz [i][j];
        }
    }
    cout << endl;
    return suma;
}
void imprimirTriangular(int matriz[CANT_MATRIZ][CANT_MATRIZ], int filas, int columnas, int inferior, int superior){
    matriz[filas][columnas];
    if (superior > inferior)
    {
        cout << "La triangular Superior es mayor a la triangular inferior, los elementos de la triangular superior son: " << endl;
        for (int i = 0; i < filas-1; i++)
    {
        for (int j = i+1; j < columnas; j++)
        {
            cout << matriz [i][j] << " ";       
        }
    }
    cout << endl;
    }
    else
    {
        cout << "La triangular Inferior es mayor a la triangular superior, los elementos de la triangular inferior son: " << endl;
        for (int i = 1; i < filas; i++)
        {
            for (int j = 0; j <= i-1; j++)
            {
                cout << matriz [i][j] << "  ";
            }
        }
        cout << endl;
    }
    return;
}

int main()
{

    int filas = 0, columnas = 0;
    int diagonalPrin = 0, diagonalSec = 0, triangularSup = 0, triangularInf = 0;
    ingreso(filas, columnas, "ingrese la cantidad de filas y columnas que tendra su matriz cuadrada: ");

    int matriz[CANT_MATRIZ][CANT_MATRIZ] = {0};

    cargarMatriz(matriz, filas, columnas);
    //punto A
    diagonalPrin = sumatoriaDiagonalPrin(matriz, filas, columnas);
    diagonalSec = sumatoriaDiagonalSec(matriz, filas, columnas);

    if (diagonalPrin > diagonalSec)
    {
        imprimirDiagonalPrincipal(matriz, filas, columnas);
    }
    else
    {
        imprimirDiagonalSecundaria(matriz, filas, columnas);
    }
    //punto B
    int imprimirCuarto = 0;
    if (columnas % 2==0)
    {
        int sumaCuartos [4] = {0};
        calcular1Cuartos(matriz, filas, columnas, sumaCuartos);
        calcular2Cuartos(matriz, filas, columnas, sumaCuartos);
        calcular3Cuartos(matriz, filas, columnas, sumaCuartos);
        calcular4Cuartos(matriz, filas, columnas, sumaCuartos);
        if (sumaCuartos [0] >= sumaCuartos [1] && sumaCuartos [0] >= sumaCuartos [2] && sumaCuartos [0] >= sumaCuartos [3])
        {
            imprimirCuarto = 1;
            imprimirCuartos(matriz, filas, columnas, imprimirCuarto);
        }
            if (sumaCuartos [1] >= sumaCuartos [0] && sumaCuartos [1] >= sumaCuartos [2] && sumaCuartos [1] >= sumaCuartos [3])
            {
                imprimirCuarto = 2;
                imprimirCuartos(matriz, filas, columnas, imprimirCuarto);
            }
                if (sumaCuartos [2] >= sumaCuartos [0] && sumaCuartos [2] >= sumaCuartos [1] && sumaCuartos [2] >= sumaCuartos [3])
                {
                    imprimirCuarto = 3;
                    imprimirCuartos(matriz, filas, columnas, imprimirCuarto);
                }
                if (sumaCuartos [3] >= sumaCuartos [0] && sumaCuartos [3] >= sumaCuartos [1] && sumaCuartos [3] >= sumaCuartos [2])
                {
                    imprimirCuarto = 4;
                    imprimirCuartos(matriz, filas, columnas, imprimirCuarto);
                }
                
    }
    else
    {
        cout << "no se puede dividir por cuartos una matriz impar";
    }
    //punto C
    triangularSup = sumaTriangularSuperior(matriz, filas, columnas);
    triangularInf = sumaTriangularInferior(matriz, filas, columnas);
    imprimirTriangular(matriz, filas, columnas, triangularInf, triangularSup);
    system("pause");
    return 0;
}