#include "evaluar.c"

int main(){ 
    FILE* archivo;
    char file[80],*token,contenido_archivo[80];
    int i,opcion_01;
    double value,valores_leidos[80];
    COLA *expresion_postfija=postfija();          
    
    printf("Desea guardar la expresion postfija en un documento de texto?\n1)Si\n2)No\n");
    scanf("%d",&opcion_01);
    
    while(opcion_01!=1 && opcion_01!=2){
        printf("Por favor elige una opcion valida\n");
        scanf("%d",&opcion_01);
        getchar();
    }

    if(opcion_01==1){
        archivo=fopen("postfijas.txt","w+t");
        for(NODO* temporal=expresion_postfija->head;temporal!=NULL;temporal=temporal->sig){
            fprintf(archivo,"%c",temporal->info);
        }
        fclose(archivo);
        printf("La expresion ha sido guardada en el archivo postfijas.txt\n");
    }

    printf("Desea leer los valores a evaluar desde un archivo?\n1)Si (Considera que los numeros en el archivo deben estar separados por una coma)\n2)No, prefiero ingresarlos desde la consola\n");
    scanf("%d",&opcion_01);

    while(opcion_01!=1 && opcion_01!=2){
        printf("Por favor elige una opcion valida\n");
        scanf("%d",&opcion_01);
        getchar();
    }
    
    if(opcion_01==2){
        for(NODO* temporal = expresion_postfija->head;temporal!=NULL;temporal=temporal->sig){
            if(temporal->operador==false) {
                printf("Ingrese el valor correspondiente a %c:\n",temporal->info);
                scanf("%lf",&value);
                temporal->valor=value;
            }
        }
    }

    else if(opcion_01==1){
        printf("Ingresa el nombre del archivo a leer:\n");
        scanf("%s",&file);
        archivo=fopen(file,"r+t");
        while (archivo==NULL)
        {
            printf("El archivo ingresado no existe, por favor intente de nuevo\n");
            scanf("%s",&file);
            getchar();
            archivo=fopen(file,"r+t");
        }
        i=0;
        fscanf(archivo,"%s",&contenido_archivo);
        fclose(archivo);
        token=strtok(contenido_archivo,",");
        printf("%s\n",token);
        if (token!=NULL)
        {
            while (token!=NULL)
            {
                valores_leidos[i]=atof(token);
                token=strtok(NULL,",");
                i++;
            }
            
        }
        
        i=0;
        for(NODO* temporal = expresion_postfija->head;temporal!=NULL;temporal=temporal->sig){
            if(temporal->operador==false) {
                temporal->valor=valores_leidos[i];
                i++;
            }
        }
    }

    printf("Valores leidos: \n");
    for(NODO* temporal = expresion_postfija->head;temporal!=NULL;temporal=temporal->sig){
            if(temporal->operador==false) {
                printf("%c %f\n",temporal->info,temporal->valor);
            }
        }
    printf("\n");



    printf("Expresion a evaluar: ");
    imprimir_cola(expresion_postfija);
    evaluar(expresion_postfija);
    getchar();
    getchar(); 
    return EXIT_SUCCESS;
}
