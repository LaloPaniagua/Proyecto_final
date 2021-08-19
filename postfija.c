#include "pila.c"
#include "cola.c"
//Función para discernir entre operadores y operandos.
bool esOperador(char x){
    char operadores[7]={'(','^','*','/','+','-','%'};
    if (x == operadores[0] || x==operadores[1] || x==operadores[2] || x==operadores[3] || x==operadores[4] || x==operadores[5]|| x==operadores[6])
        return true;
    return false;
}

COLA* postfija(){
    char s[80]; //Arreglo donde se almacena la expresion infija.
    PILA *p1 = crear_pila(); 
    COLA *expresion_postfija=crear_cola();          
    printf("Por favor ingrese una expresion infija:\n");
    scanf("%s",s);
    //Se obtiene el tamaño de la cadena para usarlo en el ciclo for.
    int size = strlen(s);
    for(int i=0;i<size;i++){
        //Si es operando, se pasa directamente a la cola.
        if(esOperador(s[i])==false  && s[i] != ')'){
            enqueue(expresion_postfija,s[i]);
        }
        //Si es operador y la pila esta vacia, se apila.
        else if (esOperador(s[i])){
            if(es_vacia_pila(p1)) push(p1,s[i]);
            else{
                //Si la prioridad del operador es mayor al del primer elemento de la pila, se apila.
                NODO* temporal=crear_nodo(s[i]);
                if (temporal->prioridad > p1->head->prioridad || temporal->prioridad==6){
                    push(p1,s[i]);
                }
                else{
                    //Si la prioridad es menor o igual, se pasa el primer elemento a la cola y se repite.
                    while(p1->head != NULL && temporal->prioridad <= p1->head->prioridad && p1->head->info != '('){
                        enqueue(expresion_postfija,p1->head->info);
                        pop(p1);
                    }
                    push(p1,temporal->info);
                }
            }
        }
        //Si es un ')', se pasan todos los operadores de la pila hasta encontrar '('
        else if(s[i] == ')'){
            while(p1->head->info != '('){
                enqueue(expresion_postfija,p1->head->info);
                pop(p1);
            }
        }
    }
    //Si quedan operadores, se pasan a la cola.
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
    //Impresion de la expresion postfija.
    printf("expresion postfija: ");
    imprimir_cola(expresion_postfija);
    printf("\n");
    return expresion_postfija;
}
//Creado por Eduardo Paniagua, Diego Barragán, Jhusteene Salgado y Alejandra Avila en 14/08/2021.
