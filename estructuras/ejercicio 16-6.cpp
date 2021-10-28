#include <iostream>
using namespace std;

void cargar(int vec[], int cant);

void imprimir(int vec[], int cant);

void anexar(int vecA[], int cantA, int vecB[],int cantB, int vecC[], int &j);

void apareo(int vecA[], int cantA, int vecB[], int cantB, int vecC[], int &k);

int main()
{
    int cantA = 100;
    int vecA[cantA] = {227, -989, -2683, 2811, 131, -827, -476, 2700, -1830, -1214, 1947, 1601, -2098, 358, -2278, -881, 1275, -2994, -2860, 1091, -2294, -2081, -2671, 1958, -1904, -1768, 520, 2768, -2062, 586, 72, -936, -464, -1452, 2242, -1827, -2007, 367, 211, 48, -2352, 1026, -1906, 1752, 2919, -1299, 583, -713, 337, -2535, 1126, 1415, 495, -2659, -2972, -932, 12, 2285, -1054, 38, 2426, -207, 2574, 2404, 1212, -2268, -744, -146, 1557, 2454, -1169, -2193, 77, -2265, -1586, -2461, -1150, 1401, 2803, 2104, 1216, -2469, -1470, -579, 178, 1997, 1529, 2271, 2886, -1362, 1651, -1380, -1348, -2908, 1039, -99, 2771, 484, 2060, -1320};

    int cantB = 143;
    int vecB[cantB] = {6070, 10570, 7063, 14557, 6036, 1512, 5031, 14451, 7994, -1078, 12350, -2083, 672, -1111, 6361, 14086, 10176, 12946, 14662, -1180, 13254, 13279, -3772, -3156, 12673, -1560, 7155, 8822, 12469, 8092, 13426, 5410, -3399, 2233, 2708, 10278, 3624, 12158, 11452, -728, 565, 13160, -948, -3701, 13002, -1134, -1055, 3095, 6298, 12830, 2247, 1141, 2555, 14987, 14968, 9222, 10531, 6001, 791, 2328, 6059, 4114, 1011, 7245, 12550, 8808, 10355, -3692, -4990, -2372, 5679, 14439, 9473, 1483, 597, -474, 1475, 2679, 757, 4028, 6837, 10083, 8670, 2655, 13185, -806, 4077, 7817, 14025, 14086, 4350, -206, 3304, -1336, 2459, -1725, 11755, -2859, 487, -1665, 4115, 626, 8150, -339, -1581, -2959, 14141, -3916, 43, -2205, 8279, 14040, -401, -3607, 7898, 7357, 13417, 9997, 14414, 7536, 6325, 7056, -3742, -3289, 1312, 2493, 323, 113, -1181, 8897, 12555, 9135, 8458, -1916, 12301, 13589, 8093, -4810, -4364, 13797, 2980, 6068, 8006};

    int vecC[cantA + cantB];

    int j = 0;
    anexar(vecA, cantA, vecB, cantB, vecC, j);
    imprimir(vecC, j);

    int k = j;
    apareo(vecA, cantA, vecB, cantB, vecC, k);
    imprimir(vecC, k);

    system("pause");
    return 0;
}

void imprimir(int vec[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        cout << vec[i];
    }
    return;
}

void anexar(int vecA[], int cantA, int vecB[],int cantB, int vecC[], int &j)
{
    for (int i = 0; i < cantA; i++)
    {
        vecC[i] = vecA[i];
    }
    for (int i = 0; i < j; i++)
    {
        vecC[i + cantA] = vecB[i];
    }
    j = cantA+cantB;
}

void apareo(int vecA[], int cantA, int vecB[], int cantB, int vecC[], int &k)
{
    int i = 0, j = 0;
    k = 0;
    while (i < cantA && j < cantB)
    {
        if (vecA[i] < vecB[j])
        {
            vecC[k] = vecA[i];
            i++;
        }
        else
        {
            vecC[k] = vecB[j];
            j++;
        }
        k++;
    }
    while (i < cantA)
    {
        vecC[k] = vecA[i];
        i++;
        k++;
    }
    while (j < cantB)
    {
        vecC[k] = vecB[j];
        j++;
        k++;
    }
}