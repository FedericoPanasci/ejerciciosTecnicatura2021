#include <iostream>

using namespace std;

struct ST_SERIE
{
    int Id_Serie;
    int NumeroDeTemporada;
    long int CantidadDeDescargas;
    string TituloDelEpisodio;
    int NumeroDeEpisodio;
    int FechaDeUltimaDescarga;
};

void cantidadTotalEpisodios(ST_SERIE serie[], int i)
{
    ST_SERIE aux;
    int nombreSerie;
    int cantidadEpisodios = 0;

    while (i == serie[i].Id_Serie)
    {
        /* code */
    }
}

void imprimir(ST_SERIE serie[], int cantSeries)
{

    cout << "       LISTADO DE DESCARGA DE SERIES          " << endl;
    for (int i = 0; i < cantSeries; i++)
    {
        cout << "serie: " << serie[i].Id_Serie << endl;
        cout << "temporada: " << serie[i].NumeroDeTemporada << endl;
        cout << "numero del episodio    titulo del episodio    cantidad de descargas     fecha de la ultima descarga" << endl;
        cout << serie[i].NumeroDeEpisodio << "                " << serie[i].TituloDelEpisodio << "   " << serie[i].CantidadDeDescargas << "            " << serie[i].FechaDeUltimaDescarga << endl;
        cout "---------------------------------------------------------" << endl;
        cantidadTotalEpisodios(serie, i);
        cantidadTotalDescargas();
        cantidadTotalEpisodiosSerie();
        totalDescargasDeLaSerie();
    }
    totalGeneralSeries;
}
/*formato ALE
int i = 0;
int serie;
int temporada;
int totalEpisodiosTemporada = 0;
int totalDescargasTemporada = 0;

int totalEpisodiosSerie = 0;
int totalDescargasSerie = 0;

cout << "listado de descargas de series" << endl;

while (i < cantidad){
    serie = serie[i].id_Serie;
    cout << "serie: " << serie << endl;
    totalDescargasSerie = 0;
    totalEpisodiosSerie = 0;
    while (i < cantidad && serie == serie[i].id_serie)
    {
        temporada = serie[i].temporada;
        cout << "temporada: " << temporada << endl;
        cout "n de episodio" << "   " << "titulo del episodio " << "   " << "cant de descargas " << "  " << "fecha " << endl;

        while (i < cantidad && serie == serie[i].id_serie && temporada == serie[i].id_serie) {
            totalEpisodiosTemporada++;
            totalDescargasTemporada = totalDescargasTemporada + serie[i].cantDescargas;
            cout << serie[i].id_serie << "  " << serie[i].tituloDeEpisodio << "   " << serie[i].cantDeDescargas << "   " << serie[i].fechaDeDescarga;
            i++;
        }
        cout "----------------" << endl;
        cout << "cant total de episodios de la temporada: " << totalEpisodiosTemporada << endl;
        cout << "cant total de descargas de la temporada: " << totalDescargasTemporada << endl;
        
    }
        totalEpisodiosSerie = totaldescargasSerie + totalDescargasTemporada;
        totalDescargasSerie = totalEpisodiosSerie + totalDescargasSerie;
}
cout << "----------------------------"  << endl;
cout << "el total de episodios de la serie: " << totalEpisodiosSerie << endl;
cout << "cantidad total de descarga de la serie: " << totalDescargaSerie << endl; 
totalGeneralSerie++;

}*/

int main()
{
    ST_SERIE serie[100];
    imprimir(serie, 10);

    system("pause");
    return 0;
}