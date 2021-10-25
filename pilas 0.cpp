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

#include <iostream>

using namespace std;

int main () {
    STR_NODO *head;
    system("pause");
    return 0;
}