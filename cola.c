#include"cola.h"

COLA* crear_cola(){
    COLA* l=(COLA*)malloc(sizeof(COLA));
    l->head=l->tail=NULL;
    l->num=0;
    return l;
}

bool es_vacia_cola(COLA *l){
    if(l->head==NULL && l->tail==NULL) return true;
    else return false;
}

void vaciar_cola(COLA *l){
    if(es_vacia_cola(l)) return;
    NODO* temporal = l->head;
    while(temporal != NULL){
        l->head=l->head->sig;
        temporal->sig=NULL;
        eliminar_nodo(temporal);
        temporal=l->head;
        l->num--;
    }
}

void imprimir_cola(COLA *l){
    for(NODO* t=l->head;t != NULL;t=t->sig){
            printf("%c",t->info);
    }
    printf("\n");
}


NODO* first_cola(COLA* l){
    if(es_vacia_cola(l)) return NULL;
    return l->head;
}

bool comparar_cola(INFO info1, INFO info2){
    if(info1==info2) return true;
    return false;
}
//En este caso, se inserta por el final.
bool enqueue(COLA* l,INFO info){
    NODO* nuevo=crear_nodo(info);
    if(l->head==NULL  && l->tail==NULL){
        l->head=l->tail=nuevo;
        l->num++;
        return true;
    }
    else{
        l->tail->sig = nuevo;
        l->tail = nuevo;
        l->num++;
        return true;
    }
    return false;
}
//Se elimina por el principio.
void dequeue(COLA *l){
    if(es_vacia_cola(l)) return;
    else if(l->head==l->tail){
        eliminar_nodo(l->head);
        l->num--;
    }
    else{
        NODO *temporal = l->head;
        l->head = l->head->sig;
        temporal->sig = NULL;
        eliminar_nodo(temporal);
        l->num--;  
    }
}
