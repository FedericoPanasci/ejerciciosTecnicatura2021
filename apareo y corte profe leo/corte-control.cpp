#include <iostream>
using namespace std;

struct Presente {
    int legajo;
    int fecha;
    bool presente;
};

void listarAusentismo(Presente asistencias[], int cantAsistencias) {
    int i = 0;
    int key = 0;
    int ausentes = 0;
    int ausentesTotales = 0;
    int cantAlumnos = 0;
    while(i < cantAsistencias) {

        key = asistencias[i].legajo;
        ausentes = 0;
        while(key == asistencias[i].legajo) {
            // ausentes = ausentes + (asistencias[i].presente ? 0 : 1);
            if (!asistencias[i].presente) {
                ausentes++;
            }

            i++;
        }

        cout << "El legajo " << key << " falto " << ausentes << " veces." << endl;
        ausentesTotales += ausentes;
        cantAlumnos++;
    }

    cout << "En total los alumnos faltaron: " << ausentesTotales << endl;
    cout << "Es decir " << ausentesTotales / (float) cantAlumnos << " faltas promedio por alumno"<< endl;



}

int main () {

    // 11709099  20200512  1      key = 11709099  cant = 0
    // 11709099  20200512  1
    // 11709099  20200512  0
    // 11709099  20200512  1
    // 11709099  20200512  0
    // 11709099  20200512  1
    //                         "El legajo 11709099 falto 2 veces"

    // 11808937  20200512  1     key = 11808937  cant = 0
    // 11808937  20200512  1
    // 11808937  20200512  1
    // 11808937  20200512  1
    // 11808937  20200512  1
    // 11808937  20200512  1
    //                         "El legajo 11808937 falto 0 veces"


    // 11709099  2
    // 11808937  0

    system("pause");
    return 0;
}