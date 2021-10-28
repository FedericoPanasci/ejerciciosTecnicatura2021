#include <iostream>

using namespace std;
#define CANT_ALUMNOS 1000

struct ST_ALUMNOS
{
    int legajo;
    string apellidoYNombre;
    string curso;
    int parcial1;
    int parcial2;
};

void imprimir(ST_ALUMNOS alumno[]){
    int i = 0;
    string curso = " ";
    int aprobados = 0;
    int promedio = 0;
    int cantAlumnos = 0;
    int notaAprobada = 6;
    while (i < CANT_ALUMNOS)
    {
        curso = alumno[i].curso;
        cout << "Curso: " << curso << endl;
        cantAlumnos = 0;
        aprobados = 0;
        while (i < CANT_ALUMNOS && curso == alumno[i].curso)
        {
            cantAlumnos++;
            promedio = (alumno[i].parcial1 + alumno[i].parcial2) / 2;
            i++;
            if (promedio >= notaAprobada)
            {
                cout << "Legajo: " << alumno[i].legajo << " - " << alumno[i].apellidoYNombre << " - Nota: " << promedio << endl;
                aprobados++;
            }
        }
        cout << "----------" << endl;
        cout << "Total alumnos aprobados: " << aprobados << " / " << cantAlumnos << endl;
    }
}

int main () {
    ST_ALUMNOS alumnos[CANT_ALUMNOS];
    imprimir(alumnos);
    system("pause");
    return 0;
}