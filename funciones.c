#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "funciones.h"


save* createsave()
{
    /*inicializa los nodos de save en 0*/
    save* aux=(save*)malloc(sizeof(save));
    aux->estado_elfa1=0;
    aux->estado_elfa2=0;
    aux->preguntamoment=0;
    aux->puntajemoment=0;
    aux->aux=0;
    aux->aux2=0;
    return aux;
}
void leerarchivo(estructura* a,int b, FILE* fp)
{
        int i=0;
        char line[1024];
        char* tmp;

        while(b<=9)
        {
            i=0;
            array* nueva_pos=create_arreglo_de_posiciones();
            a->posicion[b]=nueva_pos;
            for(i;i<10;){
                fgets(line, 1024, fp);
                nueva_pos->flag_posicion=0;


                preg* p=(preg*)malloc(sizeof(preg));

                tmp=get_cvs_field(line, 1);
                strcpy(p->titulo,tmp);
                free(tmp);

                tmp=get_cvs_field(line, 2);
                strcpy(p->respuesta1,tmp);
                free(tmp);

                tmp=get_cvs_field(line, 3);
                strcpy(p->respuesta2,tmp);
                free(tmp);

                tmp=get_cvs_field(line, 4);
                strcpy(p->respuesta3,tmp);
                free(tmp);

                tmp=get_cvs_field(line, 5);
                strcpy(p->respuesta4,tmp);
                free(tmp);

                tmp=get_cvs_field(line, 6);
                p->puntaje1=atoi(tmp);
                free(tmp);

                tmp=get_cvs_field(line, 7);
                p->puntaje2=atoi(tmp);
                free(tmp);

                tmp=get_cvs_field(line, 8);
                p->puntaje3=atoi(tmp);
                free(tmp);

                tmp=get_cvs_field(line, 9);
                p->puntaje4=atoi(tmp);
                free(tmp);


                nueva_pos->pregunta[i]=p;
                a->posicion[b]->pregunta[i]=p;
                a->posicion[b]->pregunta[i]->flag=0;
                i++;
                }
            b++;
        }

}
const char* get_cvs_field(char* tmp, int i)
{
    char* line = strdup(tmp);
    const char* tok;
    for (tok = strtok(line, "/");
            tok && *tok;
            tok = strtok(NULL, "/"))
    {
        if (!--i)
            return tok;
    }
    return NULL;
}

void leersave(save* sap,FILE* fp)
{
    /*esta funcion lee lo que esta dentro del archivo save.txt*/
        char line[1024];
        char* tmp;


                fgets(line, 1024, fp);

                tmp=get_cvs_field(line, 1);
                strcpy(sap->nombreelfa,tmp);
                free(tmp);

                tmp=get_cvs_field(line, 2);
                sap->preguntamoment=atoi(tmp);
                free(tmp);

                tmp=get_cvs_field(line, 3);
                sap->puntajemoment=atoi(tmp);
                free(tmp);

                tmp=get_cvs_field(line, 4);
                sap->estado_elfa1=atoi(tmp);
                free(tmp);

                tmp=get_cvs_field(line, 5);
                sap->estado_elfa2=atoi(tmp);
                free(tmp);


}

int empezar_juego(estructura* a,save* s,int saveopcion,int opcion)
{
        /*esta funcion tira las preguntas de forma randomizada*/
    int strikes=0;
    int preg_max=s->preguntamoment;
    int saveop;
    int porcentaje_actual;
    a->puntaje=s->puntajemoment;
     int b=calcular_porcentaje(a->puntaje,preg_max);
    if(preg_max==1)
     {
         b=5;
     }
    while(strikes!=3 && preg_max<=30)
    {
        printf("%s\n",a->nombre);
        printf("%s\n",a->descripcion);
        printf("Para salir y guardar presione numero 5\n\n");
        printf("Para devolverse presione numero 6\n\n");
        printf("%d)",preg_max);
        s->preguntamoment=preg_max;
        s->puntajemoment=a->puntaje;

        while(!imprimirpreguntas(a,b));
        int op=0;

        while(op<1 || op>6)
        scanf("%d",&op);
        switch(op)
        {
                /*almacena el valor obtenido de la respuesta */
            case 1: a->puntaje+=a->posicion[b]->current->puntaje1;
                    if(a->posicion[b]->current->puntaje1==0){strikes++;}

                    break;
            case 2: a->puntaje+=a->posicion[b]->current->puntaje2;
                    if(a->posicion[b]->current->puntaje2==0){strikes++;}

                    break;
            case 3: a->puntaje+=a->posicion[b]->current->puntaje3;
                    if(a->posicion[b]->current->puntaje3==0){strikes++;}

                    break;
            case 4: a->puntaje+=a->posicion[b]->current->puntaje4;
                    if(a->posicion[b]->current->puntaje4==0){strikes++;}

                    break;
            case 5:
                    guardar(a,s,saveopcion);
                    return;
                    break;
            case 6:

                    s->preguntamoment=1;
                    return;
                    break;
        }
        system("pause");
        system("cls");
          preg_max++;
        b=calcular_porcentaje(a->puntaje,preg_max);
    }
    guardar(a,s,saveopcion);
    situacion_final(a,b);
/* Cuando se llega a la pregunta maxima y el puntaje es el adecuado para conquistar la elfa
se cambia el flag del estado de la elfa para saber si se conquisto*/
    if(b>=8 && preg_max==31)
    {
        if(opcion==1)
        {
            s->estado_elfa1=1;
            opcion=2;
            s->aux=saveopcion;
            s->aux2=1;
            guardar(a,s,saveopcion);
            if(s->estado_elfa2==0)
                {
                s->preguntamoment=1;
                s->puntajemoment=0;
                }
        }
            else if(opcion==2)
            {
                s->estado_elfa2=1;
                opcion=1;
                s->aux=saveopcion;
                s->aux2=1;
                guardar(a,s,saveopcion);
            if(s->estado_elfa1==0)
                {
                s->preguntamoment=1;
                s->puntajemoment=0;
                }
            }
    }
    saveopcion=s->aux;
}

int calcular_porcentaje(int x,int preg)
{
        /*calcula el porcentae segun el puntaje esperado*/

    int y;
    y=preg*5;
    int aux;
    aux=x*100;
    aux=aux/y;
    if(aux/10==10)
        return 9;
    else{
        return aux/10;
    }
}

int imprimirpreguntas(estructura* a,int b)
{
        /*imprime las preguntas random basadas en el porcentaje*/
    srand (time(NULL));
    revisar_flag(a,b);
    if(a->posicion[b]->flag_posicion==1)
    {
        while(a->posicion[b]->flag_posicion==1)
        {
            if(b==9)
            {
                while(a->posicion[b]->flag_posicion==1)
                    b--;
            }
            else
            {
                b++;
            }
        }
    }
    int lugar;
    lugar=rand()%10;
    a->posicion[b]->current=a->posicion[b]->pregunta[lugar];
    if(a->posicion[b]->current->flag==0)
    {
        printf("%s\n", a->posicion[b]->current->titulo);
        printf("\t1)%s\n\t2)%s\n\t3)%s\n\t4)%s\n",a->posicion[b]->current->respuesta1,a->posicion[b]->current->respuesta2,a->posicion[b]->current->respuesta3,a->posicion[b]->current->respuesta4);
        /*separarpregunta(a->posicion[b]->current->titulo);*/
        a->posicion[b]->current->flag=1;
        revisar_flag(a,b);

        return 1;
    }
    else
    {
        for(lugar=0;lugar<9;lugar++)
        {
            if(a->posicion[b]->pregunta[lugar]->flag==0)
            {
                printf("%s\n\t1)%s\n\t2)%s\n\t3)%s\n\t4)%s\n", a->posicion[b]->pregunta[lugar]->titulo,a->posicion[b]->pregunta[lugar]->respuesta1,a->posicion[b]->pregunta[lugar]->respuesta2,a->posicion[b]->pregunta[lugar]->respuesta3,a->posicion[b]->pregunta[lugar]->respuesta4);
                a->posicion[b]->pregunta[lugar]->flag=1;
                revisar_flag(a,b);
                return 1;
            }
        }

    }

}


void situacion_final(estructura* a,int final)
{
    system("cls");
    if(final>=0 && final<=1){
        printf("%s\n",a->final_1);
    }
    if(final>=2 && final<=3){
        printf("%s\n",a->final_2);
    }
    if(final>=4 && final<=5){
        printf("%s\n",a->final_3);
    }
    if(final >=6 && final<=7){
        printf("%s\n",a->final_4);
    }
    if(final>=8){
        printf("%s\n",a->final_5);
    }
    system("pause");

}

void leer_descripcion(estructura* a ,FILE* fp)
{
    char* tmp;
    char line[1024];
    while (fgets(line, 1024, fp)){

        tmp=get_cvs_field(line, 1);
        strcpy(a->nombre,tmp);
        free(tmp);

        tmp=get_cvs_field(line, 2);
        strcpy(a->descripcion,tmp);
        free(tmp);
    }

}

void revisar_flag(estructura* a,int b)
{
    int i=0,aux=0;
    for(i;i<9;i++)
    {
        if(a->posicion[b]->pregunta[i]->flag==1)
            aux++;
    }
    if(aux==9)
    {
        a->posicion[b]->flag_posicion=1;
    }
}

void limpiar_estructura(estructura* e)
{
    int i,j;
    for(i=0;i<=9;i++)
    {
        for(j=0;j<=9;j++)
        {
            free(e->posicion[i]->pregunta[j]);
        }
        free(e->posicion[i]);
    }
    free(e);

}
void guardar(estructura* a,save* s,int saveopcion)
{
    /*Segun la opcion de donde queire guardar nos manda a esta funcion y con el switch selecciona la correspondiente*/
    switch(saveopcion)
    {
       FILE* archivoguardar;

       case 1:
            archivoguardar= fopen("save1.txt","w");

            fprintf(archivoguardar,"%s%c%d%c%d%c%d%c%d%c\n",a->nombre,'/',s->preguntamoment,'/',s->puntajemoment,'/',s->estado_elfa1,'/',s->estado_elfa2,'/');

            fclose(archivoguardar);
            break;
       case 2:

            archivoguardar= fopen("save2.txt","w");

            fprintf(archivoguardar,"%s%c%d%c%d%c%d%c%d%c\n",a->nombre,'/',s->preguntamoment,'/',s->puntajemoment,'/',s->estado_elfa1,'/',s->estado_elfa2,'/');

            fclose(archivoguardar);
            break;
       case 3:
            archivoguardar= fopen("save3.txt","w");

            fprintf(archivoguardar,"%s%c%d%c%d%c%d%c%d%c\n",a->nombre,'/',s->preguntamoment,'/',s->puntajemoment,'/',s->estado_elfa1,'/',s->estado_elfa2,'/');

            fclose(archivoguardar);
            break;
    }
}


void leerfinales(estructura* a, FILE* fp)
{
    char line[1024];
    char* tmp;
    fgets(line, 1024, fp);

        tmp=get_cvs_field(line, 1);
        strcpy(a->final_1,tmp);
        free(tmp);

        tmp=get_cvs_field(line, 2);
        strcpy(a->final_2,tmp);
        free(tmp);

        tmp=get_cvs_field(line, 3);
        strcpy(a->final_3,tmp);
        free(tmp);

        tmp=get_cvs_field(line, 4);
        strcpy(a->final_4,tmp);
        free(tmp);

        tmp=get_cvs_field(line, 2);
        strcpy(a->final_5,tmp);
        free(tmp);


}

