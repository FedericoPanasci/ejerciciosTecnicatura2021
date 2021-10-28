#include <iostream>

using namespace std;
/*

Completar la función faltante para que el programa realice lo siguiente:

Dado un vector de notas de alumnos completar otro vector con los alumnos que aprobaron.
Por cada alumno se tienen siempre N notas y están todas juntas.
El vector resultante contendrá los números de orden de los alumnos que hayan aprobado, se aprueba con promedio de 6 o más.


ej: 

Si tenemos un N de 3 y el siguiente vector de notas de alumnos

Notas = { 4, 6, 2, 
          5, 6 ,7, 
          6, 5, 6, 
          2, 4, 8, 
          9, 10,2, 
          5, 6, 7 }   

entonces Aprobados = { 2, 5, 6 }

Proque el 2do, 5to y 6to alumno del vector tienen promedios de 6 o más.

*/

// Esta funcion debe recibir el vector de notas, la cantidad de notas, la cantidad de notas por alumno y llenar el vector de aprobados
/*void aprobados(int vecA[], int cantNotas, int notasAlum, int vecC[], int &cant) {
    int notas = 0;
    int cantXalumn = 0;
    int i = 0;
    int alumno = 1;
    while (i < cantNotas)
    {   
        for (int j = 0; j < 3; j++)
        {
            notas = notas + vecA[i];
            i++;
        }
        if (notas / 3 >= 6)
        {
            vecC[cant] = alumno;
            notas = 0;
            cant++;
            cantXalumn = 0;
            alumno++;
        }
        else
        {
            alumno++;
        }
        notas = 0;
        cantXalumn = 0;
    }
}*/

void aprobados(int notas[], int cantTotal, int cantXAlumno, int aprobados[], int &cantAprobados) {
  cantAprobados = 0;
  int i = 0;
  int alum = 1;
  while(i < cantTotal) {
    int k = i + 3;
    float prom = 0;
    while(i < cantTotal && i < k) {
      prom += notas[i];
      i++;
    }
    if(prom/3 >= 6 ) {
      aprobados[cantAprobados] = alum;
      cantAprobados++;
    }    
    alum++;
  }
}

void imprimir(int vec[], int cant)
{
    cout << "Copiar los valores entre numerales #99999999#" << endl
         << "=========================================="
         << endl
         << "#";
    for (int i = 0; i < cant; i++)
    {
        cout << vec[i] << "";
    }
    cout <<"#"
         << endl
         << "==========================================" << endl;
}

int main() {
    int vecA[] = {8,5,10,10,2,2,3,9,5,8,2,10,6,5,10,9,5,7,10,4,5,3,5,2,3,6,6,9,5,10,8,2,5,8,9,8,3,2,2,7,4,10,3,4,7,3,5,7,10,7,10,5,8,9,9,8,8,8,4,3,8,8,6,2,4,6,2,3,4,10,3,7,3,7,9,4,3,8,3,5,4,2,4,8,10,2,3,3,4,2,6,4,5,6,7,10,3,7,3,3,5,5,7,3,7,9,10,10,5,6,4,5,3,6,8,10,9,3,7,5,3,5,10,9,4,8,7,4,7,8,4,6,5,4,4,4,8,7,6,8,4,9,6,6,10,8,6,4,8,5,10,4,4,4,7,5,10,10,9,6,7,3,8,6,3,5,6,3,6,8,4,10,3,9,7,3,6,10,4,9,5,8,7,3,10,7,3,9,10,5,8,10,4,3,6,10,10,7};
    
    int vecC[188] = {0};

    int cant = 0;
    aprobados(vecA, 188, 3, vecC, cant);

    imprimir(vecC, cant);
    system("pause");
}