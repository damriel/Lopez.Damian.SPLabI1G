#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pais.h"
#include "parser.h"

/** \brief Parsea los datos los datos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int parser_PaisFromText(FILE* pFile, LinkedList* pArrayListPais)
{
    int retorno=0;
    char buffer[5][50];
    ePais* auxPais=NULL;

    if(pFile!=NULL && pArrayListPais!=NULL)
    {
        auxPais=pais_new();
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
        if(auxPais!=NULL)
        {
            while(!feof(pFile))
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4])<5)
                {
                    break;
                }
                else
                {
                    auxPais = pais_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
                    ll_add(pArrayListPais, auxPais);
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}

