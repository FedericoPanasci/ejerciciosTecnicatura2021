#include <iostream>

using namespace std;
#define MAX_MAESTROS 10
#define MAX_FINALES 5
/*
1- Se dispone un vector de inscripción de alumnos a exámenes finales MAESTROFINALES y otro con las inscripciones del día de hoy DIAFINALES, ambos ordenados ascendente por 
código de materia y con el siguiente diseño:

- Nro de legajo (8 dígitos)
- Código de materia (6 dígitos)
- ApellidoNombre(cadena)

Se pide desarrollar un procedimiento que complete un nuevo vector de inscripciones a finales FINALESACT resultante del apareo de los dos vectores anteriores,
 con el mismo orden y diseño.

*/
struct ST_FINALES
{
    int legajo;
    int codigoDeMateria;
    string apellidoNombre;
};

void aparear(ST_FINALES maestro[], int cantMaestro, ST_FINALES diario[], int cantDiario, ST_FINALES actualizado[], int& cantActualizado) {
    int i = 0, j = 0, cantActualizado = 0;
    while (i < cantMaestro && j < cantDiario)
    {
        if (maestro[i].codigoDeMateria < diario[j].codigoDeMateria)
        {
            actualizado[cantActualizado] = maestro[i];
            i++;
        }
        else
        {
            actualizado[cantActualizado] = diario[j];
            j++;
        }
        cantActualizado++;
    }
    while (i < cantMaestro)
    {
        actualizado[cantActualizado] = maestro[i];
        i++;
        cantActualizado++;
    }
        while (j < cantDiario)
    {
        actualizado[cantActualizado] = diario[j];
        j++;
        cantActualizado++;
    }
    return;
}

void cargar(ST_FINALES finales[], int cant, int inicio){
    for (int i = 0; i < cant; i++)
    {
        finales[i].legajo = 1000 + 1 + inicio;
        finales[i].codigoDeMateria = 10 + 1;
        finales[i].apellidoNombre = "perez " + i + inicio;
    }
    return;
}

void imprimir(ST_FINALES final[], int cant){
    for (int i = 0; i < cant; i++)
    {
        cout << "materia: " << final[i].codigoDeMateria << "legajo: " << final[i].legajo << "apellido del alumno: " << final[i].apellidoNombre << endl;
    }
    
}
int main () {
    ST_FINALES maestro[MAX_MAESTROS];
    ST_FINALES finales[MAX_FINALES];
    ST_FINALES actualizados[MAX_FINALES + MAX_MAESTROS];

    cargar(maestro, MAX_MAESTROS, 500);
    cargar(finales, MAX_FINALES, 600);

    imprimir(actualizados, MAX_FINALES + MAX_MAESTROS);
    

    system("pause");
    return 0;
}