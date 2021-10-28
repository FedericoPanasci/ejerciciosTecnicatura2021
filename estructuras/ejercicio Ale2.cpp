#include <iostream>

using namespace std;
#define CANT_OBRAS 100
#define CANT_CATEGORIAS 10
#define CANT_AUTORES 5

/*Un museo desea desarrollar un sistema que le permita gestionar las obras de arte que posee.
Recientemente el museo recibió un conjunto de piezas que deben ser registradas.
De cada pieza el museo guarda:
Código (int)
Nombre (string)
Categoría (short int)
Autor (string)
El museo posee además el conjunto de las categorías de las obras con la siguiente información:
Código Categoría (shor int)
Nombre (string)
Este conjunto se encuentra ordenado por Código Categoría.
Se pide:
1. Desarrollar una función que permita unificar 2 conjuntos de 100 obras cada uno en un único
conjunto, utilizando para ello el código de la obra como criterio de mezcla.
2. Generar un listado ordenado por categoría con la siguiente información:*/

struct ST_PIEZA
{
    int codigo;
    string nombre;
    short int categoria;
    string autor;
};

struct ST_CATEGORIAS
{
    short int CodCategoria;
    string nombre;
};

struct ST_CONJUNTO
{
    int codigo;
    string autor;
};

void unificarConjunto(ST_PIEZA piezaA[], ST_PIEZA piezaB[])
{
    ST_PIEZA piezaC[CANT_OBRAS * 2];
    int i = 0, j = 0;

    int k = 0;

    while (i < CANT_OBRAS && j < CANT_OBRAS)
    {

        if (piezaA[i].categoria < piezaB[j].categoria)
        {

            piezaC[k] = piezaA[i];

            i++;
        }
        else
        {
            piezaC[k] = piezaB[j];
            j++;
        }
        k++;
    }

    while (i < CANT_OBRAS)
    {
        piezaC[k] = piezaA[i];
        i++;
        k++;
    }
    while (j < CANT_OBRAS)
    {
        piezaC[k] = piezaB[j];
        j++;
        k++;
    }
    return;
}

string obtenerNombreCategoria(int codCategoria, ST_CATEGORIAS categoria[], int cantCategorias){

}

void imprimirCategoria(ST_CATEGORIAS categoria[], ST_PIEZA pieza[])
{
    
    int i = 0;
    string categoria;
    int codCategoria;
    while (i < CANT_PIEZAS)
    {
        codCategoria = pieza[i].categoria;
        categoria = obtenerNombreCategoria(codCategoria, );
        cout << "categoria: " << categoria << endl;
        while (i < cantidadObras && codCategoria == pieza[i].codigo)
        {
            /* code */
        }
        
    for (int i = 0; i < CANT_CATEGORIAS; i++)
    {
        cout << "categoria: " << categoria[i].nombre << endl;
        for (int j = 0; j < CANT_AUTORES; j++)
        {
            cout << "nombre de la pieza: " << pieza[j].nombre << ", autor: " << pieza[j].autor << "." << endl;
        }
    }
}

void ordenarCategoria(ST_CATEGORIAS categoria[], ST_PIEZA pieza[])
{
    ST_CATEGORIAS aux[CANT_CATEGORIAS];
    int i, j, aux;
    for (i = 0; i < CANT_CATEGORIAS - 1; i++)
    {
        for (j = 0; j < CANT_CATEGORIAS - j - 1; j++)
        {
            if (categoria[j].nombre > categoria[j + 1].nombre)
            {
                aux[0] = categoria[j];
                categoria[j] = categoria[j + 1];
                categoria[j + 1] = aux[0];
            }
        }
    }
    imprimirCategoria(categoria, pieza);
}

void imprimirPieza(ST_PIEZA pieza[], ST_CATEGORIAS categoria[]){
    for (int i = 0; i < CANT_CATEGORIAS; i++)
    {
        cout << "nombre de la categoria: " << categoria[i].nombre << endl;
        for (int j = 0; j < CANT_OBRAS; j++)
        {     
        if (categoria[i].CodCategoria == pieza[j].categoria)
        {
            cout << pieza[j].autor << endl;
        }
        }
    }
}

int main()
{
    ST_PIEZA piezaA[CANT_OBRAS];
    ST_PIEZA piezaB[CANT_OBRAS];

    unificarConjunto(piezaA, piezaB);

    return 0;
}