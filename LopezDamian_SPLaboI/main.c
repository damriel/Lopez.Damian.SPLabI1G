#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dam.h"
#include "LinkedList.h"
#include "Controller.h"
#include "pais.h"

int paisesExitosos(void* p);

int main()
{
    srand(time(NULL));
    int opcion;
    char archivo[20] = " ";
    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* listaConValores = NULL;
    LinkedList* listaExitososHorno = NULL;

    do
    {
        opcion = dam_menuOpciones();
        switch(opcion)
        {
        case 1:
            printf("Ingrese el nombre del archivo a cargar (vacunas.csv): ");
            fflush(stdin);
            scanf("%s",archivo);
            if(!controller_loadFromText(archivo,listaPaises))
            {
                printf("Paises cargados con exito!\n\n");
            }
            else
            {
                printf("Ocurrio un error intentando abrir el archivo (no existe, no se pudo abrir o esta corrompido).\n\n");
            }
            break;
        case 2:
            if(ll_isEmpty(listaPaises))
            {
                printf("Aun no hay paises cargados.\n");
            }
            else
            {
                controller_ListarPaises(listaPaises);
            }
            break;
        case 3:
            if(ll_isEmpty(listaPaises))
            {
                printf("Aun no hay paises cargados.\n");
            }
            else
            {
                listaConValores = ll_map(listaPaises,asignarValores);
                printf("\n\nVALORES ASIGNADOS EXITOSAMENTE! \n\n");
                controller_ListarPaises(listaConValores);
            }
            break;
        case 4:
            if(listaConValores==NULL || ll_isEmpty(listaConValores))
            {
                printf("Aun no se asignaron las estadisticas.\n");
            }
            else
            {
                listaExitososHorno = ll_filter(listaConValores, paisesExitosos);
                controller_ListarPaises(listaExitososHorno);
            }
            break;
        case 5:
            if(listaConValores==NULL || ll_isEmpty(listaConValores))
            {
                printf("Aun no se asignaron las estadisticas.\n");
            }
            else
            {
                listaExitososHorno = ll_filter(listaPaises, paisesEnElHorno);
                controller_ListarPaises(listaExitososHorno);
            }
            break;
        case 6:
            if(listaConValores==NULL || ll_isEmpty(listaConValores))
            {
                printf("Aun no se asignaron las estadisticas.\n");
            }
            else
            {
                controller_sortPaises(listaPaises);
                controller_ListarPaises(listaPaises);
            }
            break;
        case 7:
            break;
        }
    system("pause");
    system("cls");
    }while(opcion!=8);

    free(listaPaises);

    if(listaConValores!=NULL)
    {
        free(listaConValores);
    }

    if(listaExitososHorno!=NULL)
    {
        free(listaExitososHorno);
    }

    return 0;
}

