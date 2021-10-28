#include <iostream>

using namespace std;

struct ST_PIEZA
{
    int codigo;
    string nombre;
    int categoria;
    string autor;
};

struct ST_CATEGORIA
{
    int codigo;
    string nombre;
};

string BuscarNombreCategoria(int codCategoria, ST_CATEGORIA categorias[], int cantCate){

}

void ordenarPorNombreCategoria(ST_PIEZA piezas[], int cantPiezas, ST_CATEGORIA categorias[], int cantCategorias){
    int i = 0;
    bool ordenado = false;
    ST_PIEZA aux;
    while (i < cantPiezas < 1 && !ordenado)
    {   
        ordenado = true;
        for (int j = 0; i < cantPiezas - i - 1; i++)
        {
            string nombre = BuscarNombreCategoria(piezas[j].categoria, categorias, cantCategorias);
            string nombreSte = BuscarNombreCategoria(piezas[j+1])
            if (buscarNombreCategoria(piezas[j].categoria) < buscarNombreCategoria(piezas[j+1].categoria))
            {
                aux = piezas[j];
                piezas[j] = piezas[j + 1];
                piezas[j + 1] = aux;
                ordenado = false;
            }
            
        }
        i++;
    }
    

}

/*cortedecontrol
void imprimir(ST_piezas piezas[], int cant, st_cate categorias[], int cantCate){
    int i = 0;
    while (i < cant){
        int key = piezas[i].categoria;
        cout << "categoria: " << buscarNombreCategoria(key, categorias, cantCate) << endl;
        while(i < cant && key == piezas[i].categoria){
            cout << piezas[i].nombre << "   " << piezas[i].autor << endl;
            i++;
        }
    }
}
corte de control x dos criterios:
void imprimir(ST_piezas piezas[], int cant, st_cate categorias[], int cantCate){
    int i = 0;
    while (i < cant){
        int key = piezas[i].categoria;
        cout << "categoria: " << buscarNombreCategoria(key, categorias, cantCate) << endl;
        int cantAutores = 0;
        while(i < cant && key == piezas[i].categoria){
            cantAutores++;
            string keyAutor = piezas[i].autor; 
            int cantObras = 0;
            while (i < cant && key == piezas[i].categoria && keyAutor == piezas[i].autor){
                cantObras++;
                i++;
            }
            cout << "autor: " << keyAutor << " - " << "cantidad de obras: " << cantObras;
            cantObras = 0;
        }
        cout << "cantidad de autores: " << cantAutores << endl;
    }
}
*/
void imprimirListadoXCategoria(ST_CATEGORIA categoria[], int cantCategorias, ST_PIEZA piezas[], int cantPiezas){
    ordenarPorNombreCategoria(piezas, cantPiezas);
}

int main () {


    system("pause");
    return 0;
}