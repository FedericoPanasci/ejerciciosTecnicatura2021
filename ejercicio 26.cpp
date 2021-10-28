#include <iostream>

using namespace std;

int main () {
    string identificacion = "", identificacionMasPesado = "";
    int peso = 0, puerto = 0, puerto1 = 0, puerto2 = 0, puerto3 = 0, pesoTotal = 0, pesoMayor = 0;


    for (int i = 0; i < 5; i++)
    {
        cout << "identificacion del contenedor: ";
        cin >> identificacion;
        cout << "peso del contedor en kg: ";
        cin >> peso;
        cout << "puerto de arribo (1, 2 o 3): ";
        cin >> puerto;

        pesoTotal = pesoTotal + peso;

        if (peso > pesoMayor)
        {
            pesoMayor = peso;
            identificacionMasPesado = identificacion;
        }
        
        switch (puerto)
        {
        case 1:
            puerto1 = puerto1 + 1;
            break;
        case 2:
            puerto2 = puerto2 + 1;
            break;
        case 3:
            puerto3 = puerto3 + 1;
            break;
        }
        
    }
    
    cout << "el peso total del buque es " << pesoTotal << ", el contenedor de mayor peso es " << identificacionMasPesado << "." << endl;
    cout << "Y la cantidad de contenedores que van a los puertos son: puerto 1: " << puerto1 << ", puerto 2: " << puerto2 << ", y al puerto 3: " << puerto3 << "." << endl;




    system ("pause");
    return 0;
}