#include <iostream>

using namespace std;

void cargaVector(int numeros[]/*al ser de referencia no necesita &*/, int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        cout << "ingrese un numero: ";
        cin >> numeros[i]; //se le cargan los datos a los espacios
        cout << endl;
    }
    
}
int main () {

    int dimension;

    cout << "ingrese dimension ";
    cin >> dimension; //se define la cantidad de espacio que tendra el vector
    cout << endl;
    
    int numeros[dimension]; //se le asignan al vector los espacios, si los quiero iniciar en 0 se inicia = {0}

    cargaVector(numeros, dimension);

    return 0;
}