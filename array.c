#include "array.h"
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

estructura* create_estructura()
{
    int i;
    estructura* nuevo=(estructura*)malloc(sizeof(estructura));
    for(i=0;i<=10;i++)
      nuevo->posicion[i]=NULL;
    nuevo->puntaje=0;
    return nuevo;
}

array* create_arreglo_de_posiciones()
{
    int i;
    estructura* nuevo=(estructura*)malloc(sizeof(estructura));
    for(i=0;i<=10;i++){
        nuevo->posicion[i]=NULL;
    }

    return nuevo;
}



