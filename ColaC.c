#include <stdio.h>
#include <stdlib.h>
#include "ColaC.h"


ColaCir *crearCola(int max){
    ColaCir *c;
    c = (ColaCir *) calloc(1, sizeof(ColaCir));
    c->arrClientes = (Cliente *) calloc(max, sizeof(Cliente));
    c->t = c->h = -1;
    c->maxC = max;
    return c;
}

int validarVacio(ColaCir *c){
    return (c->h == -1);
}

void insertar(ColaCir *c, Cliente *cliente){
    if(validarVacio(c))
        c->h++;
    else if(c->t  == c->maxC -1)
        c->t = -1;
    c->t++;
    c->arrClientes[c->t] = *cliente;
}

int validarEspacio(ColaCir *c){
    return !((c->h == 0 && c->t == c->maxC) || (c->t == c->h-1));

}

void listarColaCir(ColaCir *c){
    int i;
    if(validarVacio(c)){
        printf("No hay ordenes\n");
    }else if (c->h <= c->t){
        for(i = c->h; i <= c->t; i++)
            listarCliente(&c->arrClientes[i]);
    }else {
        for(i = c->h; i <= c->maxC; i++)
            listarCliente(&c->arrClientes[i]);
         for(i = 0; i <= c->t; i++)
            listarCliente(&c->arrClientes[i]);
    }
}

Cliente atender(ColaCir *c){ //borrar
    Cliente aux = c->arrClientes[c->h];
    if(c->h == c->t)
        c->h = c->t = -1;
    else{
        if(c->h == c->maxC -1 )
            c->h = -1;
        c->h ++;
    }
    return aux;
}

void preparPizza(Cliente c, int i){
    char ingredientesB[12][30] = {"Pepperoni","Masa","Jamon","Mozzarela","Tocino","Cheddar","Champiniones","Pimientos","Pinia","Jalapenio","Salsa","Tomate"};
    Pizza *aux;
    PilaIng *ingredientesP;
    aux = pop(c);
    if(aux == NULL){
        printf("No hay pedidos restantes");
    }else{
        ingredientesP = convertirPila(c);
        int j;
        for(j=0;j<6;j++){
            int ing = popIng(c, ingredientesP);
            printf("\n\tSe agrego %s", ingredientesB[ing]);
        }
        printf("\n\nLa pizza %s esta lista",c.ordpizza->arrP[i].Nombrep);
    }

}
