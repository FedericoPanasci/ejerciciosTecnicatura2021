#include <iostream>
#include <string.h>
using namespace std;

int main () {
    int legajo = 0, cantAtendida = 0, minlegajo = 0, salario = 0, vacaciones = 0, medico = 0, tramite;
    char primer, nombre;

    
    printf("legajo: ");
    scanf("%d", &legajo);
    while (legajo != 0)
    {
        printf("nombre: ");
        scanf("%s", &nombre);
        if (cantAtendida == 0)
        {
           primer = nombre;
           minlegajo = legajo;
        }
        cantAtendida++;
        if (legajo < minlegajo)
        {
            minlegajo = legajo;
        }
        
        printf("tipo de tramite (1-salario, 2-vacaciones o 3-medico): ");
        scanf("%d", &tramite);
                
        switch (tramite)
        {
        case 1:
            salario++;
            break;
        case 2:
            vacaciones++;
            break;
        case 3:
            medico++;
            break;
        default:
            break;
        }

    printf("legajo: ");
    scanf("%d", &legajo);
    }
    printf("legajo menor: %d", minlegajo);

    system("pause");
    return 0;
}