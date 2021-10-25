int numAlto(int num, int alto){
    if (num > alto)
    {
        alto = num;
    }
    return alto;
}

int numBajo (int num, int bajo){
    if (num < bajo || bajo == 0)
    {
        bajo = num;
    }
    return bajo;
}

int promedioSum(int promedio, int suma, int i){
    promedio = suma / i;
    return promedio;
}