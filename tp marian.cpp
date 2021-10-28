#include <iostream>

using namespace std;

#define CORPORATIVO 'C'
#define SOCIAL 'S'
#define OTRO 'O'
#define MENU1 1
#define MENU2 2

void divisorFecha (int fecha, int& dia, int& mes, int& anio){
    dia = fecha % 100;
    mes = (fecha/100)%100;
    anio = fecha/10000;
}

float promedioFiestas (float totalFiestas, float totalPersonas){
    float promedio;
    promedio = totalPersonas/totalFiestas;
    return promedio;
}

void fechaMaxMenu (int cantidadPersonas, char menu, int fecha, int&fechaMenu1, int& fechaMenu2){
    int cantidadMaxMenu;
    if (cantidadMaxMenu < cantidadPersonas && menu == MENU1){
        cantidadMaxMenu = cantidadPersonas;
        fechaMenu1 = fecha;
    }
    else if (cantidadMaxMenu < cantidadPersonas && menu == MENU2){
        cantidadMaxMenu = cantidadPersonas;
        fechaMenu2 = fecha;
        }
}

void fechaMaxPersonas (int cantidadPersonas, int fechaFiesta, int& fechaMax){
    int cantidadMaxPersonas;
    if ( cantidadMaxPersonas < cantidadMaxPersonas){
        cantidadMaxPersonas = cantidadPersonas;
        fechaMax = fechaFiesta;
    }
}

void totalesTipo (char tipoFiesta, int& totalC, int& totalS, int& totalO){
    switch (tipoFiesta){
    case 'C':
        totalC++;
        break;
    case 'S':
        totalS++;
        break;
    case 'O':
        totalO++;
        break;
    }
}

int main () {

    int fecha = 1;
    char tipoFiesta = 0;
    int cantidadPersonas = 0;
    char numeroMenu = 0;

    int totalC = 0, totalS = 0, totalO = 0;
    int fechaMax = 0;
    int dia = 0, mes = 0, anio = 0;
    int fechaMenu1 = 0, fechaMenu2 = 0;
    int totalFiestas = 0, totalPersonas = 0;

    cout << "INGRESE UN NUMERO NEGATIVO PARA TERMINAR." << endl << endl;

    cout << "Ingrese la fecha de la fiesta (8 digitos en formato AAAAMMDD): ";
    cin >> fecha; //aca pedis la fecha para entrar al while, y con esa fecha nunca la mandas a la funcion de fecha xq esta fuera del while la llamada

    while (fecha > 0){
        cout << "Ingrese el tipo de fiesta ('C', 'S', 'O'): ";
        cin >> tipoFiesta;

        cout << "Ingrese la cantidad de personas: ";
        cin >> cantidadPersonas;

        cout << "Ingrese el nro de menu elegido (1, o 2): ";
        cin >> numeroMenu;
        cout << endl;

        totalFiestas++;
        totalPersonas++;
        totalesTipo(tipoFiesta, totalC, totalS, totalO);
        fechaMaxPersonas (cantidadPersonas, fecha, fechaMax);
        fechaMaxMenu (cantidadPersonas, numeroMenu, fecha, fechaMenu1, fechaMenu2);

        cout << endl << "INGRESE UN NUMERO NEGATIVO PARA TERMINAR." << endl << endl;

        cout << "Ingrese la fecha de la fiesta (8 digitos en formato AAAAMMDD): ";
        cin >> fecha;

        }

    cout << endl << endl;
    cout << "El total de fiestas de tipo C es: " << totalC << endl;
    cout << "El total de fiestas de tipo S es: " << totalS << endl;
    cout << "El total de fiestas de tipo O es: " << totalO << endl;

    divisorFecha (fechaMax, dia, mes, anio); //aca llamas a la fecha y ya vale 0
    cout << "La fecha para la cual se realizara la fiesta con mayor cantidad de personas es: ";
    cout << dia << "/" << mes << "/" << anio << endl;

    divisorFecha (fechaMenu1, dia, mes, anio); // esta tambien xq no tomaste ningun dato
    cout << "La fecha de la fiesta con mayor cantidad de menu 1 es:";
    cout << dia << "/" << mes << "/" << anio << endl;

    divisorFecha (fechaMenu2, dia, mes, anio); // esta tambien
    cout << "La fecha de la fiesta con mayor cantidad de menu 2 es:";
    cout << dia << "/" << mes << "/" << anio << endl;

    cout << "El promedio de personas de todas las fiestas es: ";
    cout << promedioFiestas(totalFiestas, totalPersonas) << endl; // esta no me acuerdo

    system("pause");
    return 0;
}