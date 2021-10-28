#include <iostream>

using namespace std;

typedef struct ALUMNO
{
    int legajo;
    string nomYApe;
    string curso;
    int parcial1;
    int parcial2;
} ST_ALUMNO;

void imprimirCorte(ST_ALUMNO alumno[], int cant)
{
    string cursoKey;
    int i = 0;
    int aprobados = 0, cantAlumnos = 0;;
    while (i < cant)
    {
        cursoKey = alumno[i].curso;
        cout << "Curso: " << cursoKey << endl;
        int promedio = 0;
        while (alumno[i].curso == cursoKey && i < cant)
        {
            promedio = (alumno[i].parcial1 + alumno[i].parcial2) / 2;
            cantAlumnos++;
            if (promedio >= 6)
            {
                aprobados++;
            }
            cout << "legajo: " << alumno[i].legajo << " - " << alumno[i].nomYApe << " - Nota: " << promedio << endl;
            i++;
        }
        cout << "------------------------" << endl;
        cout << "total de aprobados: " << aprobados << "/" << cantAlumnos;
        aprobados = 0;
        cantAlumnos = 0;
    }
}

int main()
{
    ST_ALUMNO alumno[10];
    imprimirCorte(alumno, 10);
    system("pause");
    return 0;
}