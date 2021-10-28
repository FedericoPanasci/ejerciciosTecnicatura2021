#include <iostream>

using namespace std;

/*Ejercicio 2 - Salón de Fiestas
Una Empresa dedicada a realizar servicios para fiestas, nos pide la confección de un programa que les permita obtener algunos datos
estadísticos procesando la información que tienen de las fiestas que se van a realizar.
Para ello ingresan la siguiente información ya validada:
Fecha de la fiesta (8 dígitos en formato AAAAMMDD)
Tipo de fiesta (‘C’, ’S', ‘O’)
Cantidad de personas
Nro de menú elegido (1, ó 2). En cada fiesta sólo se elige un menú.
El proceso finaliza cuando se ingresa una fecha negativa.
Se pide:
a. Informar cuantas fiestas hay de cada tipo.
b. La fecha para la cuál se realizará la fiesta con mayor cantidad de personas (suponer único máximo)
c. La fecha de la fiesta con mayor cantidad de menú 1 y la fecha de la fiesta con mayor cantidad de menú 2. (suponer único
máximo)
d. El promedio de personas de todas las fiestas.
Nota: Para el punto “b” y “c” las fechas deben ser impresas como DD/MM/YYYY
*/
int fechaDDMMAAAA(int X, int &dia, int &mes, int &anio)
{
    anio = (X / 10000);

    mes = (X / 100) - anio * 100;

    dia = X % 100;

    return dia, mes, anio;
}

/*salida A:*/ void cantidadFiestas(int C, int S, int O)
{
    cout << "fiestas tipo C hay: " << C << ", fiestas tipo S hay: " << S << ", y fiestas tipo O hay: " << O << endl;
    return;
}
/*salida B*/ void fechaConMasPersonas(int fecha)
{
    int dia = 0, mes = 0, anio = 0;
    fechaDDMMAAAA(fecha, dia, mes, anio);
    cout << "la fecha de la fiesta con mayor cantidad de personas es: " << dia << "/" << mes << "/" << anio << endl;
    return;
}

/*salida C parte 1*/ void fiestaMayorMenu1(int menu1)
{
    int dia1 = 0, mes2 = 0, anio3 = 0;
    menu1 = fechaDDMMAAAA(menu1, dia1, mes2, anio3);
    cout << "la fecha que eligio el menu 1 y tiene mas asistencia es: " << dia1 << "/" << mes2 << "/" << anio3 << endl;
    return;
}
/*salida C parte 2*/ void fiestaMayorMenu2(int menu2)
{
    int dia1 = 0, mes2 = 0, anio3 = 0;
    menu2 = fechaDDMMAAAA(menu2, dia1, mes2, anio3);
    cout << "la fecha que eligio el menu 2 y tiene mas asistencia es: " << dia1 << "/" << mes2 << "/" << anio3 << endl;
}

int main()
{
    int fechaFiesta = 0, cantidadPersonas = 0, mayorPersonas = 0, fiestaMayorPersonas = 0, menuElegido = 0, personasTotal = 0, cantidadDeFiestas = 0;
    int cantidadFiestaC = 0, cantidadFiestaS = 0, cantidadFiestaO = 0, menu1 = 0, menu2 = 0, mayorMenu1 = 0, mayorMenu2 = 0, promedioDePersonas = 0;

    char tipoDeFiesta = '*';

    cout << "ingrese la fecha de la fiesta en forma AAAAMMDD (si el numero es negativo finaliza el programa): ";
    cin >> fechaFiesta;

    while (fechaFiesta > 0)
    {
        cantidadDeFiestas++;
        
        cout << "ingrese el tipo de fiesta que se va a realizar 'C, S u O': ";
        cin >> tipoDeFiesta;
        
        cout << "ingrese la cantidad de personas que asistiran a la fiesta: ";
        cin >> cantidadPersonas;

        cout << "ingrese cual fue el menu elegido (1 o 2): ";
        cin >> menuElegido;
        
        if (tipoDeFiesta == 'C' || tipoDeFiesta == 'c')
        {
            cantidadFiestaC++;
        }
        if (tipoDeFiesta == 'S' || tipoDeFiesta == 's')
        {
            cantidadFiestaS++;
        }
        if (tipoDeFiesta == 'O' || tipoDeFiesta == 'o')
        {
            cantidadFiestaO++;
        }

        if (cantidadPersonas > mayorPersonas)
        {
            mayorPersonas = cantidadPersonas;
            fiestaMayorPersonas = fechaFiesta;
        }
        if (menuElegido == 1)
        {
            menu1++;
            if (mayorMenu1 < cantidadPersonas)
            {
                mayorMenu1 = fechaFiesta;
            }
        }
        else
        {
            menu2++;
            if (mayorMenu2 < cantidadPersonas)
            {
                mayorMenu2 = fechaFiesta;
            }
        }
        personasTotal = personasTotal + cantidadPersonas;

        cout << "ingrese otra fecha de fiesta en forma AAAAMMDD (si el numero es negativo finaliza el programa): ";
        cin >> fechaFiesta;
    }
    /*salida A*/ cantidadFiestas(cantidadFiestaC, cantidadFiestaS, cantidadFiestaO);
    /*salida B*/ fechaConMasPersonas(fiestaMayorPersonas);
    /*salida C parte 1*/fiestaMayorMenu1(mayorMenu1);
    /*salida C parte 2*/fiestaMayorMenu2(mayorMenu2);
    promedioDePersonas = personasTotal / cantidadDeFiestas;
    /*salida D*/ cout << "la cantidad promedio de personas que asisten a las fiestas es: " << promedioDePersonas << endl;
    system("pause");
    return 0;
}