#include<stdio.h>
#include "postfija.c"
void evaluar(COLA* expresion_postfija){
    int opcion_01;
    char info_placeholder='u',info_nodo_pila,caso;
    double a,b,c,valor_pila;
    FILE* archivo;
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
                    case('%'):
                        c = (int)a%(int)b;
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
    printf("Desea guardar el resultado en un documento de texto?\n1)Si\n2)No\n");
    scanf("%d",&opcion_01);

    while(opcion_01!=1 && opcion_01!=2){
        printf("Por favor elige una opcion valida\n");
        scanf("%d",&opcion_01);
        getchar();
    }

    if(opcion_01==1){
        archivo=fopen("postfijas.txt","a+t");
            fprintf(archivo,"El resultado es: %f",p1->head->valor);
        fclose(archivo);
        printf("El resultado ha sido guardado en el archivo postfijas.txt\n");
    }
}
