int buscarBinaria(Producto vector[], int cant, int codigo)
{
    // Cuando arranco evalúo todo el vector de 0 a n - 1
    int inicio = 0;
    int fin = cant - 1;
    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;
        // Si el elemento es el del medio, devolvemos la posicion
        if (vector[mitad].codigo == codigo)
            return mitad;
        // Si el elemento es menor entonces solo puede estar en la primer mitad
        if (vector[mitad].codigo > codigo)
        {
            fin = mitad - 1; //Cambio el limite superior
        }
        else
        {
            inicio = mitad + 1; // Cambio el limite inferior
        }
    }
    // Si llegamos hasta aca es que el elemento no estaba
    return -1;
}

void ordenarXCodigo(Producto productos[], int cant)
{
    Producto aux;
    int i = 0;
    bool ordenado = false;
    while(i < cant - 1 && !ordenado){
        ordenado = true;
        // Los ultimos i elementos ya estan ordenados
        for (int j = 0; j < cant - i - 1; j++) {
            if (productos[j].codigo > productos[j + 1].codigo) {
                aux = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

void ordenarPorApellido(Vendedor vendedores[], int cant) {
    Vendedor aux;
    int i = 0;
    bool ordenado = false;
    while(i < cant - 1 && !ordenado){
        ordenado = true;
        // Los ultimos i elementos ya estan ordenados
        for (int j = 0; j < cant - i - 1; j++) {
            if (vendedores[j].apellido > vendedores[j + 1].apellido) {
                aux = vendedores[j];
                vendedores[j] = vendedores[j + 1];
                vendedores[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

void anexar(int vecA[], int n, int vecB[], int m, int vecC[]) {
    // Lleno C con el vector A
    for(int i = 0; i < n; i ++) {
        vecC[i] = vecA[i];
    }

    // Lleno C con el vector B
    for(int i = 0; i < m; i ++) {
        vecC[n + i] = vecB[i];
    }
    return;
}

//apareo solo con iguales
void apareo(int vecA[], int cantA, int vecB[], int cantB, int vecC[], int &k)
{

    int i = 0, j = 0;

    int k = 0;

    while (i < cantA && j < cantB)
    {
        for (i = 0; i < cantA; i++)
        {
            for (j = 0; j < cantB; j++)
            {
                if (vecA[i] == vecB[j])
                {
                    vecC[k] = vecA[i];
                    k++;
                }
            }
        }
    }
    return;
}
/*ejercicio de leo
while (i < cantA && j < cantB){
    if (vecA[i] == vecB[j])
    {
        vecC[k] = vecA[i];
        i++;
        j++;
        k++;
    }
    else if (vecA[i] < vecB[j]){
        i++;
    }
    else {
        j++;
    }
}
*/


//apareo solo diferentes
void apareo(int vecA[], int cantA, int vecB[], int cantB, int vecC[], int &k)
{

    int i = 0, j = 0;
    k = 0;

    while (i < cantA && j < cantB)
    {
        if (vecA[i] < vecB[j])
        {
            vecC[k] = vecA[i];
            k++;
            i++;
        }
        if (vecA[i] == vecB[j])
        {
            i++;
            j++;
        }
        if (vecB[j] < vecA[i])
        {
            vecC[k] = vecB[j];
            j++;
            k++;
        }
        while (i < cantA)
        {
            vecC[k] = vecA[i];
            i++;
            k++;
        }
        while (j < cantB)
        {
            vecC[k] = vecB[j];
            j++;
            k++;
        }
    }
    return;
}

//ordenar de mayor a menor
void ordenarVector(int vec[], int cant)
{
    int aux;
    int i = 0;
    bool ordenado = false;
    while(i < cant - 1 && !ordenado){
        ordenado = true;
        // Los ultimos i elementos ya estan ordenados
        for (int j = 0; j < cant - i - 1; j++) {
            if (vec[j] < vec[j + 1]) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

//apareo mayor a menor
void apareoMayorAMenor(int vecA[], int cantA, int vecB[], int cantB, int vecC[], int &k){
    int i = cantA - 1, j = cantB - 1;
    k = 0;
    while(i >= 0 && j >= 0){
        if (vecA[i] > vecB[j]) {
            vecC[k] = vecA[i];
            i++;
        } else {
            vecC[k] = vecB[j];
            j++;
        }
            k++;
    }

    while(i >= 0) {
        vecC[k] = vecA[i];
        i++;
        k++;
    }

    while(j >= 0) {
        vecC[k] = vecB[j];
        j++;
        k++;
    }
    return;
}

