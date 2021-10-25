#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

typedef struct
{
    int idSerie;
    int temporada;
    long cantDescargas;
    char tituloDeEpisodio[21];
    unsigned char episodio;
    int fecha;
} ST_SERIE;

FILE *abrirArchivo(char *nombre, char *modo)
{
    FILE *archivo = fopen(nombre, modo);
    if (archivo == NULL)
    {
        EXIT_FAILURE;
    }
    return archivo;
}

ST_SERIE leer(FILE *file)
{
    ST_SERIE episodio;
    char buffer[255];
    if (fgets(buffer, 255, file) == NULL)
    {
        return episodio;
    }

    episodio.idSerie = atoi(strtok(buffer, ","));
    episodio.temporada = atoi(strtok(NULL, ","));
    episodio.cantDescargas = atoi(strtok(NULL, ","));
    strcpy(episodio.tituloDeEpisodio, strtok(NULL, ","));
    episodio.episodio = atoi(strtok(NULL, ","));
    episodio.fecha = atoi(strtok(NULL, ","));

    return episodio;
}

int main()
{
    FILE *lectura = abrirArchivo("datos.txt", "r");
    ST_SERIE serie;

    /* lo hizo leo


    int cantidadEspisodiosTotal = 0;
    int cantidaddescargasTotal = 0;
    
    episodio = leer(episodio);
    while(!feof(episodios)){
        int idSerie = episodio.idserie;

        while(!feof(episodios) && episodios.idSerie == idserie){
            int nroTemporada = episodio.nroTemporada;
            
            while(!feof(epiosdios) && episodio.idSerie == idSerie && episodio.nroTemporada == nroTemporada){
                episodio = leer(episodios);
            }
        }
    }
    */

    printf("listado de descargas de series\n");

    int cantEpisodiosTotal = 0, cantidaDeDescargasTotal = 0;

    serie = leer(lectura);
    while (!feof(lectura))
    {
        int idSerie = serie.idSerie;

        while (!feof(lectura) && serie.idSerie == idSerie)
        {
            int nroTemporada = serie.temporada;

            while (!feof(lectura) && serie.idSerie == idSerie && serie.temporada == nroTemporada)
            {
                
                serie = leer(lectura);
            }
            
        }
        
    }
    

    system("pause");
    return 0;
}