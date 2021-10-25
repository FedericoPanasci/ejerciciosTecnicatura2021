#include <iostream>
#include "stdio.h"
#include "string.h" //para strlen
using namespace std;

int main()
{
    /*int n = 10;
    int *ptrn = NULL; //declaracion
    ptrn = &n; //asigna memoria
    *ptrn = 20; //modifica el valor de n

    printf("valor %d\n", n);
    printf("dir de mem %p\n", &n); //imprime posicion de memoria
    printf("ptr a n = %p y n vale= %d", ptrn, *ptrn/*desreferencia y obtiene el dato);*/

    /*
    char palabra[] = "hola";
    char *ptrpalabra = palabra;
    printf("la palabra %s arranca en la posicion %p\n", palabra, palabra);
    */

    /*
    int vec[] = {1,2,3,4,5};
    for (int i = 0; i < 5; i++)
    {
        printf("vector [%d] = %d - pos = %p\n", i, *(vec + i), vec + i);
    }
    */
    /*void funcion(char *valor){
       *valor= 20;
    }
    funcion(n);*/
    /*
    int n = 10;
    int *ptrn = NULL;
    ptrn = (int*)malloc(sizeof(int));
    *ptrn = 30;
    printf("en pos %p hay %d", ptrn, *ptrn);
    
    free(ptrn);
    ptrn = NULL;
    if (ptrn != NULL)
    {
        
    }

    char *cadena = (char *) malloc(sizeof(char) * 11);*/

    int contar(char palabra){
        int cant = 0;
        while (palabra[cant] != "\0") //para contar la cantidad de letras que tiene
        {
            cant++;
        }
        
        return cant;
    }
    //sino se puede usar strlen(palabra)

    char palabra[100] = "hola";
    printf("%s tiene %d letras\n", palabra, contar(palabra));
    strcpy(palabra, "mundo");

    system("pause");
    return 0;
}