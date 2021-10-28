#include <iostream>

using namespace std;

/*Ejercicio 1 - Electrodomésticos
El centro de atención al cliente de una conocida marca de electrodomésticos, recibe diariamente los llamados e ingresa por cada
llamado los siguientes datos ya validados:
Código de comercio donde adquirió el producto (entero entre 1 y 20)
Código del producto por el cual llama (entero entre 1 y 300)
Tipo de llamado (‘C’ => Consulta, ‘R’ => Reclamo)
Duración de la llamada en minutos (mayor que 0 siempre)
Al finalizar la llamada, se registra también la calificación dada por el cliente a la atención brindada. Esta calificación es un número entre
1 y 3, siendo:
1 muy mala
2 normal
3 excelente
El proceso finaliza cuando se ingresa un código de comercio menor a 1 o mayor a 20.
Se pide procesar toda la información correspondiente a las llamadas e indicar:
a. Porcentaje de llamadas por consulta sobre el total de llamadas.
b. Porcentaje de llamadas por reclamos sobre el total de llamadas.
c. Código del producto correspondiente a la llamada más larga para consulta.
d. Promedio de llamadas calificadas como “excelente” sobre el total de llamadas.
e. Promedio de llamadas calificadas como “muy mala” sobre el total de llamadas.
*/

void ingreso()
{

    return;
}

void datosExtra(int &codProducto, char &tipoDeLlamado, int &duracionLlamada, float &calificacionDeAtencion)
{
    cout << "ingrese el codigo del producto por el que esta llamando (sea entre 1 y 300): ";
    cin >> codProducto;
    cout << "ingrese el tipo del llamado siendo 'C' para consulta y 'R' para reclamo: ";
    cin >> tipoDeLlamado;
    cout << "ingrese el tiempo total en minutos de cuanto duro la llamada: ";
    cin >> duracionLlamada;
    cout << "calificacion brindada por el usuario a la atencion del servicio al cliente siendo: 1 muy mala, 2 normal o 3 excelente: ";
    cin >> calificacionDeAtencion;
}

void contadorLlamadoYConsulta(char tipoDeLlamado, int &cantidadConsultas, int &cantidadReclamos)
{
    if (tipoDeLlamado == 'C' || tipoDeLlamado == 'c')
    {
        cantidadConsultas++;
    }
    else
    {
        cantidadReclamos++;
    }
}

void segunDuracionLlamada(int duracionLlamada, int &llamadaMasLarga, int &codProductoLlamadaMasLarga, int codProducto)
{
    if (duracionLlamada > llamadaMasLarga)
    {
        llamadaMasLarga = duracionLlamada;
        codProductoLlamadaMasLarga = codProducto;
    }
}

void segunCalificacion(float calificacionDeAtencion, float &llamadasExcelente, float &llamadasMuyMala)
{
    if (calificacionDeAtencion == 1)
    {
        llamadasMuyMala = llamadasMuyMala + 1;
    }
    if (calificacionDeAtencion == 3)
    {
        llamadasExcelente = llamadasExcelente + 1;
    }
}

void impresionFinal(int cantidadConsultas, int cantidadLlamadas, int cantidadReclamos, int codProductoLlamadaMasLarga, float promedioExcelente, float promedioMuyMala)
{
    cout << "el porcentaje de llamadas por consultas es: " << cantidadConsultas * 100 / cantidadLlamadas << "%. " << endl;
    cout << "el porcentaje de llamadas por reclamos es: " << cantidadReclamos * 100 / cantidadLlamadas << "%. " << endl;
    cout << "Codigo del producto correspondiente a la llamada mas larga para consulta: " << codProductoLlamadaMasLarga << ". " << endl;
    cout << "Promedio de llamadas calificadas como excelente sobre el total de llamadas: " << promedioExcelente << ". " << endl;
    cout << "Promedio de llamadas calificadas como muy mala sobre el total de llamadas: " << promedioMuyMala << ". " << endl;
}

int main()
{
    int codComercio = 0, cantidadLlamadas = 0, cantidadConsultas = 0, cantidadReclamos = 0, codProducto = 0;
    int duracionLlamada = 0, llamadaMasLarga = 0, codProductoLlamadaMasLarga = 0;
    float llamadasExcelente = 0, llamadasMuyMala = 0, calificacionDeAtencion = 0, promedioExcelente = 0, promedioMuyMala = 0;
    char tipoDeLlamado = '*';

    cout << "ingrese el codigo de comercio donde compro el producto siendo entre 1 y 20 (si es menor o mayor a estos valores el proceso finaliza): ";
    cin >> codComercio;

    while (codComercio < 21 && codComercio > 0)
    {
        cantidadLlamadas++;
        datosExtra(codProducto, tipoDeLlamado, duracionLlamada, calificacionDeAtencion);
        contadorLlamadoYConsulta(tipoDeLlamado, cantidadConsultas, cantidadReclamos);
        segunDuracionLlamada(duracionLlamada, llamadaMasLarga, codProductoLlamadaMasLarga, codProducto);
        segunCalificacion(calificacionDeAtencion, llamadasExcelente, llamadasMuyMala);

        cout << "ingrese otro codigo de comercio donde compro el producto siendo entre 1 y 20 (si es menor o mayor a estos valores el proceso finaliza: ";
        cin >> codComercio;
    }
    promedioExcelente = llamadasExcelente / cantidadLlamadas;
    promedioMuyMala = llamadasMuyMala / cantidadLlamadas;
    impresionFinal(cantidadConsultas, cantidadLlamadas, cantidadReclamos, codProductoLlamadaMasLarga, promedioExcelente, promedioMuyMala);
    ingreso();

    system("pause");
    return 0;
}