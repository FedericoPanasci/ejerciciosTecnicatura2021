#include <iostream>
using namespace std;
int main () {
    float valorMulta = 0, cantidadGraves = 0, totalL = 0, totalM = 0, totalG = 0; 
    int tipo = 0;
    string motivo = "";
    char gravedad;

        for (int i = 0; i < 20; i++) 
        {
        cout << "tipo de infraccion (1, 2, 3 o 4)" << endl;
        cin >> tipo;

        cout << "motivo de la infraccion" << endl;
        cin >> motivo;

        cout << "valor de la multa" << endl;
        cin >> valorMulta;

        cout << "gravedad de la infraccion (L, G o M)" << endl;
        cin >> gravedad; 
        
    switch (gravedad) {
    
    case 'l':
        totalL += valorMulta;
        break;
    case 'm':
        totalM += valorMulta;
        break;
    case 'g':
        totalG += valorMulta;
        if (tipo == 3 || tipo == 4) {
            cantidadGraves++;
        }
    }



}
cout << "total de multas de infracciones 'L': " << totalL << endl;
cout << "total de multas de infracciones 'M': " << totalM << endl;
cout << "total de multas de infracciones 'G': " << totalG << endl;
if (cantidadGraves > 3)
{
    cout << "clausurar fabrica" << endl;

}
}