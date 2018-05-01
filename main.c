#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Cliente.h"
#include "Aleatorio.h"
#include "Pila.h"
#include "ColaC.h"
#include "menu.h"
#include "Estructuras.h"


int main()
{

    int i, op, numOrd = 0;
    srand(time(NULL));
    CPizza *p= crearPizzas();
    Cliente *cliente = crearCliente();
    crearCatalogo(p);
    ColaCir *pedidos = crearCola(5);
    Cliente aux;


    do{
        op = Menu("\n1)Registrar nueva orden\n2)Ver ordenes\n3)Simular proceso\n4)Salir\n\nOpcion: ", 4);
        switch(op){
            case 1:
                numOrd++;
                llenarCliente(cliente,p,numOrd);
                insertar(pedidos, cliente);
                break;
            case 2:
                listarColaCir(pedidos);
                break;
            case 3:
                aux = atender(pedidos);
                for(i=0;i< cliente->CantMax; i++){
                   // printf("%d",cliente->CantMax);
                    preparPizza(aux,i);
                }
                break;
        }

    }while(op != 4);

    return 0;
}
