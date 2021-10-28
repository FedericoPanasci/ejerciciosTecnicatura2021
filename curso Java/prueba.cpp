#include <iostream>

using namespace std;

int main()
{
    int miArray[10] = {0};
    int cant = 0;
    int i = 0;
    while (cant < 10)
    {
        if (cant % 5 == 0)
        {
            miArray[i] = cant;
            cout << miArray[i] << endl;
        }
        else
        {
            cant++;
        }
        
        cant++;
        i++;
        
    }
    system("pause");
    return 0;
}
