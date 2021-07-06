#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[30];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
}ePais;

int pais_setId(ePais* this, int id);
int pais_getId(ePais* this, int* id);
int pais_setNombre(ePais* this, char* nombre);
int pais_getNombre(ePais* this, char* nombre);
int pais_setVac1dosis(ePais* this, int vac1dosis);
int pais_getVac1dosis(ePais* this, int* vac1dosis);
int pais_setVac2dosis(ePais* this, int vac1dosis);
int pais_getVac2dosis(ePais* this, int* vac1dosis);
int pais_setSinVacunar(ePais* this, int sinVacunar);
int pais_getsinVacunar(ePais* this, int* sinVacunar);
ePais* pais_new();
ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1dosisStr,char* vac2dosisStr,char* sinVacunarStr);
int pais_mostrarUnPais(ePais* this);
int pais_compareByVacunados1dosis(void* pais1, void* pais2);
int paisesExitosos(void* p);
int paisesEnElHorno(void* p);

#endif // PAIS_H_INCLUDED
