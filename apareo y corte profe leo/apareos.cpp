#include <iostream>

using namespace std;

//apareo solo con iguales
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
/*ejercicio de leo
while (i < cantA && j < cantB){
    if (vecA[i] == vecB[j])
    {
        vecC[k] = vecA[i];
        i++;
        j++;
        k++;
    }
    else if (vecA[i] < vecB[j]){
        i++;
    }
    else {
        j++;
    }
}
*/


//apareo solo diferentes
void apareo(int vecA[], int cantA, int vecB[], int cantB, int vecC[], int &k)
{

    int i = 0, j = 0;
    k = 0;

    while (i < cantA && j < cantB)
    {
        if (vecA[i] < vecB[j])
        {
            vecC[k] = vecA[i];
            k++;
            i++;
        }
        if (vecA[i] == vecB[j])
        {
            i++;
            j++;
        }
        if (vecB[j] < vecA[i])
        {
            vecC[k] = vecB[j];
            j++;
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
    return;
}

//ordenar de mayor a menor
void ordenarVector(int vec[], int cant)
{
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
}

//apareo mayor a menor
void apareoMayorAMenor(int vecA[], int cantA, int vecB[], int cantB, int vecC[], int &k){
    int i = cantA - 1, j = cantB - 1;
    k = 0;
    while(i >= 0 && j >= 0){
        if (vecA[i] > vecB[j]) {
            vecC[k] = vecA[i];
            i++;
        } else {
            vecC[k] = vecB[j];
            j++;
        }
            k++;
    }

    while(i >= 0) {
        vecC[k] = vecA[i];
        i++;
        k++;
    }

    while(j >= 0) {
        vecC[k] = vecB[j];
        j++;
        k++;
    }
    return;
}

int main () {

    return 0;
}