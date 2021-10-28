#include <iostream>

using namespace std;
#define CANT_DIAS 28

/*
1. Cargar las temperaturas de 1 mes.
2. Generar un listado que imprima por pantalla la tendencia (creciente, decreciente u otra) de
cada semana.
3. Mostar por pantalla cuál es la temperatura máxima del mes y en qué semana se encuentra.
4. Para un día ingresado por el usuario, mostrar las temperaturas de dicho día en cada semana.
Tener en cuenta que el usuario ingresará "Lunes", "Martes", ..., "Domingo". Se asume que
la primer temperatura cargada corresponde al día Lunes y la sexta al Domingo
*/

void cargarDias(float dias[CANT_DIAS]){
    for (int i = 0; i < CANT_DIAS; i++)
    {
        cout << "ingrese la temperatura del dia " << i+1 << ": ";
        cin >> dias[i];
    }
    return;
}

void tendencia(float dias[CANT_DIAS], int menor, int mayor, int X){
    float temperatura = -20;
    int i = menor, inicio = menor;
    while (inicio <= mayor && temperatura <= dias[i])
    {
        temperatura = dias[i];
        i++;
        inicio++;
    }
    if (inicio > mayor)
    {
        cout << "semana " << X << ": creciente." << endl;
    }
    else
    {
        temperatura = 50;
        i = menor;
        inicio = menor;
        while (inicio <= mayor && temperatura >= dias[i])
    {
        temperatura = dias[i];
        i++;
        inicio++;
    }
            if (inicio > mayor)
            {
                cout << "semana " << X << ": decreciente." << endl;
            }
            else
            {
                cout << "semana " << X << ": otra." << endl;
            }
    }
    return;
}

void temperaturaMaxima(float dias[CANT_DIAS]){
    int maxima = -20;
    int semana = 0;
    for (int i = 0; i < CANT_DIAS; i++)
    {
        if (dias[i] > maxima)
        {
            maxima = dias[i];
            semana = (i / 7)+1;           
        }
    }
    cout << "la temperatura maxima fue: " << maxima << "grados y se dio en la semana: " << semana << endl;
}

int queDiaEs(float dias[CANT_DIAS], string nombre){
    int dia = 0;
    if (nombre == "lunes")
    {
        dia = 1;
    }
    if (nombre == "martes")
    {
        dia = 2;
    }
    if (nombre == "miercoles")
    {
        dia = 3;
    }
    if (nombre == "jueves")
    {
        dia = 4;
    }
    if (nombre == "viernes")
    {
        dia = 5;
    }
    if (nombre == "sabado")
    {
        dia = 6;
    }
    if (nombre == "domingo")
    {
        dia = 7;
    }
    return dia;
}

void imprimirDias(float dias[CANT_DIAS], int dia) {
    switch (dia)
    {
    case 1:
        cout << "las temperaturas de los dias lunes fue: " << dias[0] << ", " << dias[7] << ", " << dias[14] << ", " << dias[21] << endl;
        break;
    case 2:
        cout << "las temperaturas de los dias martes fue: " << dias[1] << ", " << dias[8] << ", " << dias[15] << ", " << dias[22] << endl;
        break;
    case 3: 
        cout << "las temperaturas de los dias miercoles fue: " << dias[2] << ", " << dias[9] << ", " << dias[16] << ", " << dias[23] << endl;
        break;
    case 4:
        cout << "las temperaturas de los dias jueves fue: " << dias[3] << ", " << dias[10] << ", " << dias[17] << ", " << dias[24] << endl;
        break;
    case 5:
        cout << "las temperaturas de los dias viernes fue: " << dias[4] << ", " << dias[11] << ", " << dias[18] << ", " << dias[25] << endl;
        break;
    case 6:
        cout << "las temperaturas de los dias sabado fue: " << dias[5] << ", " << dias[12] << ", " << dias[19] << ", " << dias[26] << endl;
        break;
    case 7:
        cout << "las temperaturas de los dias domingo fue: " << dias[6] << ", " << dias[13] << ", " << dias[20] << ", " << dias[27] << endl;
    }
    return;
}

void diaEspecifico(float dias[CANT_DIAS]){
    string nombre = "lunes";
    cout << "ingrese el dia que quiere conocer sus temperaturas: ";
    cin >> nombre;
    int dia;
    dia = queDiaEs(dias, nombre);
    imprimirDias(dias, dia);
    return;
}


int main () {
    float dias[CANT_DIAS] = {0};

    cargarDias(dias);
    /*semana 1*/ tendencia(dias, 0, 6, 1);
    /*semana 2*/ tendencia(dias, 7, 13, 2);
    /*semana 3*/ tendencia(dias, 14, 20, 3);
    /*semana 4*/ tendencia(dias, 21, 27, 4);
    temperaturaMaxima(dias);
    diaEspecifico(dias);
    
    system("pause");
    return 0;
}