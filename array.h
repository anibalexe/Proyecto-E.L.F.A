#ifndef ARREGLO_H
#define ARREGLO_H
#include <stdio.h>
#include <stdlib.h>
    /*implementamos un array dentro de otro array*/
typedef struct n
{
    char titulo[100];
    char respuesta1[100];
    char respuesta2[100];
    char respuesta3[100];
    char respuesta4[100];
    int puntaje1,puntaje2,puntaje3,puntaje4; //se cambio p por puntaje
    int flag;
}preg;

typedef struct
{
    preg* pregunta[10];
    preg* current;
    int flag_posicion;
}array;

typedef struct estructura
{
    array* posicion[10]; //se cambio por posicion en ves de arr
    int puntaje;
    char descripcion[1000];
    char nombre[50];
    char final_1[200],final_2[200],final_3[200],final_4[200],final_5[200];

}estructura;

estructura* create_estructura();
array* create_arreglo_de_posiciones();

#endif // ARREGLO_H

