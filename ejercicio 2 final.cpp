#include <iostream>

using namespace std;

/* 1 - Moto - $30.00
● 2 - Auto - $50.00
● 3 - Camioneta - $75.00 */

struct ST_COCHERA
{
    int id; //definidas del 1 al 200
    int vehiculo;
    int horaIngreso;
    int horaEgreso;
    bool ocupado;
};

struct ST_TICKET
{
    int id;
    int horaIngreso;
    int horaEgreso;
    int horaTotal;
    int automovil;
    int valorTotal;
};


int registrarIngreso(ST_COCHERA predio[10][20])
{
    int i = 0, j = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (predio[i][j].ocupado == false)
            {
                cout << "ingrese tipo de vehiculo: ";
                cin >> predio[i][j].vehiculo;
                cout << "hora de ingreso: HHMM ";
                cin >> predio[i][j].horaIngreso;
                predio[i][j].ocupado = true;
                return predio[i][j].id;
            }
        }
    }
}

ST_TICKET registrarEgreso(ST_COCHERA predio[10][20], int idCochera){

}


int main()
{
    ST_COCHERA vehiculo[10][20];
    //ingreso y egreso;
    int accion;
    cout << "Que desea realizar? 1 ingreso/2 egreso ";
    cin >> accion;
    int pos = 0;
    if (accion == 1)
    {
        pos = registrarIngreso(vehiculo);
    }
    else
    {
        registrarEgreso(vehiculo, pos);
    }

    system("pause");
    return 0;
}