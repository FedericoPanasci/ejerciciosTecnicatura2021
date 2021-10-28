#include <iostream>
using namespace std;
//usando el  espacio de nombres  estándar ;

#define CANTIDAD 100

struct ST_EPISODIO
{
    int idSerie;
    int idTemporada;
    long int cantidadDescargas;
    string tituloEpisodio;
    int idEpisodio;
    int fechaUltimaDescarga;
};

string obtenerFechaFormateada(int fecha)
{
    int anio = fecha / 10000;
    int mes = (fecha % 10000) / 100;
    int dia = fecha % 100;

    return obtenerFechaFormateada(dia) + " / " + obtenerFechaFormateada(mes) + " / " + obtenerFechaFormateada(anio);
}

void obtenerFechaFormatead(int fecha, string &fechaStr)
{
    int anio = fecha / 10000;
    int mes = (fecha % 10000) / 100;
    int dia = fecha % 100;

    fechaStr = to_string(dia) + " / " + to_string(mes) + " / " + to_string(anio);

    return;
}

void emitirListado(ST_EPISODIO episodios[], int cantidad)
{
    int i = 0;
    int serie;
    int temporada;

    int totalEpisodiosSerie = 0;
    int totalDescargasSerie = 0;

    int totalEpisodiosTemporada = 0;
    int totalDescargasTemporada = 0;

    int totalGeneralSerie = 0;

    cout << " Listado de descargas de series " << endl;

    while (i < cantidad)
    {
        totalDescargasSerie = 0;
        totalEpisodiosSerie = 0;
        serie = episodios[i].idSerie;
        cout << " Serie: " << serie << endl;

        while (i < cantidad && serie == episodios[i].idSerie)
        {
            totalDescargasTemporada = 0;
            totalEpisodiosTemporada = 0;
            temporada = episodios[i].idTemporada;
            cout << " Temporada: " << temporada << endl;
            cout << " N. de Episodio "
                 << "  "
                 << " Título del Episodio "
                 << "  "
                 << " Cant. descargas "
                 << "  "
                 << " Fecha " << endl;

            while (i < cantidad && serie == episodios[i].idSerie &&
                   temporada == episodios[i].idTemporada)
            {
                totalEpisodiosTemporada++;
                totalDescargasTemporada = totalDescargasTemporada + episodios[i].cantidadDescargas;
                cout << episodios[i].idEpisodio << "  " << episodios[i].tituloEpisodio << "  " << episodios[i].cantidadDescargas << "  " << obtenerFechaFormateada(episodios[i].fechaUltimaDescarga) << endl;
                i++;
            }
            cout << " ....................................... " << endl;
            cout << " Cant. Total de Episodios de la temporada: " << totalEpisodiosTemporada << endl;
            cout << " Cant. Total de descargas de la temporada: " << totalDescargasTemporada << endl;

            totalDescargasSerie = totalDescargasSerie + totalDescargasTemporada;
            totalEpisodiosSerie = totalEpisodiosSerie + totalEpisodiosTemporada;
        }

        cout << " ....................................... " << endl;
        cout << " Cant. Total de Episodios de la serie: " << totalEpisodiosSerie << endl;
        cout << " Cant. Total de descargas de la serie: " << totalDescargasSerie << endl;

        totalGeneralSerie++;
    }
    cout << " ....................................... " << endl;
    cout << " Cant. Total de Series: " << totalGeneralSerie << endl;
}

int main()
{

    return 0;
}