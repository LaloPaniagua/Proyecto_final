#ifndef cola_H
#define cola_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"pila.h"
typedef struct _cola COLA;
struct _cola{
    NODO *head;
    NODO *tail;
    int num;
};


NODO* crear_nodo(INFO info);
void eliminar_nodo(NODO* n);
COLA* crear_cola();
bool enqueue(COLA* l,INFO info);
bool es_vacia_cola(COLA *l);
void vaciar_cola(COLA *l);
void imprimir_cola(COLA *l);
void dequeue(COLA *l);
bool comparar(INFO info1, INFO info2);
NODO* first_cola(COLA* l);
#endif