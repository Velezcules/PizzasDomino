#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<string.h>
#include "Cliente.h"
#include "Pila.h"
#include "Aleatorio.h"

Cliente *crearCliente(){

    Cliente *cliente = (Cliente *)calloc(1,sizeof(Cliente));
    cliente->NombreC = (char *)calloc(30,sizeof(char));

    return cliente;
}
void llenarCliente(Cliente *c,CPizza *p,int numOrd){
    int i,opPizza;
    //char nombres[10][20] = {"Luis","Emmanuel","Ivan","Nestor","Alex","Paty","Fernanda","Lilian","Ana","Paola"};
    system("cls");

    printf("Cuántas pizzas quieres?");
    scanf("%d", &c->CantMax);
    c->ordpizza = crearPila(c->CantMax);
    c->Orden = numOrd;
    strcpy(c->NombreC,"Juan");//c->NombreC = nombres[7];  //Cambiar a random
    listarCatalogo(p);
    printf("\nSeleccione %d pizzas: ",c->CantMax);
    for(i=0; i<c->CantMax; i++){
        printf("\nOpcion: ");
        scanf("%d",&opPizza);
        opPizza--;
        Push(c->ordpizza,opPizza,p);
    }
}
void listarCliente(Cliente *c){
    printf("\nOrden:%i\t\tNombre: %s\t\tCantidad: %d\n ",c->Orden,c->NombreC,c->CantMax);
    listarOrden(c); //Lista las pizzas que selecciono el cliente

}
void listarOrden(Cliente *c){
    int otroi;
    char aux[30];
    otroi = c->ordpizza->tope;
    float total = 0;
    do{
        //otroi--;
        strcpy(aux,c->ordpizza->arrP[otroi].Nombrep);
        total = total + c->ordpizza->arrP[otroi].Precio;
        printf("\t%s",aux);
        otroi--;
    }while(otroi != -1);
    c->Total = total;
    printf("\n\tPrecio total: %0.2f", c->Total);

printf("\n");
}
