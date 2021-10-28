#include <iostream>

using namespace std;

/*void imprimir(int vec[], int cant){
    for (int i = 0; i < cant; i++)
    {
        cout << vec[i] << "  ";
    }
    
}

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
    imprimir(vec, cant);
}*/

int main()
{
int vec[] = {1,2,3,4,5,6};
    for (int i = 0; i < 3; i++)
    {
        if (vec[i] % 2 != 0)
        {
            cout << i;
        }
    }
    system("pause");
    return 0;
}