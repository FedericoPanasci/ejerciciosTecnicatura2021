#include<iostream>
using namespace std;
#define N 6

bool recorrerPrincipal (string secuenciaAdn[N][N]){
    int contador = 1;
    bool resultado = false;

    for (int i = 1; i < N; i++)
    {
        for (int j = 2; j < N; j++)
        {
            if (i==j){
                if (secuenciaAdn[i][i] == secuenciaAdn[i-1][j-1]){
                    contador++;   
                    if (contador == 4){
                        resultado = true;
                    }              
                }
                else
                {
                    contador = 1;
                }                      
            }
        }    
    }
    return resultado;
}
bool recorrerSecundaria (string secuenciaAdn[N][N]){
    int contador = 1;
    bool resultado = false;

    for (int i = 1; i < N; i++)
    {
        for (int j = N-i; j > 0; j--)
        {
            if (i+j == N-1){
                if (secuenciaAdn[i][j] == secuenciaAdn[i-1][j+1]){
                    contador++;   
                    if (contador == 4){
                        resultado = true;
                    }              
                }
                else
                {
                    contador = 1;
                }                      
            }
        }    
    }
    return resultado;
}

bool recorrerDecrecientesInf (string adn[N][N]){
    int contador = 1;
    bool resultado = false;

    for (int i=1 ; i<N ; i++){
        for(int j=0 ; j<N; j++){
            if(j>0 && i>0){
                if ( adn[i+1][j+1]==adn[i][j] ){
                    contador++;
                    if(contador>3){
                        resultado=true;
                    } 
                }      
            }
        }
    }

    return resultado;
}
bool recorrerDecrecientesSup(string adn[N][N]){
        int contador=1;
        bool resultado = false;

    for (int i=0 ; i<N ; i++){
        for(int j=0 ; j<N; j++){
            if(i>0){
                if ( adn[j][j+i]==adn[j-1][j+(i-1)] ){
                    contador++;
                    if(contador>3){
                        resultado=true;
                    } 
                }      
            }
        }
    }
    return resultado;
}

bool recorrerCrecientesInf(string adn[N][N]){
    int contador=1;
    bool resultado = false;

    for(int i= N ; i>0; i--){
        for (int j=1; j<N; j++){
            if(i+j>=N){
                if(adn[i][j]==adn[i-1][j+1]){
                    contador++;
                    if(contador>3){ 
                        resultado=true;
                    }
                }
            }
        }
    }
    return resultado;
}

bool recorrerCrecientesSup(string adn[N][N]){
    int contador=1;
    bool resultado = false;

    for (int i=N-1; i>0; i--){
        for (int j=0; j<N-1; j++){
            if (i+j<=N){
               if(adn[i][j] == adn[i-1][j+1]){
                   contador++;
                   if (contador>3){
                       resultado=true;
                   }
                }
            }
        }
    }
    return resultado;
}


bool recorrerDiagonal (string secuenciaAdn[N][N]){
    bool principal=false, secundaria=false, crecientesInf=false, decrecientesSup=false, decrecientesInf=false, crecientesSup=false;
    bool resultado = false;

    principal = recorrerPrincipal (secuenciaAdn);
    secundaria = recorrerSecundaria (secuenciaAdn);
    decrecientesSup = recorrerDecrecientesSup (secuenciaAdn);
    decrecientesInf = recorrerDecrecientesInf (secuenciaAdn);
    crecientesSup = recorrerCrecientesSup (secuenciaAdn);
    crecientesInf = recorrerCrecientesInf (secuenciaAdn);


    if (principal==false && secundaria==false && crecientesInf==false && crecientesSup==false && decrecientesSup==false && decrecientesInf==false){
        resultado = false;
    }
    else
    {
        resultado = true;
    }
    return resultado;
}

bool recorrerHorizontal (string secuenciaAdn[N][N]){
    bool resultado = false ;
    int contador = 0;
   
   for (int i=0; i<N; i++){
       for (int j=0; j<N; j++) {
           if (secuenciaAdn[i][j+1] == secuenciaAdn[i][j]){
               contador++;
               if (contador == 4){
                   resultado = true;
                }  
           }
           else
           {
            contador = 0;
           }
        }
    }
    return resultado;
}
bool recorrerVertical (string secuenciaAdn[N][N]){
    bool resultado = false ;
    int contador = 0;

    for (int j=0; j<N; j++){
        for (int i = 0; i < N; i++){
            if (secuenciaAdn[i+1][j]==secuenciaAdn [i][j]){
                contador++;
                if(contador == 4){
                    resultado = true;
                }
            }
            else{
                contador = 0;
            }   
        }
        
    }
    return resultado;
}


bool esMutante (string secuenciaAdn[N][N]){
    bool resultado = false;
    bool horizontal=false, vertical=false, diagonal=false;

    horizontal = recorrerHorizontal (secuenciaAdn);
    vertical = recorrerVertical(secuenciaAdn);
    diagonal = recorrerDiagonal(secuenciaAdn);

    if (horizontal == false && vertical == false && diagonal == false){
        resultado = false;
    }
    else
    {
        resultado = true;
    }
    

   return resultado;
}
void imprimirRespuesta (bool respuesta){
    if (respuesta == true)
    {
        cout<< "El humano es mutante";
    }
    else
    {
        cout<<"El humano no es mutante";
    }
    return;
}

int main (){
    bool respuesta=false;
    string secuenciaADN[N][N]={
        {	"	G	"	,	"	A 	"	,	"	E 	"	,	"	G	"	,	"	D	",  "A"     }	,
        {	"	C	"	,	"	Y	"	,	"	L	"	,	"	F	"	,	"	T	",  "S"     }	,
        {	"	T	"	,	"	G	"	,	"	F	"	,	"	A	"	,	"	T	", 	"P"     }	,
        {	"	G 	"	,	"	J	"	,	"	P	"	,	"	T	"	,	"	P	",  "E"     }	,
        {	"	F	"	,	"	C	"	,	"	O	"	,	"	P	"	,	"	L	",  "R"	    }	,
        {	"	F	"	,	"	T	"	,	"	P	"	,	"	T	"	,	"	L	",  "R"	    }	
    };    

    respuesta = esMutante (secuenciaADN);

    imprimirRespuesta (respuesta);
   
}