#include <iostream>

using namespace std;
#define MESES 12
#define DIAS 30

struct temperaturas
{
    int dia;
    int mes;
    float temperatura;
};

string MensajeMes(int i){
string mensaje;
switch (i)
    {
    case 1:
        mensaje = "Enero";
        break;
    case 2:
        mensaje = "Febrero";
        break;
    case 3:
        mensaje = "Marzo";
        break;
    case 4:
        mensaje = "Abril";
        break;
    case 5:
        mensaje = "Mayo";
        break;
    case 6:
        mensaje = "Junio";
        break;
    case 7:
        mensaje = "Julio";
        break;
    case 8:
        mensaje = "Agosto";
        break;
    case 9:
        mensaje = "Septiembre";
        break;
    case 10:
        mensaje = "Octubre";
        break;
    case 11:
        mensaje = "Noviembre";
        break;
    case 12:
        mensaje = "Diciembre";
        break;
    default:
        break;
    }
    return mensaje;
}

void imprimirAnual(temperaturas anuales[MESES]){
int mes, dia, i = 0;
float temperatura = 0;
for (i = 0; i < MESES; i++)
{
    if (temperatura < anuales[i].temperatura)
    {
        temperatura = anuales[i].temperatura;
        mes = anuales[i].mes;
        dia = anuales[i].dia;
    }
}
string mensaje = MensajeMes(i);   
cout << "La temperatura mas alta fue: " << temperatura << " el dia " << dia << " del mes " << mensaje << endl;
}

void imprimirTempYMes(float temp[MESES][DIAS], temperaturas anuales[MESES]){
float mayor[MESES] = {-100};
for (int i = 0; i < MESES; i++)
{
    for (int j = 0; j < DIAS; j++)
    {
        if (temp[i][j] > mayor[i])
        {
            mayor[i] = temp[i][j];
            anuales[i].mes = i+1;
            anuales[i].dia = j+1;
            anuales[i].temperatura = temp[i][j];
        }
    }
    string mensaje = MensajeMes(i);
    cout << mensaje << ": " << mayor << endl;
}
imprimirAnual(anuales);
}

int main () {
    float tempe[MESES][DIAS];
    temperaturas anuales[MESES];
    imprimirTempYMes(tempe, anuales);

    system("pause");
    return 0;
}