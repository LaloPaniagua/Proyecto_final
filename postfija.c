#include "pila.c"
#include "cola.c"
bool esOperador(char x){
    char operadores[7]={'(','^','*','/','+','-','%'};
    if (x == operadores[0] || x==operadores[1] || x==operadores[2] || x==operadores[3] || x==operadores[4] || x==operadores[5]|| x==operadores[6])
        return true;
    return false;
}

COLA* postfija(){
    char s[80];
    PILA *p1 = crear_pila(); 
    COLA *expresion_postfija=crear_cola();          
    printf("Por favor ingrese una expresion infija:\n");
    scanf("%s",s);
    int size = strlen(s);
    for(int i=0;i<size;i++){
        if(esOperador(s[i])==false  && s[i] != ')'){
            enqueue(expresion_postfija,s[i]);
        }
        else if (esOperador(s[i])){
            if(es_vacia_pila(p1)) push(p1,s[i]);
            else{
                NODO* temporal=crear_nodo(s[i]);
                if (temporal->prioridad > p1->head->prioridad || temporal->prioridad==6){
                    push(p1,s[i]);
                }
                else{ 
                    while(p1->head != NULL && temporal->prioridad <= p1->head->prioridad && p1->head->info != '('){
                        enqueue(expresion_postfija,p1->head->info);
                        pop(p1);
                    }
                    push(p1,temporal->info);
                }
            }
        }
        else if(s[i] == ')'){
            while(p1->head->info != '('){
                enqueue(expresion_postfija,p1->head->info);
                pop(p1);
            }
        }
    }
    
    if(es_vacia_pila(p1)==false){
        while(p1->head != NULL){
            if(p1->head->info!='(' && p1->head->info!=')'){
                enqueue(expresion_postfija,p1->head->info);
            }
            pop(p1);
        }
        pop(p1);
    }
    vaciar_pila(p1);

    printf("expresion postfija: ");
    imprimir_cola(expresion_postfija);
    printf("\n");
    return expresion_postfija;
}
