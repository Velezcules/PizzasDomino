#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "Estructuras.h"

Cliente *crearCliente();
void llenarCliente(Cliente *c,CPizza *p,int numOrd);
//listarCliente(Cliente *c);
void listarOrden(Cliente *c);

#endif // CLIENTE_H_INCLUDED
