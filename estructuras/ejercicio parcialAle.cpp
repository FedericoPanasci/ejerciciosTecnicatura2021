#include <iostream>

using namespace std;

void llenarVector(int vec[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        cout << "Ingrese un numero: ";
        cin >> vec[i];
        cout << endl;
    }
}

void imprimirResultadoUno(int aux1[], int n)
{
    cout << "Resultado 1: " << endl;
    for (int h = 0; h < n; h++)
    {
        cout << aux1[h] << endl;
    }
}

void resultadoUno(int aux1[], int v1[], int v2[], int m)
{
    int i = 0;
    while (i < m)
    {
        aux1[i] = v1[i] + v2[m - 1 - i];
        i++;
    }
    imprimirResultadoUno(aux1, m);
}

void imprimirResultadoDos(int aux2[], int m){
    cout << "Resultado 2: " << endl;
    for (int h = 0; h < m; h++)
    {
        cout << aux2[h] << endl;
    }
}

void resultadoDos(int aux2[], int v1[], int v2[], int m){
    int j = 0;
    while (j < m)
    {
        aux2[j] = v1[j] - v2[j];
        j++;
    }
    imprimirResultadoDos(aux2, m);
}

void imprimirEscalar(int escalar[], int n){
    cout << "Resultado del producto escalar: " << endl;
    for (int h = 0; h < n; h++)
    {
        cout << escalar[h] << endl;
    }
}

void vectorEscalar(int escalar[], int v1[], int v2[], int n){
    for (int k = 0; k < n; k++)
    {
        escalar[k] = escalar[k] + (v1[k] * v2[k]);
    }
    imprimirEscalar(escalar, n);
}

int main()
{
    int n = 0;
    int m = 0;

    cout << "Ingrese la cantidad de numeros que tendra el primer grupo: ";
    cin >> n;
    cout << endl;
    int vec1[n];

    cout << "Ingrese la cantidad de numeros que tendra el segundo grupo: ";
    cin >> m;
    cout << endl;
    int vec2[m];

    if (n != m)
    {
        // termina el programa
        return 1;
    }

    llenarVector(vec1, n);
    llenarVector(vec2, m);

    int aux1[n];
    int aux2[n];
    resultadoUno(aux1, vec1, vec2, m);
    resultadoDos(aux2, vec1, vec2, m);

    int escalar[n] = {0}; 
    /*inicializamos escalar (vector"p") porque se realizara la siguiente funcion: escalar[k] = escalar[k] + (v1[k] * v2[k]). Entonces
    se sumara a lo que el vector posea en la posicion correspondiente,
    entonces si el vector no esta inicializado la funcion se sumara a basura, pero inicializando en 0 se suma a ese valor en cada posicion.
    si la funcion hubiera sido: escalar[k] = v1[k] * v2[k] no tendria sentido dado que se asignaria el valor unicamente*/
    vectorEscalar(escalar, vec1, vec2, n);

    system("pause");
    return 0;
}