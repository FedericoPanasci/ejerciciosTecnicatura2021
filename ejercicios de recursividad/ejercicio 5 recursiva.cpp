#include <iostream>

using namespace std;
/* Ejercicio 5 - Sistema Octal
Desarrolle una función recursiva que permita convertir un número decimal en su equivalente en sistema octal.
Descripción
El sistema de numeración octal es un sistema de numeración en base 8. El sistema octal usa 8 dígitos (0, 1, 2, 3, 4, 5, 6, 7) y cada dígito
tiene el mismo valor que en el sistema de numeración decimal.
Como el sistema de numeración octal usa la notación posicional entonces para el número octal 3452 tenemos que: 38`3 + 482 + 581 +
280 = 3512 + 464 + 40 + 2 = 1536 + 256 + 40 + 2 = 1834 en decimal
Conversión de decimal a octal
Para poder convertir un número en base decimal a base octal se divide dicho número entre 8, dejando el residuo y dividiendo el
cociente sucesivamente entre 8 hasta obtener cociente 0, luego los restos de las divisiones leídos en orden inverso indican el número
en octal.
Ver ejemplo en el siguiente link: Wikipedia - Sistema Octal
*/

#include <iostream>

using namespace std;

int octal(int num) {
    if (num > 7)
    {
        octal (num/8);
    }
    cout << num%8;
    return 0;
}
int main () {
    int num = 0;
    cout << "ingrese un numero: ";
    cin >> num;

    octal(num);
    cout << endl;
    system("pause");
    return 0;
}