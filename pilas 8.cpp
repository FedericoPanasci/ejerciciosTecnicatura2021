#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

typedef struct dato
{
    char nombre;
    char apellido;
} STR_DATO;


typedef struct nodo
{
    STR_DATO alumno;
    struct nodo *ste;
} STR_NODO;

void create(STR_NODO **pila)
{
    *pila = NULL;
}

void push(STR_NODO **head, STR_DATO dato)
{
    //1ero creo el nodo
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    //2do le guardo el dato
    strcpy(nodo->alumno.apellido, dato.apellido);
    
    //3ero apunta a null
    nodo->ste = NULL;

    //se enlazan
    nodo->ste = *head;
    *head = nodo;
    return;
}

char * pop(STR_NODO **head)
{
    char *valor;
    strcpy((*head)->dato, valor);
    STR_NODO *aux = *head;
    *head = (*head)->ste;
    free(aux);
    return valor;
}

bool isEmpty(STR_NODO *head)
{
    return head == NULL;
}

int main () {

    system("pause");
    return 0;
}