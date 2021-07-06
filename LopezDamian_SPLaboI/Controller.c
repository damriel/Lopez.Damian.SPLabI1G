#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pais.h"
#include "parser.h"
#include "dam.h"

/** \brief Carga los datos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPais)
{
    int retorno=-1;
    FILE* pFile=NULL;
    if(path!=NULL && pArrayListPais!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile != NULL)
        {
            parser_PaisFromText(pFile, pArrayListPais);
            retorno=0;
            fclose(pFile);
        }
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListarPaises(LinkedList* pArrayListPais)
{
    int retorno = -1;
    int tam;
    ePais* aux=NULL;

    if(pArrayListPais!=NULL)
    {
        tam=ll_len(pArrayListPais);
        retorno=0;
        printf("\n====================================================\n");
        printf("             LISTADO DE PAISES\n");
        printf("====================================================\n");
        printf("  ID          Nombre            Vac1dosis   Vac2dosis   SinVacunar\n");
        for(int i=0; i<tam; i++)
        {
            aux = (ePais*)ll_get(pArrayListPais, i);
            pais_mostrarUnPais(aux);
        }
        printf("\n");
    }
    return retorno;
}

int controller_sortPaises(LinkedList* pArrayListPais)
{
	int retorno = 1;

    printf("Ordenando...\n");
    if(ll_sort(pArrayListPais, pais_compareByVacunados1dosis, 0)!=0)
    {
        retorno=-1;
    }

    return retorno;
}
