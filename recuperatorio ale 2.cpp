#include <iostream>

using namespace std;
#define DIAS 30
#define MESES 12

void imprimir(float temperatura[DIAS][MESES], int dia, int mes){
    switch (mes)
    {
    case 0:
        cout << "La Temperatura Máxima del año es: " << temperatura[dia][mes] << ". Se detectó el " << dia+1 << " de enero." << endl;
        break;
    case 1:
        cout << "La Temperatura Máxima del año es: " << temperatura[dia][mes] << ". Se detectó el " << dia+1 << " de febrero." << endl;
        break;
    case 2:
        cout << "La Temperatura Máxima del año es: " << temperatura[dia][mes] << ". Se detectó el " << dia+1 << " de marzo." << endl;
        break;
    case 3:
        cout << "La Temperatura Máxima del año es: " << temperatura[dia][mes] << ". Se detectó el " << dia+1 << " de abril." << endl;
        break;
    case 4:
        cout << "La Temperatura Máxima del año es: " << temperatura[dia][mes] << ". Se detectó el " << dia+1 << " de mayo." << endl;
        break;
    case 5:
        cout << "La Temperatura Máxima del año es: " << temperatura[dia][mes] << ". Se detectó el " << dia+1 << " de junio." << endl;
        break;
    case 6:
        cout << "La Temperatura Máxima del año es: " << temperatura[dia][mes] << ". Se detectó el " << dia+1 << " de julio." << endl;
        break;
    case 7:
        cout << "La Temperatura Máxima del año es: " << temperatura[dia][mes] << ". Se detectó el " << dia+1 << " de agosto." << endl;
        break;
    case 8:
        cout << "La Temperatura Máxima del año es: " << temperatura[dia][mes] << ". Se detectó el " << dia+1 << " de septiembre." << endl;
        break;
    case 9:
        cout << "La Temperatura Máxima del año es: " << temperatura[dia][mes] << ". Se detectó el " << dia+1 << " de octubre." << endl;
        break;
    case 10:
        cout << "La Temperatura Máxima del año es: " << temperatura[dia][mes] << ". Se detectó el " << dia+1 << " de noviembre." << endl;
        break;
    case 11:
        cout << "La Temperatura Máxima del año es: " << temperatura[dia][mes] << ". Se detectó el " << dia+1 << " de diciembre." << endl;
        break;    

    }
}

void imprimirMaximaAnio(float temperaturas[DIAS][MESES]){
    float max = 0;
    int dia = 0;
    int mes = 0;
    for (int i = 0; i < MESES; i++)
    {
        for (int j = 0; j < DIAS; j++)
        {
            if (temperaturas[j][i] > max)
            {
                max = temperaturas[j][i];
                dia = j;
                mes = i;
            }
        }
    }
    imprimir(temperaturas, dia, mes); 
}

void imprimirFinal(string mensaje, float max){
    cout << mensaje << " " << max << endl;
}

void calcularMaxMes(string mensaje, float temperaturas[DIAS][MESES], int mes){
    float max = 0;
    for (int i = 0; i < DIAS; i++)
    {
        if (temperaturas[i][mes] > max)
        {
            max = temperaturas[i][mes];
        }
    }
    imprimirFinal(mensaje, max);
}

void imprimirMaximaMes(float temperaturas[DIAS][MESES]){
    calcularMaxMes("enero: ", temperaturas, 0);
    calcularMaxMes("febrero: ", temperaturas, 1);
    calcularMaxMes("marzo: ", temperaturas, 2);
    calcularMaxMes("abril: ", temperaturas, 3);
    calcularMaxMes("mayo: ", temperaturas, 4);
    calcularMaxMes("junio: ", temperaturas, 5);
    calcularMaxMes("julio: ", temperaturas, 6);
    calcularMaxMes("agosto: ", temperaturas, 7);
    calcularMaxMes("septiembre: ", temperaturas, 8);
    calcularMaxMes("octubre: ", temperaturas, 9);
    calcularMaxMes("noviembre: ", temperaturas, 10);
    calcularMaxMes("diciembre: ", temperaturas, 11);
}

int main () {
    float temperaturas[DIAS][MESES];
    imprimirMaximaMes(temperaturas);
    imprimirMaximaAnio(temperaturas);
    system("pause");
    return 0;
}