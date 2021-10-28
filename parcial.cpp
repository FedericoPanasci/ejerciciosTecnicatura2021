#include <iostream>

using namespace std;
#define MAXCAT 30

struct ST_CONTADO
{
    string nombre;
    int codigo;
    int cod_categoria;
    float precio;
};

struct ST_CUOTAS
{
    string nombre;
    int codigo;
    int cod_categoria;
    float precioEn3;
    float precioEn6;
    float precioEn12;
};

struct ST_CATEGORIAS
{
    string nombre;
    int codigo;
};

struct ST_RESULTADO
{
    int codigo;
    string nombre;
    float precioContado;
    float precioCuotas;
    int cantCuotas;
};

void apareo(ST_CUOTAS a[MAXCAT], ST_CONTADO b[MAXCAT], ST_CATEGORIAS c[MAXCAT], ST_RESULTADO apareo[MAXCAT]){
    int i = 0, j = 0, k = 0;
    while (i < MAXCAT && j < MAXCAT)
    {
        if (a[i].codigo == b[j].codigo)
        {
            apareo[k].codigo = a[i].codigo;
            apareo[k].nombre = a[i].nombre;
            apareo[k].precioContado = b[j].precio;
            if (a[i].precioEn12 != 0)
            {
                apareo[k].precioCuotas = a[i].precioEn12;
                apareo[k].cantCuotas = 12;            
            }
            else if(a[i].precioEn6 != 0){
                apareo[k].precioCuotas = a[i].precioEn6;
                apareo[k].cantCuotas = 6;
            }
            else{
                apareo[k].precioCuotas = a[i].precioEn3;
                apareo[k].cantCuotas = 3;
            }
            i++;
            j++;
            k++;
        }
        
        if (a[i].codigo < b[j].codigo)
        {
            apareo[k].codigo = a[i].codigo;
            apareo[k].nombre = a[i].nombre;
            if (a[i].precioEn12 != 0)
            {
                apareo[k].precioCuotas = a[i].precioEn12;
                apareo[k].cantCuotas = 12;            
            }
            else if(a[i].precioEn6 != 0){
                apareo[k].precioCuotas = a[i].precioEn6;
                apareo[k].cantCuotas = 6;
            }
            else{
                apareo[k].precioCuotas = a[i].precioEn3;
                apareo[k].cantCuotas = 3;
            }
            apareo[k].precioContado = apareo[k].precioCuotas * apareo[k].cantCuotas;
            i++;
            k++;
        }
        
        if (b[j].codigo < a[i].codigo)
        {
            apareo[k].codigo = b[j].codigo;
            apareo[k].nombre = b[j].nombre;
            apareo[k].precioContado = b[j].precio;
            apareo[k].precioCuotas = 0;
            apareo[k].cantCuotas = 0;
            j++;
            k++;
        }
    }
    return;
}

void imprimir(int vec[3], ST_RESULTADO a[MAXCAT]){
    int codMayor = vec[0], codMedio = vec[1], codMenor = vec[2];
    cout << "El producto de mayor precio en contado es: " << a[codMayor - 1].nombre << " con valor de " << a[codMayor - 1].precioContado;
    cout << "El producto de 2do mayor precio en contado es: " << a[codMedio - 1].nombre << " con valor de " << a[codMedio - 1].precioContado;
    cout << "El producto de 3er mayor precio en contado es: " << a[codMenor - 1].nombre << " con valor de " << a[codMenor - 1].precioContado;
}

void mayor(int vec[3], ST_RESULTADO resultado[MAXCAT]){
    int mayor = -1, medio = 0, menor = 0;
    for (int i = 0; i < MAXCAT; i++)
    {
        if (resultado[i].precioContado > mayor)
        {
            vec[2] = vec[1];
            vec[1] = vec[0];
            vec[0] = resultado[i].codigo;
        }
        if (resultado[i].precioContado > medio)
        {
            vec[2] = vec[1];
            vec[1] = resultado[i].codigo;
        }
        if (resultado[i].precioContado > menor)
        {
            vec[2] = resultado[i].codigo;
        }     
    }
    imprimir(vec, resultado);
}

int main () {
    ST_CUOTAS cuotas[MAXCAT];
    ST_CONTADO contado[MAXCAT];
    ST_CATEGORIAS categorias[MAXCAT];
    ST_RESULTADO resultado[MAXCAT+MAXCAT];

    apareo(cuotas, contado, categorias, resultado);
    int vec[3];
    mayor(vec, resultado);


    system("pause");
    return 0;
}