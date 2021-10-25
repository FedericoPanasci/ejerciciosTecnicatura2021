#include <iostream>

using namespace std;

typedef struct nodo{
    int dato;
    struct nodo *ste;
} STR_NODO;

void create(STR_NODO **pila){
    *pila = NULL;
}


void push(STR_NODO **head, int dato){   
    //1ero creo el nodo
    STR_NODO *nodo = (STR_NODO*)malloc(sizeof(STR_NODO));
    //2do le guardo el dato
    nodo->dato = dato;
    //3ero apunta a null
    nodo->ste = NULL;

    //se enlazan
    nodo->ste = *head;
    *head = nodo;
    return;
}

int pop(STR_NODO **head){
    int valor = (*head)->dato;
    STR_NODO *aux = *head;
    *head = (*head)->ste;
    free(aux);
    return valor;
}

bool isEmpty(STR_NODO *head){
    return head == NULL;
}

int main () {
    STR_NODO *head;
    create(&head);

    for (int i = 0; i < 5; i++)
    {
        push(&head, i);
    }
    
    STR_NODO *aux;
    create(&aux);
    int valor;

    //saco 2 valores de head y los meto en aux
    valor = pop(&head);
    push(&aux, valor);
    valor = pop(&head);
    push(&aux, valor);
    
    //meto el valor en el 3er lugar que deseaba
    push(&head, 100);
    
    //saco 2 valores de aux y los meto en head
    valor = pop(&aux);
    push(&head, valor);
    valor = pop(&aux);
    push(&head, valor);
    


    system("pause");
    return 0;
}