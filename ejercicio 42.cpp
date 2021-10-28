#include <iostream>

using namespace std;

/*Ej. MI-42: De un censo realizado en una población se conocen los siguientes datos:
- Día de nacimiento (2 dig.)
- Mes (2 dig.)
- Año (4 dig.)
- Sexo ('M'=masc. 'F'=fem.)
Con estos datos de cada habitante se forma un lote finalizado con un día cero. Desarrollar el programa que determine e
imprima:
1) Cuántos nacimientos hubo en el mes de octubre de todos los años.
2) Cuántos nacimientos hubo antes del 9 de julio de 1990.
3) Cuántos nacimientos de mujeres hubo en la primavera del 1982.
4) Sexo de la persona más vieja (solo existe una). */

void ingresoFecha(int &mes, int &anio){
    cout << "ingrese el mes de nacimiento: ";
    cin >> mes;
    cout << "ingrese el anio de nacimiento: ";
    cin >> anio;
    return;
}
void ingresoGenero(char &genero) {
    cout << "ingrese el genero de la persona: ";
    cin >> genero;
    return;
}
int fechaDeCalculo(int dia, int mes, int anio) {
        return anio * 10000 + mes * 100 + dia;
}
void nacimientoOctubre(int mes, int &nacimientos) {
        if (mes == 10)
        {
            nacimientos++;
            return;
        }
}
void nacidosAntesJulio(int fecha, int &nacidos){
        if (fecha < 19900609)
        {
            nacidos++;
            return;
        }
}
void nacimientosPrimavera(int fecha, int &nacimientos){
        if (fecha >= 19820921 && fecha <= 19821222)
        {
            nacimientos++;
            return;            
        }
}
void personaMasLongeba(int fecha, char genero, int &fechaMAsLongeba, char &generoMasLongebo){
    if (fecha < fechaMAsLongeba) {
        fechaMAsLongeba = fecha;
        generoMasLongebo = genero;
        return;
    }
}
int main () {
    int dia = 0, mes = 0, anio = 0, nacidosOctubre = 0, nacidosAntesB = 0, nacimientosEnPrimavera = 0, fechaMasLongeba = 0, diaMasLongeba = 99, mesMasLongeba = 99, anioMasLongeba = 9999;
    char genero = '*', generoPersonaMasGrande = ' ';
    
    cout << "ingrese el dia de nacimiento: ";
    cin >> dia;
    while (dia != 0)
    {
        ingresoFecha(mes, anio);
        ingresoGenero(genero);
        int fecha = 0;
        fecha = fechaDeCalculo(dia, mes, anio); 
        nacimientoOctubre(mes, nacidosOctubre);
        nacidosAntesJulio(fecha, nacidosAntesB);
        personaMasLongeba(fecha, genero, fechaMasLongeba, generoPersonaMasGrande);
        if (genero == 'g' || genero == 'G')
        {
            nacimientosPrimavera(fecha, nacimientosEnPrimavera);
        }
        cout << "ingrese otro dia de nacimiento: ";
        cin >> dia;
    }
    cout << "en el mes de octubre hubo " << nacidosOctubre << " nacimientos." << endl;
    cout << "antes del 9 de julio de 1982 hubo " << nacidosAntesB << " nacimientos" << endl;
    cout << "en la primavera de 1982 hubo " << nacimientosEnPrimavera << " nacimientos" << endl;
    cout << "el genero de la persona mas longeba es " << generoPersonaMasGrande << endl;

    system("pause");
    return 0;
}