#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"

int pais_setId(ePais* this, int id)
{
    int retorno=0;
    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno=1;
    }
    return retorno;
}

int pais_getId(ePais* this, int* id)
{
    int retorno=0;
    if(this!=NULL)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}

int pais_setNombre(ePais* this, char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL && strlen(nombre)>1 && strlen(nombre)<=30)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }
    return retorno;
}

int pais_getNombre(ePais* this, char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }
    return retorno;
}

int pais_setVac1dosis(ePais* this, int vac1dosis)
{
    int retorno=0;
    if(this!=NULL)
    {
        this->vac1dosis=vac1dosis;
        retorno=1;
    }
    return retorno;
}

int pais_getVac1dosis(ePais* this, int* vac1dosis)
{
    int retorno=0;
    if(this!=NULL)
    {
        *vac1dosis = this->vac1dosis;
        retorno=1;
    }
    return retorno;
}

int pais_setVac2dosis(ePais* this, int vac2dosis)
{
    int retorno=0;
    if(this!=NULL)
    {
        this->vac2dosis=vac2dosis;
        retorno=1;
    }
    return retorno;
}

int pais_getVac2dosis(ePais* this, int* vac2dosis)
{
    int retorno=0;
    if(this!=NULL)
    {
        *vac2dosis = this->vac2dosis;
        retorno=1;
    }
    return retorno;
}

int pais_setSinVacunar(ePais* this, int sinVacunar)
{
    int retorno=0;
    if(this!=NULL)
    {
        this->sinVacunar=sinVacunar;
        retorno=1;
    }
    return retorno;
}

int pais_getsinVacunar(ePais* this, int* sinVacunar)
{
    int retorno=0;
    if(this!=NULL)
    {
        *sinVacunar = this->sinVacunar;
        retorno=1;
    }
    return retorno;
}

ePais* pais_new()
{
    ePais* nuevoPais = (ePais*)malloc(sizeof(ePais));
    if(nuevoPais!=NULL)
    {
        nuevoPais->id=0;
        strcpy(nuevoPais->nombre,"");
        nuevoPais->vac1dosis=0;
        nuevoPais->vac2dosis=0;
        nuevoPais->sinVacunar=0;
    }
    return nuevoPais;
}

ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1dosisStr,char* vac2dosisStr,char* sinVacunarStr)
{
    ePais* nuevoPais = pais_new();
    if(nuevoPais!=NULL)
    {
        pais_setId(nuevoPais, atoi(idStr));
        pais_setNombre(nuevoPais, nombreStr);
        pais_setVac1dosis(nuevoPais, atoi(vac1dosisStr));
        pais_setVac2dosis(nuevoPais, atoi(vac2dosisStr));
        pais_setSinVacunar(nuevoPais, atoi(sinVacunarStr));
    }
    return nuevoPais;
}

int pais_mostrarUnPais(ePais* this)
{
    int retorno = 0;
    int id;
    char nombre[128];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
    if(this!=NULL &&
       pais_getId(this, &id) &&
       pais_getNombre(this, nombre) &&
       pais_getVac1dosis(this, &vac1dosis) &&
       pais_getVac2dosis(this, &vac2dosis) &&
       pais_getsinVacunar(this, &sinVacunar))
    {
        printf(" %4d   %19s  %8d    %8d    %8d\n",id,nombre,vac1dosis,vac2dosis,sinVacunar);
        retorno=1;
    }
    return retorno;
}

int pais_compareByVacunados1dosis(void* pais1, void* pais2)
{
	int retorno;

	if(pais1!=NULL && pais2!=NULL)
    {
        if(((ePais*)pais1)->vac1dosis > ((ePais*)pais2)->vac1dosis)
        {
            retorno=1;
        }
        else if(((ePais*)pais1)->vac1dosis < ((ePais*)pais2)->vac1dosis)
        {
            retorno=-1;
        }
        else
        {
            retorno=0;
        }
    }

	return retorno;
}

int paisesExitosos(void* p)
{
    int retorno=0;
    ePais* unPais = NULL;
    if(p!=NULL)
    {
        unPais = (ePais*)p;
        if(unPais->vac2dosis>=30)
        {
            retorno=1;
        }
    }
    return retorno;
}

int paisesEnElHorno(void* p)
{
    int retorno=0;
    ePais* unPais = NULL;
    if(p!=NULL)
    {
        unPais = (ePais*)p;
        if(unPais->sinVacunar>unPais->vac1dosis+unPais->vac2dosis)
        {
            retorno=1;
        }
    }
    return retorno;
}
