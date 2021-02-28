#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "funciones.h"

int main()
{
    int posicion=0;
    int opcion=10;
    int opcionsave=0;
    estructura* a=create_estructura();
    save* sap=createsave();

    system("color F5");

    while(opcion!=0){
    int opcionsave=sap->aux2;
    int saveopcion=sap->aux;
    while(opcionsave<1 || opcionsave>2)
    {
            printf("     %c%c%c%c%c%c%c              %c%c%c%c%c%c\n",175,178,178,178,178,178,178,178,178,178,178,178,178);
            printf("    %c%c      %c            %c       %c\n",175,177,178,178,178);
            printf("  %c%c          %c        %c           %c\n",175,177,178,178,178);
            printf(" %c%c             %c    %c              %c\n",175,177,178,178,178);
            printf("%c%c               %c  %c                %c\n",175,177,178,177,178);
            printf("%c%c              presione:             %c\n",175,177,178,178);
            printf(" %c%c      1 para cargar partida       %c\n",175,177,178);
            printf("  %c%c        2 para empezar          %c\n",175,177,178);
            printf("    %c%c     una nueva partida      %c\n",175,177,178);
            printf("      %c%c                        %c\n",175,177,178);
            printf("        %c%c                    %c\n",175,177,178);
            printf("          %c%c                %c\n",175,177,178);
            printf("            %c%c            %c\n",175,177,178);
            printf("              %c%c        %c\n",175,177,178);
            printf("                %c%c    %c\n",175,177,178);
            printf("                 %c%c  %c\n",175,177,178);
            printf("                   %c%c\n",175,178);
        scanf("%d",&opcionsave);
        system("cls");
    }
       while(saveopcion<1 || saveopcion>3){
        printf("Elija una opcion de save:\n");

        FILE* fp = fopen("save1.txt", "r");
        leersave(sap,fp);
        printf("%cSave 1\t%s\t\t/Pregunta donde quedo :%d\t/Punjate :%d\n",3,sap->nombreelfa,sap->preguntamoment,sap->puntajemoment);
        fclose(fp);

        fp = fopen("save2.txt", "r");
        leersave(sap,fp);
        printf("%cSave 2\t%s\t\t/Pregunta donde quedo :%d\t/Punjate :%d\n",3,sap->nombreelfa,sap->preguntamoment,sap->puntajemoment);
        fclose(fp);

        fp = fopen("save3.txt", "r");
        leersave(sap,fp);
        printf("%cSave 3\t%s\t\t/Pregunta donde quedo :%d\t/Punjate :%d\n",3,sap->nombreelfa,sap->preguntamoment,sap->puntajemoment);
        fclose(fp);

        scanf("%d",&saveopcion);
        system("cls");
        switch(saveopcion)
        {
            FILE* fp;
        case 1:
                fp = fopen("save1.txt", "r");
                leersave(sap,fp);
                if(opcionsave==2)
                {

                    sap->preguntamoment=1;
                    sap->puntajemoment=0;
                    sap->estado_elfa1=0;
                    sap->estado_elfa2=0;
                }
                fclose(fp);
                break;
        case 2:
                fp = fopen("save2.txt", "r");
                leersave(sap,fp);
                if(opcionsave==2)
                {

                    sap->preguntamoment=1;
                    sap->puntajemoment=0;
                    sap->estado_elfa1=0;
                    sap->estado_elfa2=0;
                }
                fclose(fp);
                break;
        case 3:
                fp = fopen("save3.txt", "r");
                leersave(sap,fp);
                if(opcionsave==2)
                {

                    sap->preguntamoment=1;
                    sap->puntajemoment=0;
                    sap->estado_elfa1=0;
                    sap->estado_elfa2=0;
                }
                fclose(fp);
                break;
        }

        char* nomb="Pablito";
        char* nomb2="sylvana";
        /* Esta parte del programa nos verifica si el nombre de la elfa ya fue guardado para asi acceder de forma
        mas eficaz a los saves*/
        if(opcionsave==1)
        {
           if(strcmp(sap->nombreelfa,nomb2)==0)
            {

                if(sap->preguntamoment>=1 && sap->preguntamoment<30)
                {
                    if(sap->estado_elfa2==0)
                    opcion=1;
                }

                if(sap->preguntamoment==30)
                {
                sap->preguntamoment=1;
                sap->puntajemoment=0;
                }
            }
            if(strcmp(sap->nombreelfa,nomb)==0)
            {
                if(sap->preguntamoment>=1 && sap->preguntamoment<30)
                {
                    if(sap->estado_elfa1==0)
                    opcion=2;
                }
                 if(sap->preguntamoment==30)
                {
                sap->preguntamoment=1;
                sap->puntajemoment=0;
                }
            }
        }
    }
    system("cls");

        while(opcion<0 || opcion>2)
        {
            estructura* a=create_estructura();

            printf("====================================MENU=======================================");
            printf("\n\n\n\n\t\t\t\telige una elfa\n");
            printf("\t\t\t\t0) salir\n");
            printf("\t\t\t\t(Un %c Significa que fue conquistada)\n\n",3);

            FILE* nomb = fopen("sylvana.txt", "r");
            leer_descripcion(a,nomb);
            printf("\t\t\t\t1)%s\n",a->nombre);
            printf("\t\t\t\t%s\n",a->descripcion);
            if(sap->estado_elfa1==1)
            {
               printf("\t\t\t\t%c\n",3);
            }

            fclose(nomb);

            nomb = fopen("pablo.txt", "r");
            leer_descripcion(a,nomb);
            printf("\t\t\t\t2)%s\n",a->nombre);
            printf("\t\t\t\t%s\n",a->descripcion);
            if(sap->estado_elfa2==1)
            {
               printf("\t\t\t\t%c\n",3);
            }

            fclose(nomb);

            scanf("\t\t\t\t%d",&opcion);
            system("cls");
        }
        /*Esta parte del menu da la opcion de escoger una elfa y rellena los arreglos con los archivos de preguntas*/
        switch(opcion)
        {
        case 1:{
            FILE* fp = fopen("sylvana.txt", "r");
            leerfinales(a,fp);
            leerarchivo(a,posicion,fp);
            leer_descripcion(a,fp);
            fclose(fp);

            empezar_juego(a,sap,saveopcion,opcion);
            limpiar_estructura(a);
            break;
            }
        case 2:{
            FILE* fp = fopen("pablo.txt", "r");
            leerfinales(a,fp);
            leerarchivo(a,posicion,fp);
            leer_descripcion(a,fp);
            fclose(fp);

            empezar_juego(a,sap,saveopcion,opcion);
            limpiar_estructura(a);
            break;
            }
    }
    system("cls");
    if(opcion==0)
        return;
    opcion=-1;
}

}
