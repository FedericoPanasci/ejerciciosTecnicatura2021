#include <iostream>


using namespace std;

typedef struct nodo
{
    int dato;
    struct nodo *ste;
} STR_NODO;

void create(STR_NODO **pila)
{
    *pila = NULL;
}

void push(STR_NODO **head, int dato)
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

int pop(STR_NODO **head){
    int valor = (*head)->dato;
    STR_NODO *aux = *head;
    *head = (*head)->ste;
    free(aux);
    printf("%d", valor);
    return valor;
}

bool isEmpty(STR_NODO *head)
{
    return head == NULL;
}

void volverHead(STR_NODO **head, STR_NODO **aux){
    while (!isEmpty(*aux))
    {
        push(head, pop(aux));
    }
}

int buscoValor(STR_NODO **head, STR_NODO **aux){
    int alto = 0;
    int valor = 0;
    
    while (!isEmpty(*head))
    {
        valor = pop(head);
        if (valor > alto)
        {
            alto = valor;
        }
        push(aux, valor);
    }
    return alto;
}

int buscoValorEnHead(STR_NODO **head, STR_NODO **aux, int alto){
    int valor = pop(head);
    while (valor < alto)
    {
        push(aux, valor);
        valor = pop(head);
    }
    return valor;
}

int main () {
    STR_NODO * head;
    create(&head);
    STR_NODO * aux;
    create(&aux);
    STR_NODO * aux2;
    create(&aux2);

    push(&head, 2);
    push(&head, 5);
    push(&head, 3);
    push(&head, 4);
    push(&head, 1);
    

    int alto = 0;
    int valor;
    //mientras head no sea null saco datos
    while (!isEmpty(head))
    {
    //guardo el valor mas alto en head
    alto = buscoValor(&head, &aux);
    //vuelvo a poner en head toda la pila
    volverHead(&head, &aux);
    //saco los valor de head mientras no sean el alto
    valor = buscoValorEnHead(&head, &aux, alto);
    //el valor alto que busco es el nodo que queda guardado en valor, lo guardo en aux2
    push(&aux2, valor);
    //vuelvo a poner toda la aux en head
    volverHead(&head, &aux);
    }
    
    //head ya es null asi que vuelvo los datos a head
    head = aux2;
    
    system("pause");
    return 0;
}