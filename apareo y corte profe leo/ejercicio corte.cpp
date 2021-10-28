#include <iostream>

using namespace std;

#define CANT_ALUMNOS 100

struct ST_ALUMNO
{
    int legajo;
    string apellidonombre;
    int nota;
    int codigoMateria;
    string mes;
};

void imprimir(ST_ALUMNO alumnos[]){
    int codigoMateria = 0;
    int i = 0;
    cout << "legajo   nombre y apellido     codigo de materia" << endl;
    while (i < CANT_ALUMNOS) 
    {
        codigoMateria = alumnos[i].codigoMateria;
        while (i < CANT_ALUMNOS && codigoMateria == alumnos[i].legajo)
        {
            cout << alumnos[i].legajo << "  " << alumnos[i].apellidonombre << "   " << alumnos[i].codigoMateria << endl;
            i++;
        }
        
    }
    
}

void ordenarAlumnosPorCodigo(ST_ALUMNO alumnos[], int cant){
    int i = 0;
    bool ordenado = false;
    ST_ALUMNO aux;
    while (i < cant && !ordenado)
    {   
        ordenado = true;
        for (int j = 0; i < cant - i - 1; i++)
        {
            if (alumnos[j].codigoMateria < alumnos[j+1].codigoMateria)
            {
                aux = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = aux;
                ordenado = false;
            } 
        }
        i++;
    }
    imprimir(alumnos);
}

int main () {
    ST_ALUMNO alumnos[100];

    system("pause");
    return 0;
}