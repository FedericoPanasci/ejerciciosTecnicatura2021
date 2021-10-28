#include <iostream>

using namespace std;

#include <math.h>

struct ST_GEOMETRIA {
    int puntoX;
    int puntoY;

};

int calcularDistancia(ST_GEOMETRIA punto1, ST_GEOMETRIA punto2){
    int distancia = 0;
    int potencia1 = 0, potencia2 = 0;
    potencia1 = pow((punto2.puntoX - punto1.puntoX), 2);
    potencia2 = pow((punto2.puntoY - punto1.puntoY), 2);
    distancia = potencia1 + potencia2;
    distancia = sqrt(distancia);

    return distancia;
}

int main () {
    ST_GEOMETRIA punto1;
    ST_GEOMETRIA punto2;

    cout << "ingrese valor X para su primer punto: ";
    cin >> punto1.puntoX;

    cout << "ingrese valor Y para su primer punto: ";
    cin >> punto1.puntoY;

    cout << "ingrese valor X para su segundo punto: ";
    cin >> punto2.puntoX;

    cout << "ingrese valor Y para su segundo punto: ";
    cin >> punto2.puntoY;

    int distancia = 0;

 //punto A
    distancia = calcularDistancia(punto1, punto2);
    cout << endl;
    cout << "la distancia entre los 2 puntos es: " << distancia;
//punto B
    float M = 0;
    M = (punto2.puntoY - punto1.puntoY) / (punto2.puntoX - punto1.puntoX);
    float B = 0;
    B = punto1.puntoY - (M * punto1.puntoX);

    cout << "la ecuacion de la recta es: Y = " << M << "x + " << B << endl;


//punto C
    int Y = 0;
    for (int i = 0; i < 5; i++)
    {
        Y = M*i + B;
        cout << "para el valor de X: " << i << " el valor de Y es: " << Y << endl;
    }
    
    system("pause");
    return 0;
}