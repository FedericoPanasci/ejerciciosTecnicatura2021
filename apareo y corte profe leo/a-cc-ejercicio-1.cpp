#include <iostream>
using namespace std;

#define MAX_MAESTRO 10
#define MAX_DIARIO 5

/**
 * Se dispone un vector de inscripción de alumnos a exámenes finales MAESTROFINALES y otro con las inscripciones
 * del día de hoy DIAFINALES, ambos ordenados ascendente por código de materia y con el siguiente diseño:

- Nro de legajo (8 dígitos)
- Código de materia (6 dígitos)
- ApellidoNombre(cadena)

Se pide desarrollar un procedimiento que complete un nuevo vector de inscripciones a finales FINALESACT resultante
del apareo de los dos vectores anteriores, con el mismo orden y diseño.
*/


struct Final {
    int legajo;
    int codigoMateria;
    string apellidoNombre;
};

void aparear(Final maestro[], int cantMaestro, Final diarios[], int cantDiario, Final actualizado[], int& cantActualizado) {

    int i = 0, j = 0;
    cantActualizado = 0;

    while(i < cantMaestro && j < cantDiario) {
        if (maestro[i].codigoMateria < diarios[j].codigoMateria) {
            actualizado[cantActualizado] = maestro[i];
            i++;
        } else {
            actualizado[cantActualizado] = diarios[j];
            j++;
        }
        cantActualizado++;
    }

    while(i < cantMaestro) {
        actualizado[cantActualizado] = maestro[i];
        i++;
        cantActualizado++;
    }

    while(j < cantDiario) {
        actualizado[cantActualizado] = diarios[j];
        j++;
        cantActualizado++;
    }
    return;
}

void cargar(Final finales[], int cant, int inicio) {
    for (int i = 0; i < cant; i++) {
        finales[i].legajo = 1000 + i + inicio;
        finales[i].codigoMateria = 10 + i;
        finales[i].apellidoNombre = "Alumno - " + i + inicio;
    }
    return;
}

void imprimir(Final finales[], int cant) {
    for (int i = 0; i < cant; i++) {
        cout << "Materia: " << finales[i].codigoMateria << " Legajo:"  << finales[i].legajo << " Nombre:" << finales[i].apellidoNombre << endl;
    }

}

int main () {

    Final maestro[MAX_MAESTRO];
    Final diarios[MAX_DIARIO];
    Final actualizados[MAX_MAESTRO + MAX_DIARIO];

    cargar(maestro, MAX_MAESTRO, 500);
    cargar(diarios, MAX_DIARIO, 600);

    int cantActualizado = 0;
    aparear(maestro, MAX_MAESTRO, diarios, MAX_DIARIO, actualizados, cantActualizado);

    imprimir(actualizados, cantActualizado);


    system("pause");
    return 0;
}