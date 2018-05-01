#ifndef ALEATORIO_H_INCLUDED
#define ALEATORIO_H_INCLUDED
#define MAXP 30
#include "Estructuras.h"


CPizza *crearPizzas();
void *crearCatalogo(CPizza *p);
void listarCatalogo(CPizza *p);
void ingRandom(CPizza *p,int i);
#endif // ALEATORIO_H_INCLUDED
