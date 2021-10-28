#include <iostream>
using namespace std;
int main () 
{
    int dni = 0;
    float sueldoNeto = 0;
    int anios = 0;
    int cantHijos = 0;
    const int porAnt = 500;
    const int porHijo = 500;
    float salarioTotal = 0;  
    string dia = "";
    cout << "ingrese dni del empleado: ";
    cin >> dni;

    while (dni > 0)
    {
        cout << "ingrese su cantidad de años trabajados: ";
        cin >> anios;

        cout << "ingrese la cantidad de hijos que tiene: ";
        cin >> cantHijos;

        cout << "ingrese su sueldo neto: ";
        cin >> sueldoNeto;

        salarioTotal = (porAnt * anios) + (cantHijos * porHijo) + sueldoNeto;
        

        int ultimoDni = dni % 10;
        
        if (ultimoDni % 2 == 0)
        {
            if (ultimoDni < 5)
            {
            dia = "cobra el dia lunes.";
            }
            else
            {
            dia = "cobra el dia miercoles";
            }
        }
        else 
        {
            if (ultimoDni > 5)
        {
            dia = "cobra el dia martes";
            }
            else
            {
            dia = "cobra el dia jueves";
            }        
        }
        cout << "empleado con dni " << dni << " su salario es: " << salarioTotal << " y " << dia << endl;
        cout << "ingrese su dni: ";
        cin >> dni;
    }
    return 0;
}
