#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Pila.h"
#include "Cliente.h"

Pila *crearPila(int max){

        Pila *pila = (Pila*)calloc(1,sizeof(Pila));
        pila->arrP = (Pizza*)calloc(max,sizeof(Pizza));
        pila->tope = -1;

        return pila;
}
void Push(Pila *pila,int opPizza,CPizza *cP){
        pila->tope++;
        pila->arrP[pila->tope].Clave = cP->orden[opPizza].Clave;
        pila->arrP[pila->tope].Ingredientes = cP->orden[opPizza].Ingredientes;
        pila->arrP[pila->tope].Nombrep = cP->orden[opPizza].Nombrep;
        pila->arrP[pila->tope].Precio = cP->orden[opPizza].Precio;
}

void PushIng(PilaIng *pila2,int ingrediente){
        pila2->tope++;
        pila2->ingredientes[pila2->tope]= ingrediente;
        //pila2->ingrediente = ingrediente;
}

Pizza *pop(Cliente c){
    Pizza *aux;
        if(!pilaVacia(&c)){
           // printf("\n1");
            aux = &c.ordpizza->arrP[c.ordpizza->tope];
            //printf("\n2");
            c.ordpizza->tope--;
            return aux;
        }else{

            return NULL;
        }
}

int *popIng(Cliente c, PilaIng *p){
    int *aux;
        if(!pilaVaciaIng(p)){
           // printf("\n1");
            aux = p->ingredientes[p->tope];
            //printf("\n2");
            p->tope--;
            return aux;
        }else{

            return NULL;
        }
}

PilaIng *crearPilaIng(int max){

PilaIng *pila = (Pila*)calloc(max,sizeof(PilaIng));
        pila->ingredientes = (int*) calloc(max, sizeof(int));
        pila->tope = -1;
        pila->max = max;

        return pila;
}
int pilaVacia(Cliente *c){
    return c->ordpizza->tope == -1;
}
int pilaVaciaIng(PilaIng *c){
    return c->tope == -1;
}

PilaIng *convertirPila(Cliente c){
    PilaIng *aux = crearPilaIng(6);
    int i, j;
    for(i=0;i<6;i++){
        PushIng(aux, c.ordpizza->arrP->Ingredientes[i]);
    }
    return aux;

}

