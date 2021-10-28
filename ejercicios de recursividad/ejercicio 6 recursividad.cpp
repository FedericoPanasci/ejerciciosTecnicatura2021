
/*Ejercicio 6 - Factorial
El siguiente fragmento de código, no calcula de forma correcta el factorial de un número. Utilizando las herramientas aprendidas
(como debugger, prueba de escritorio, etc) analice el código y explique por qué. Proponga una solución que corrija el código.
#include <iostream>
using namespace std;
int factorial(int n){
if(n==0){
return 1;
}
return n * factorial(--n);
}
int main () {
cout << factorial(4) << endl;
return 0;
}
*/

#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
    /*lo que estaba pasando es que el numero con --n se descontaba pero no se hacia la cuenta correspondiente
    para poder hacer las cuentas correspondientes al llamar a una funcion
    se corrigio con poner la formula n-1, el numero se descuenta y a su vez nos realiza el calculo*/
}
int main()
{
    cout << factorial(4) << endl;
    system("pause");
    return 0;
}