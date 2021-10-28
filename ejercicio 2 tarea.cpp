#include <iostream>

using namespace std;

float pasaje (int celcius) {

    float fahern = ((1.8 * celcius) + 32);
    return fahern;


}

int main () {
    float celc = 0;

    cout << "ingrese una temperatura en celcius: ";
    cin >> celc; 

    float faren = pasaje(celc);

    cout << "la temperatura en faherenheit es: " << faren << endl;

    system ("pause");
    return 0;
}