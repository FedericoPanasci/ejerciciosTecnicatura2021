#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

using namespace std;

typedef struct nodo
{
    char *dato;
    struct nodo *ste;
} STR_NODO;

void create(STR_NODO **pila)
{
    *pila = NULL;
}

void push(STR_NODO **head, char *dato)
{
    //1ero creo el nodo
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    //2do le guardo el dato
    nodo->dato = dato;
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

int main()
{
    STR_NODO *head;
    create(&head);
    char pal[]= "pala.alap\0";
    int i = 0;
    char aux;
    cout << pal[i] << endl;
    while (pal[i] != '\0' && pal[i] != '.')
    {
        push(&head, *(pal)+i);
        
        i++;
    }
    
    // strcpy(aux, strtok(pal,"."));
    // strcpy(aux, strtok(NULL,"\0"));


    system("pause");
    return 0;
}