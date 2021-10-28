#include <iostream>
using namespace std;

/*
Ej. MI-33: Desarrollar una función que calcule el máximo común divisor de dos números enteros A, B con el siguiente
algoritmo:
    1) Dividir A por B, y calcular el resto (0 < R < B)
    2) Si R = 0, el MCD es B, si no seguir en 3)
    3) Reemplazar A por B, B por R, y volver al paso 1)
*/

// Revisar este algoritmo porque parece que no esta bien!
int maximoComunDivisor(int numeroA, int numeroB)
{
    if (numeroA < numeroB)
    {
        return -1;
    }

    int resto = 0;
    while (resto < numeroB)
    {
        resto = numeroA % numeroB;
        if (resto == 0)
        {
            return numeroB;
        }
        numeroA = numeroB;
        numeroB = resto;
    }
    return numeroB;
}

int main()
{
    int nroA, nroB;
    int mcd;

    cout << "Ingrese A";
    cin >> nroA;

    cout << "Ingrese B";
    cin >> nroB;

    mcd = maximoComunDivisor(nroA, nroB);

    if (mcd > 0) {
        cout << "El maximo comun divisor entre " << nroA << " y " << nroB << " es: " << mcd << endl << endl;
    }
    mcd = maximoComunDivisor(nroB, nroA);


    cout << "El maximo comun divisor entre " << nroB << " y " << nroA << " es: " << mcd << endl << endl;

    system("pause");

    return 0;
}
