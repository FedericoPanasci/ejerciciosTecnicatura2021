#include <iostream>
#include "consola.h"
#include "burbujeo.h"
using namespace std;


int main () {
    int vec [10] = {0};
    for (int i = 0; i < 10; i++)
    {
        datos(vec, i);
    }
    ordenar(vec, 10);
    mostrar(vec);
    
    system("pause");
    return 0;
}