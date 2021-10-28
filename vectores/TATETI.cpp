#include <iostream>

using namespace std;

#define CANT_MATRIZ 3

void imprimirTablero(char tablero[CANT_MATRIZ][CANT_MATRIZ])
{
    for (int i = 0; i < CANT_MATRIZ; i++)
    {
        for (int j = 0; j < CANT_MATRIZ; j++)
        {
            cout << " | " << tablero[i][j];
        }
        cout << endl;
        cout << " ----------- " << endl;
    }
    return;
}

bool esGanador(char tablero[CANT_MATRIZ][CANT_MATRIZ])
{
    if (tablero[0][0] == 'X' && tablero[0][1] == 'X' && tablero[0][2] == 'X' ||
        tablero[0][0] == 'X' && tablero[1][0] == 'X' && tablero[2][0] == 'X' ||
        tablero[1][0] == 'X' && tablero[1][1] == 'X' && tablero[1][2] == 'X' ||
        tablero[2][0] == 'X' && tablero[2][1] == 'X' && tablero[2][2] == 'X' ||
        tablero[0][1] == 'X' && tablero[1][1] == 'X' && tablero[2][1] == 'X' ||
        tablero[0][2] == 'X' && tablero[1][2] == 'X' && tablero[2][2] == 'X' ||
        tablero[0][0] == 'X' && tablero[1][1] == 'X' && tablero[2][2] == 'X' ||
        tablero[0][2] == 'X' && tablero[1][1] == 'X' && tablero[2][0] == 'X')
    {
        return true;
    }
        if (tablero[0][0] == 'O' && tablero[0][1] == 'O' && tablero[0][2] == 'O' ||
            tablero[0][0] == 'O' && tablero[1][0] == 'O' && tablero[2][0] == 'O' ||
            tablero[1][0] == 'O' && tablero[1][1] == 'O' && tablero[1][2] == 'O' ||
            tablero[2][0] == 'O' && tablero[2][1] == 'O' && tablero[2][2] == 'O' ||
            tablero[0][1] == 'O' && tablero[1][1] == 'O' && tablero[2][1] == 'O' ||
            tablero[0][2] == 'O' && tablero[1][2] == 'O' && tablero[2][2] == 'O' ||
            tablero[0][0] == 'O' && tablero[1][1] == 'O' && tablero[2][2] == 'O' ||
            tablero[0][2] == 'O' && tablero[1][1] == 'O' && tablero[2][0] == 'O')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool tableroLleno(char tablero[CANT_MATRIZ][CANT_MATRIZ])
    {
        int casilleros = 0;
        for (int i = 0; i < CANT_MATRIZ; i++)
        {
            for (int j = 0; j < CANT_MATRIZ; i++)
            {
                if (tablero[i][j] == 'X' || tablero[i][j] == 'O')
                {
                    casilleros++;
                }
            }
        }
        if (casilleros == 9)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool ganoX(char tablero[CANT_MATRIZ][CANT_MATRIZ])
    {
        if (tablero[0][0] == 'X' && tablero[0][1] == 'X' && tablero[0][2] == 'X' ||
            tablero[0][0] == 'X' && tablero[1][0] == 'X' && tablero[2][0] == 'X' ||
            tablero[1][0] == 'X' && tablero[1][1] == 'X' && tablero[1][2] == 'X' ||
            tablero[2][0] == 'X' && tablero[2][1] == 'X' && tablero[2][2] == 'X' ||
            tablero[0][1] == 'X' && tablero[1][1] == 'X' && tablero[2][1] == 'X' ||
            tablero[0][2] == 'X' && tablero[1][2] == 'X' && tablero[2][2] == 'X' ||
            tablero[0][0] == 'X' && tablero[1][1] == 'X' && tablero[2][2] == 'X' ||
            tablero[0][2] == 'X' && tablero[1][1] == 'X' && tablero[2][0] == 'X')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool ganoO(char tablero[CANT_MATRIZ][CANT_MATRIZ])
    {
        if (tablero[0][0] == 'O' && tablero[0][1] == 'O' && tablero[0][2] == 'O' ||
            tablero[0][0] == 'O' && tablero[1][0] == 'O' && tablero[2][0] == 'O' ||
            tablero[1][0] == 'O' && tablero[1][1] == 'O' && tablero[1][2] == 'O' ||
            tablero[2][0] == 'O' && tablero[2][1] == 'O' && tablero[2][2] == 'O' ||
            tablero[0][1] == 'O' && tablero[1][1] == 'O' && tablero[2][1] == 'O' ||
            tablero[0][2] == 'O' && tablero[1][2] == 'O' && tablero[2][2] == 'O' ||
            tablero[0][0] == 'O' && tablero[1][1] == 'O' && tablero[2][2] == 'O' ||
            tablero[0][2] == 'O' && tablero[1][1] == 'O' && tablero[2][0] == 'O')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void quienGano(char tablero[CANT_MATRIZ][CANT_MATRIZ])
    {
        if (ganoX(tablero))
        {
            cout << "el ganador fue el jugador X" << endl;
        }
        else
        {
            if (ganoO(tablero))
            {
                cout << "el ganador fue el jugador O" << endl;
            }
            else
            {
                cout << "Hubo un empate, para volver a jugar reiniciar el programa." << endl;
            }
        }
    }

    int main()
    {
        int fila = 0, columna = 0;
        char tablero[CANT_MATRIZ][CANT_MATRIZ] = {' '};

        cout << "inicia el juego, arranca jugador X, indique en que fila va a ubicar su ficha: ";
        cin >> fila;
        cout << "eliga la columna: ";
        cin >> columna;
        tablero[fila][columna] = 'X';
        imprimirTablero(tablero);

        while (tableroLleno && !esGanador(tablero))
        {
            cout << "jugador O elija una fila: ";
            cin >> fila;
            cout << "elija una columna: ";
            cin >> columna;
            tablero[fila][columna] = 'O';
            imprimirTablero(tablero);
            if (tableroLleno && !esGanador(tablero))
            {
                cout << "jugador X elija una fila: ";
                cin >> fila;
                cout << "elija una columna: ";
                cin >> columna;
                tablero[fila][columna] = 'X';
            }
            imprimirTablero(tablero);
        }
        quienGano(tablero);
        system("pause");
        return 0;
    }