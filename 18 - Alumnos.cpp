/*Ej. 18: Dado el archivo “ALUMNOS.dat” con los datos personales de alumnos ordenado por legajo, con
el siguiente diseño:
a.1 Legajo (8 dígitos) a.2 Apellido y nombre ( 30 caracteres)
a.3 Domicilio (20 caracteres) a.4 Código postal (4 dígitos)
a.5 Teléfono (10 caracteres) a.6 Año de ingreso (4 dígitos)
Y otro archivo con el mismo orden que el mencionado llamado “NOVEDADES.dat”, con las
actualizaciones (altas, bajas, y modificaciones) a ser aplicadas, donde cada registro contiene además de
todos los campos de Alumnos.dat un código de operación (“A”= Alta, “B”= Baja, “M”= Modificación).
a- Desarrollar todos los pasos necesarios para realizar un programa que genere un archivo actualizado
“ALUMACTU.dat” con el mismo diseño.
b- Rehacer el ejercicio considerando que el archivo NOVEDADES es de texto separado por tabs en
lugar de binario.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ALUMNO{
    int legajo;
    char ApellidoNombre[31];
    char domicilio[11];
    int cp;
    int telefono;
    int anioIngreso;
};
struct NOVEDADES{
    int legajo;
    char ApellidoNombre[31];
    char domicilio[11];
    int cp;
    int telefono;
    int anioIngreso;
    char operacion;
};
FILE * abrirArchivo(char * nombreArchivo, char* modo){
    FILE *archivo = fopen(nombreArchivo, modo);
    if(archivo == NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }
    return archivo;
}
ALUMNO obtenerDato(NOVEDADES registro){
    ALUMNO dato;

    dato.legajo = registro.legajo;
    strcpy(dato.ApellidoNombre,registro.ApellidoNombre);
    strcpy(dato.domicilio,registro.domicilio);
    dato.cp = registro.cp;
    dato.telefono = registro.telefono;
    dato.anioIngreso = registro.anioIngreso; 

   return dato;
}

void grabarArchivo(FILE *alumnos, FILE *novedades,FILE *actualizados){
    ALUMNO aux;
    ALUMNO alumno;
    NOVEDADES novedad;

    fread(&alumno, sizeof(ALUMNO),1, alumnos);
    fread(&novedad, sizeof(NOVEDADES), 1, novedades);

    while (!feof(alumnos) && !feof(novedades)){
        
        if (alumno.legajo == novedad.legajo){
            if (novedad.operacion == 'B'){
                fread(&alumno, sizeof(ALUMNO),1, alumnos);
                fread(&novedad, sizeof(NOVEDADES), 1, novedades);
            } else if (novedad.operacion == 'M'){
                aux = obtenerDato(novedad);    
                fwrite(&aux,sizeof(ALUMNO),1,actualizados);
                fread(&alumno, sizeof(ALUMNO),1, alumnos);
                fread(&novedad, sizeof(NOVEDADES), 1, novedades);
            }         
        }

        if (alumno.legajo < novedad.legajo){
            fwrite(&alumno,sizeof(ALUMNO),1,actualizados);
            fread(&alumno, sizeof(ALUMNO),1, alumnos);
        }
        if (novedad.legajo < alumno.legajo){
            aux = obtenerDato(novedad);    
            fwrite(&aux,sizeof(ALUMNO),1,actualizados);
            fread(&novedad, sizeof(NOVEDADES), 1, novedades);
        
        }
    }    
    while(!feof(alumnos)){

         fwrite(&alumno,sizeof(ALUMNO),1,actualizados);
            fread(&alumno, sizeof(ALUMNO),1, alumnos);
    }

    while (!feof(novedades))
    {
        aux = obtenerDato(novedad);    
            fwrite(&aux,sizeof(ALUMNO),1,actualizados);
            fread(&novedad, sizeof(NOVEDADES), 1, novedades);
    }

    return;
}






int main(){

    FILE *alumnos = abrirArchivo("alumnos.dat","rb");
    FILE *novedades = abrirArchivo("novedades.dat","rb");
    FILE *actualizados = abrirArchivo("aluActu.dat","wb");

    grabarArchivo(alumnos, novedades, actualizados);



    fclose(alumnos);
    fclose(novedades);
    return 0;
}