#include <iostream>

using namespace std;
/*Figuras geométricas
En el siguiente ejercicio vamos a tratar de dibujar algunas figuras geométricas como un triángulo rectángulo y un cuadrado. Para ello,
el usuario deberá ingresar qué desea dibujar “triangulo” o “cuadrado” y a continuación deberá ingresar las dimensiones, a saber:
En el caso del cuadrado, sólo deberá ingresar el largo del lado.
En el caso del triángulo, deberá ingresar el largo de la base.
Ejemplo:
Ingrese figura a dibujar: “cuadrado” Ingrese el largo del lado: 4
Salida:
****
****
****
****
Ejemplo: Ingrese figura a dibujar: “triangulo”
Ingrese la base: 5
Salida:
* 
**
***
****
*****
*/

void hacerCuadrado (int lado){
    string result = "";
    const char caracter = '*';
    int impre = 2;
    for (int i = 1; i <= lado; i++)
    {
        result = result + caracter; 
    }
    while (impre <= lado)
    {
        cout << result << endl;
        impre++;
    }    
    return;
}
void hacerTriangulo (int base) {
    string result = "";
    const char caracter = '*';
    int impre = 1;
    while (impre <= base)
    {
        result = result + caracter;
        cout << result << endl;
        impre++;
    }
    return;
}
int main () {

    int figura = 0;
    int lado = 0;
    int base = 0; 
    cout << "indique que figura desea siendo 1 (cuadrado) o 2 (triangulo): ";
    cin >> figura;

    if (figura == 1)
    {
        cout << "indique el largo del lado: ";
        cin >> lado;
        hacerCuadrado(lado);
    }
        if (figura == 2)
    {
        cout << "indique el largo de la base: ";
        cin >> base;
        hacerTriangulo(base);
    }    
    system ("pause");
    return 0;
}