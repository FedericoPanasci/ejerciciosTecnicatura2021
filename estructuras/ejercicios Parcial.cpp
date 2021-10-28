#include <iostream>

using namespace std;
/*

Completar las funciones faltantes para que el siguiente programa realice lo siguiente:

Dados dos vectores de numeros enteros, sin repetidos y ordenados en forma ascendente obtener e imprimir por consola los valores de un
tercer vector con los elementos que están en ambos conjuntos en forma ascendente

ej:

A={-12, -8, -2, 0, 1, 5, 8, 10}    y B={-7, -2, 1, 5, 9, 11}   entonces c={-2, 1, 5}


*/

// Esta funcion debe recibir dos vectores y completar un tercero con los elementos comunes a ambos sin repetidos y en forma ascendente.

void imprimirVec(int vec[], int cant){
    for (int i = 0; i < cant; i++)
    {
        cout << vec[i] << "  ";
    }
}

void ordenarMayor(int vec[], int cant){
    int aux;
    int i = 0;
    bool ordenado = false;
    while(i < cant - 1 && !ordenado){
        ordenado = true;
        // Los ultimos i elementos ya estan ordenados
        for (int j = 0; j < cant - i - 1; j++) {
            if (vec[j] < vec[j + 1]) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
    imprimirVec(vec, cant);
}

void apareo(int vecA[], int cantA, int vecB[], int cantB, int vecC[], int &k)
{

    int i = 0, j = 0;

    k = 0;

    while (i < cantA && j < cantB)
    {
        for (i = 0; i < cantA; i++)
        {
            for (j = 0; j < cantB; j++)
            {
                if (vecA[i] == vecB[j])
                {
                    vecC[k] = vecA[i];
                    k++;
                }
            }
        }
    }
    return;
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
    cout << "#"
         << endl
         << "==========================================" << endl;
}

int main()
{
    int vecA[] = {-48,
                  -47,
                  -46,
                  -43,
                  -37,
                  -36,
                  -34,
                  -32,
                  -31,
                  -30,
                  -29,
                  -27,
                  -26,
                  -25,
                  -24,
                  -23,
                  -22,
                  -21,
                  -20,
                  -19,
                  -18,
                  -17,
                  -16,
                  -13,
                  -12,
                  -11,
                  -10,
                  -9,
                  -8,
                  -7,
                  -5,
                  -4,
                  -3,
                  -2,
                  1,
                  3,
                  4,
                  5,
                  7,
                  10,
                  11,
                  15,
                  22,
                  23,
                  25,
                  26,
                  26,
                  27,
                  28,
                  30,
                  33,
                  34,
                  35,
                  37,
                  38,
                  39,
                  40,
                  41,
                  42,
                  43,
                  44,
                  45,
                  46};
    int vecB[] = {
        -50,
        -49,
        -45,
        -44,
        -43,
        -42,
        -41,
        -40,
        -39,
        -38,
        -36,
        -35,
        -34,
        -33,
        -31,
        -30,
        -29,
        -26,
        -25,
        -24,
        -23,
        -22,
        -20,
        -18,
        -17,
        -16,
        -14,
        -13,
        -12,
        -11,
        -9,
        -8,
        -6,
        -5,
        -3,
        0,
        3,
        4,
        6,
        7,
        8,
        10,
        11,
        12,
        14,
        15,
        21,
        22,
        23,
        24,
        25,
        26,
        27,
        29,
        30,
        32,
        35,
        36,
        37,
        38,
        41,
        42,
        46,
        47,
        49,
    };
    int vecC[128] = {0};

    int cant = 0;
    ordenarMayor(vecA, 63);
    ordenarMayor(vecB, 65);
    apareo(vecA, 63, vecB, 65, vecC, cant);

    imprimir(vecC, cant);
    system("pause");
    return 0;
}