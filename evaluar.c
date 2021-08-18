#include "postfija.c"
void evaluar(COLA* expresion_postfija){
    char info_placeholder='u',info_nodo_pila,caso;
    double a,b,c,valor_pila;
    PILA* p1=crear_pila();
    for(NODO* temporal = expresion_postfija->head;temporal!=NULL;temporal=temporal->sig){
            
            if(temporal->operador==false){
                info_nodo_pila=temporal->info;
                valor_pila=temporal->valor;
                push(p1,info_nodo_pila);
                p1->head->valor=valor_pila;
            }
            else{
                b=p1->head->valor;
                pop(p1);
                a=p1->head->valor;
                pop(p1);
                caso=temporal->info;
                switch(caso){
                    case('+'):
                        c=a+b;
                        push(p1,info_placeholder);
                        p1->head->valor=c;
                        break;
                    case('-'):
                        c=a-b;
                        push(p1,info_placeholder);
                        p1->head->valor=c;
                        break;
                    case('*'):
                        c=a*b;
                        push(p1,info_placeholder);
                        p1->head->valor=c;
                        break;
                    case('/'):
                        c=a/b;
                        push(p1,info_placeholder);
                        p1->head->valor=c;
                        break;
                    case('^'):
                        c=pow(a,b);
                        push(p1,info_placeholder);
                        p1->head->valor=c;
                        break;
                }
            }
        }

    printf("El resultado final es: %f\n",p1->head->valor);
}