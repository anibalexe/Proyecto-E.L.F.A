#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int estado_elfa1,estado_elfa2;
    int puntajemoment;
    int preguntamoment;
    char nombreelfa[20];
    int aux,aux2;

}save;

save* createsave();
void separarpregunta(char*);
void leersave(save*,FILE*);
void guardar(estructura*,save*,int);
void leerarchivo(estructura*,int,FILE*);
const char* get_cvs_field(char* , int );
const char* get_cvs_field2(char* , int );
int imprimirpreguntas(estructura*, int );
void situacion_final(estructura*,int);
void leer_descripcion(estructura* ,FILE*);
void revisar_flag(estructura* ,int);
void limpiar_estructura(estructura*);
void leerfinales(estructura* ,FILE*);
#endif // FUNCIONES_H
