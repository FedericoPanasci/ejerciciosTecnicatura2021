#include <iostream>

using namespace std;

/*Celular
Un prototipo de celular muy básico posee las siguientes 3 funcionalidades:
Puede enviar mensajes de texto de hasta 256 caracteres
Puede realizar llamadas telefónicas
Puede tomar fotos.
Este prototipo posee una batería cuya duración, es un valor entero entre 1 y 100, configurable al momento de iniciar el celular.
El prototipo sólo consume su batería cada vez que el usuario realiza una acción, como por ejemplo enviar un mensaje, tomar una foto o
realizar una llamada.
Los consumos de batería son los siguientes:
Por cada mensaje enviado, la batería se consume en un 1% sobre el total actual.
Por cada llamada realizada, la batería se consume en una cantidad fija, determinada por la siguiente fórmula: cantidad de
minutos * 0,08
Por cada foto tomada, la batería consume 6% sobre el total actual.
Realizar un programa que permita a un usuario simular el comportamiento del prototipo mencionado, es decir, que le permita simular
el envío de mensajes, llamadas y tomar fotos de forma tal que la batería se vaya consumiendo y determinar para un ciclo de batería:
a. Cuál fue la llamada de mayor duración.
b. El porcentaje de mensajes que superan los 10 caracteres por sobre el total de mensajes enviados.
Nota: se recomienda el uso de funciones para simular el comportamiento del prototipo, por ejemplo enviarMensaje, realizarLlamada,
tomarFoto
*/

void enviarMensaje(int &bate)
{
    float consumo = 0.01;
    bate = bate - (consumo * bate);
    return;
}
void realizarLlamada(int &bate, int minutos)
{
    float consumo = 0.08;
    bate = bate - (minutos * consumo);
    return;
}
void tomarFoto(int &bate)
{
    const int foto = 0.06;
    bate = bate - (bate * foto);
    return;
}
int resultadoMensaje(int cantidadTotal, int cantidadMayores)
{
    int resultado = cantidadMayores * 100 / cantidadTotal;
    return resultado;
}
int main()
{

    int bateria = 0, minutos = 0, fotoTomada = 0, accion = 0, cantMensaje = 0, mensajesMas10 = 0, cantLlamada = 0, llamadaMayor = 0, numDeLlamada = 0;
    int mensajeEnviado = 0;

    cout << "indique la cantidad de bateria con la que inicia la simulacion: ";
    cin >> bateria;

    cout << "indique que accion quiere simular siendo: 1 - enviar un mensaje, 2 - realizar una llamada, 3 - tomar una foto, 4 para terminar la simulacion: ";
    cin >> accion;

    while (accion <= 3)
    {
        switch (accion)
        {
        case 1:
            enviarMensaje(bateria);
            cout << "indique la cantidad de caracteres que tiene su mensaje: ";
            cin >> mensajeEnviado;
            cantMensaje++;
            if (mensajeEnviado > 10)
            {
                mensajesMas10++;
            }
            break;
        case 2:
            cout << "cuantos minutos duro la llamada? ";
            cin >> minutos;
            realizarLlamada(bateria, minutos);
            cantLlamada++;
            if (minutos > llamadaMayor)
            {
                llamadaMayor = minutos;
                numDeLlamada = cantLlamada;
            }
            break;
        case 3:
            tomarFoto(bateria);
            break;
        }
            if (bateria > 0)
            {

                cout << "desea realizar otra accion? 1 - enviar un mensaje, 2 - realizar una llamada, 3 - tomar una foto, 4 para terminar la simulacion: ";
                cin >> accion;
            }
            else
            {
                accion = 4;
            }
    }
    cout << "la llamada de mayor duracion fue la llamada " << numDeLlamada << " y duro: " << llamadaMayor << endl;
    cout << "la cantidad de mensajes con mas de 10 caracteres fueron el " << resultadoMensaje(cantMensaje, mensajesMas10) << "% de los mensajes enviados" << endl;
    cout << "quedan " << bateria << "% de bateria." << endl;

    system("pause");
    return 0;
}