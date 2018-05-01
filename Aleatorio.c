#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Aleatorio.h"
#include "Estructuras.h"

CPizza *crearPizzas(){
    int i;
     CPizza *p = (CPizza*)calloc(1, sizeof(CPizza));
    p->orden=(Pizza *)calloc(5,sizeof(Pizza));
    for(i=0;i<5;i++){
    p->orden[i].Nombrep = (char *)calloc(MAXP,sizeof(char));
    p->orden[i].Ingredientes=(int *)calloc(12,sizeof(int));
    }

    return p;
}
void *crearCatalogo(CPizza *p){
    int i;
    int clave=0;
    for(i=0;i<5;i++){
        clave++;
        p->orden[i].Clave=clave;
        printf("\nIngrese el nombre de la pizza %d: \n",i+1);
        fflush(stdin);
        gets(p->orden[i].Nombrep);
        printf("\nIngrese Precio: \n");
        scanf("%f",&p->orden[i].Precio);
        ingRandom(p,i);
    }
    system("cls");
}
void listarCatalogo(CPizza *p){
        char ingredientes[12][30] = {"Pepperoni","Masa","Jamon","Mozzarela","Tocino","Cheddar","Champiniones","Pimientos","Pinia","Jalapenio","Salsa","Tomate"};
     printf("\n\tCatalogo de Pizzas\t\n");
     int i,j;
     for(i=0;i<5;i++){
            printf("\tPizza %i\t%s\t%.2f\n",p->orden[i].Clave,p->orden[i].Nombrep,p->orden[i].Precio);
            printf("\nIngredientes: ");
            for(j=0;j<6;j++){
                printf("\t%s",ingredientes[p->orden[i].Ingredientes[j]]);
            }
    printf("\n");
     }
}
void ingRandom(CPizza *p,int i){
    //srand(time(NULL));
    char ingredientes[12][30] = {"Pepperoni","Masa","Jamon","Mozzarela","Tocino","Cheddar","Champiniones","Pimientos","Pinia","Jalapenio","Salsa","Tomate"};
    int j;
    for(j=0;j<6;j++){
        p->orden[i].Ingredientes[j] = rand()%12/*ingredientes[2]*/;
    }
}
