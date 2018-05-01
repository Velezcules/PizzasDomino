#ifndef COLAC_H_INCLUDED
#define COLAC_H_INCLUDED
#include "Aleatorio.h"
#include "Cliente.h"
#include "Estructuras.h"


ColaCir *crearCola(int max);
int validarVacio(ColaCir *c);
int validarEspacio(ColaCir *c);
void insertar(ColaCir *c, Cliente *cliente);
void listarColaCir(ColaCir *c);
Cliente atender(ColaCir *c);
void preparPizza(Cliente c,int i);

#endif // COLAC_H_INCLUDED
