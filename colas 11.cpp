#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

typedef struct nodo
{
    int dato;
    nodo *ste;
}STR_NODO;

typedef struct queue
{
    STR_NODO *frente;
    STR_NODO *fin;
}STR_QUEUE;

bool isEmpty(STR_QUEUE queue){
    return queue.fin == NULL && queue.frente == NULL;
}

void add(STR_QUEUE *queue, int dato){
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = dato;
    nodo->ste = NULL;

    if (queue->frente == NULL)
    {
        queue->frente = nodo;
    } else
    {
        queue->fin->ste = nodo;
    }
    
    queue->fin = nodo;
}

int remove(STR_QUEUE *queue){   
    STR_NODO *aux = queue->frente;

    int valor = aux->dato;
    queue->frente = queue->frente->ste;

    if (queue->frente == NULL)
    {
        queue->fin = NULL;
    }

    free(aux);
    return valor;
}

STR_QUEUE create(STR_QUEUE queue){
    STR_QUEUE queue;
    queue.fin = NULL;
    queue.frente = NULL;
    return queue;
}

void print(STR_QUEUE *queue){
    while (!isEmpty(*queue))
    {
        printf("%d\n", remove(queue));
    }
    
}

bool remove2(STR_QUEUE *queue, int cant){
    
    for (int i = 0; i < cant; i++)
    {
    if (isEmpty(*queue))
    {
        return false;
    }
    remove(queue); 
    }
    
    return true;
}

int contarNodos(STR_QUEUE *queue){
    STR_QUEUE aux;
    create(aux);

    int i = 0;
    while (!isEmpty(*queue))
    {
        add(&aux, remove(queue));
        i++;
    }
    
    
    *queue = aux;
    return i;
}


int main () {
    STR_QUEUE queue;
    create(queue);

    add(&queue, 1);
    add(&queue, 1);
    add(&queue, 1);

    int cantidad = contarNodos(&queue);

    system("pause");
    return 0;
}