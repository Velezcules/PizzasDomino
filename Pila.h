#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
//#include "Aleatorio.h"
#include "Estructuras.h"
//#include "Cliente.h""


Pila *crearPila(int max);
PilaIng *crearPilaIng(int max);
void PushIng(PilaIng *pila2,int ingrediente);
void Push(Pila *pila,int c,CPizza *cP);
Pizza *pop(Cliente c);
PilaIng *convertirPila(Cliente c);
int pilaVacia(Cliente *c);
int *popIng(Cliente c, PilaIng *p);

#endif // PILA_H_INCLUDED
