#include <iostream>

using namespace std;

/* Ej. MI-36: Dada la fracción P/Q, para P y Q naturales informar la mayor cantidad de simplificaciones. Desarrolle y
utilice una función que reciba dos números naturales y retorne el menor factor común. Ej: 360/60 = 180/30 = 90/15 =
30/5 = 6/1 */

int maximoComunDivisor(int X, int Y){
    int R = 0;
    R = X / Y;

    while (R != 0)
    {
        X = Y;
        Y = R;
        R = X / Y;
    }
    return X;
}
int main () {
    int P = 0;
    int Q = 0;

    cout << "ingrese un valor P: ";
    cin >> P;
    cout << "ingrese un valor Q: ";
    cin >> Q;

    int resultado = maximoComunDivisor(P, Q);
    cout << resultado << endl;
    system ("pause");
    return 0;
}