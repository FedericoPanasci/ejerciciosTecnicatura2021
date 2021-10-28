#include <iostream>

using namespace std;


    char esPositivo (int num1, char &positivo) {
        
        if (num1 >= 0)
        {
            positivo = 'P';
        }
        else
        {
            positivo = 'F';
        }

    return positivo;
    }
int main () {

    int num1;
    

    cout << "ingrese un numero: ";
    cin >> num1;

    char positivo = esPositivo(num1, positivo);
    
    cout << "su numero es " << positivo << endl;
    
    system("pause");
    return 0;
}