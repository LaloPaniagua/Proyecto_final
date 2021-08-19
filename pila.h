#ifndef pila_H
#define pila_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
//Definición de los aliases para nodo e info
typedef struct _nodo NODO;
typedef char INFO;


//Estructura nodo (se usará la misma estructura nodo para las pilas y para las colas)
struct _nodo{
    INFO info;
    NODO *sig;
    double valor;
    int prioridad;
    bool operador;
};

//Estructura para las pilas
typedef struct _pila PILA;
struct _pila{
    NODO *head;
    NODO *tail;
    int num;
};

//Funciones para las pilas
NODO* crear_nodo(INFO info);
void eliminar_nodo(NODO* n);
PILA* crear_pila();
bool push(PILA* l,INFO info);
bool es_vacia_pila(PILA *l);
void vaciar_pila(PILA *l);
void imprimir_pila(PILA *l);
void pop(PILA *l);
bool comparar(INFO info1, INFO info2);
INFO* first_pila(PILA* l);
#endif
