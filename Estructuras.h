#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

typedef struct{
   char *Nombrep;
    int Clave;
    float Precio;
    int *Ingredientes;
}Pizza;

typedef struct{
    int tope;
    int max;
    Pizza *arrP;
}Pila;

typedef struct{
    int tope;
    int max;
    int *ingredientes;
}PilaIng;

typedef struct{
    int Orden;
    char *NombreC;
    int CantMax;
    Pila *ordpizza;
    float Total;
}Cliente;



typedef struct{
 Pizza *orden;
}CPizza;

typedef struct{
    Cliente *arrClientes;
    int h, t, maxC;
}ColaCir;


#endif // ESTRUCTURAS_H_INCLUDED
