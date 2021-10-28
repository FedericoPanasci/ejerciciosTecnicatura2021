/*#include <iostream>

using namespace std;

int main () {
    string nombre = "";
    string nombreMayor = "";
    string nombreMen = "";
    int fecha8dig = 0, fechaMen = 0, fechaMinima = 0, fechaMay = 0, posicionNom = 0, contador = 0;

    cout << "ingrese un nombre: ";
    cin >> nombre;
    
    while (nombre != "fin")
    {
        cout << "ingrese la fecha de nacimiento de 8 digitos (AAAAMMDD): ";
        cin >> fecha8dig;

        if (fecha8dig > fechaMay)
        {
            fechaMay = fecha8dig;
            nombreMen = nombre;
        }
        if (fecha8dig < fechaMen || fechaMen == 0)
        {
            fechaMen = fecha8dig;
            nombreMayor = nombre;
        }
                
        
        cout << "ingrese un nombre: ";
        cin >> nombre; 
    }
    
    cout << "el mayor es " << nombreMayor << " y el menor es " << nombreMen << endl;
    cout << "fecha mayor " << fechaMen << " y fecha menor " << fechaMay << endl;
    
    system ("pause");
    return 0;
}
*/

#include <iostream>

using namespace std;

int main () {

    /*float num1 = 0, num2 = 0, num3 = 0;
    float resultado = 0;
    float promedio = 0;
    float cantNum = 0;
    cout << "ingrese numero ";
    cin >> num1;
    resultado = resultado + num1;
    cantNum++;
    cout << "ingrese numero ";
    cin >> num2;
    resultado = resultado + num2;
    cantNum++;
    cout << "ingrese numero "; 
    cin >> num3; 
    resultado = num3 + resultado;
    cantNum++;
    promedio = resultado / cantNum;
    cout << promedio << endl;*/

    int anio = 0, dia = 0, mes = 0, X = 0;

    cout << "fecha";
    cin >> X;

    anio = (X / 10000);

    mes = (X / 100) - anio * 100;

    dia = X % 100;
    
    cout << dia << mes << anio;

    system("pause");
    return 0;
}