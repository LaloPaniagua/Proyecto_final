#include "evaluar.c"

int main(){ 
    FILE* archivo;
    char file[80],*token,contenido_archivo[80];
    int i,opcion_01;
    double value,valores_leidos[80];
    
    //Ejecución de la función para generar una expresión postfija
    COLA *expresion_postfija=postfija();          
    
    
    //Menú para elegir si guardar o no la expresión postfija en un documento de texto
    printf("Desea guardar la expresion postfija en un documento de texto?\n1)Si\n2)No\n");
    scanf("%d",&opcion_01);
    
    while(opcion_01!=1 && opcion_01!=2){
        printf("Por favor elige una opcion valida\n");
        scanf("%d",&opcion_01);
        getchar();
    }

    //Guardado de la expresión en el archivo postfijas.txt
    if(opcion_01==1){
        archivo=fopen("postfijas.txt","w+t");
        for(NODO* temporal=expresion_postfija->head;temporal!=NULL;temporal=temporal->sig){
            fprintf(archivo,"%c",temporal->info);
        }
        fprintf(archivo,"\n");
        fclose(archivo);
        printf("La expresion ha sido guardada en el archivo postfijas.txt\n");
    }
    
    //Se le pregunta al usuario si desea leer los valores a evaluar de un archivo
    printf("Desea leer los valores a evaluar desde un archivo?\n");
    printf("1)Si (Considera que los numeros en el archivo deben estar separados por una coma)\n2)No, prefiero ingresarlos desde la consola\n");
    scanf("%d",&opcion_01);

    while(opcion_01!=1 && opcion_01!=2){
        printf("Por favor elige una opcion valida\n");
        scanf("%d",&opcion_01);
        getchar();
    }
    
    
    //El usuario ingresa los valores a evaluar
    if(opcion_01==2){
        for(NODO* temporal = expresion_postfija->head;temporal!=NULL;temporal=temporal->sig){
            if(temporal->operador==false) {
                printf("Ingrese el valor correspondiente a %c:\n",temporal->info);
                scanf("%lf",&value);
                temporal->valor=value;
            }
        }
    }

    //Se le pide al usuario ingresar el nombre del archivo a leer
    else if(opcion_01==1){
        printf("Ingresa el nombre del archivo a leer:\n");
        scanf("%s",&file);
        //Apertura del archivo a leer
        archivo=fopen(file,"r+t");
        while (archivo==NULL)
        {
            printf("El archivo ingresado no existe, por favor intente de nuevo\n");
            scanf("%s",&file);
            getchar();
            archivo=fopen(file,"r+t");
        }
        i=0;
        //Lectura del contenido del archivo
        fscanf(archivo,"%s",&contenido_archivo);
        fclose(archivo);
        //Separación de los números contenidos en la cadena leída
        token=strtok(contenido_archivo,",");
        printf("%s\n",token);
        if (token!=NULL)
        {
            while (token!=NULL)
            {
                valores_leidos[i]=atof(token);//Conversión de cadena a flotante
                token=strtok(NULL,",");
                i++;
            }
            
        }
        
        i=0;
        //Asignación de valores a cada uno de los operandos de la expresión postfija
        for(NODO* temporal = expresion_postfija->head;temporal!=NULL;temporal=temporal->sig){
            if(temporal->operador==false) {
                temporal->valor=valores_leidos[i];
                i++;
            }
        }
    }

    //Impresión de los valores leídos
    printf("Valores leidos: \n");
    for(NODO* temporal = expresion_postfija->head;temporal!=NULL;temporal=temporal->sig){
            if(temporal->operador==false) {
                printf("%c %f\n",temporal->info,temporal->valor);
            }
        }
    printf("\n");
    printf("Desea guardar los valores en un documento de texto?\n1)Si\n2)No\n");
    scanf("%d",&opcion_01);

    while(opcion_01!=1 && opcion_01!=2){
        printf("Por favor elige una opcion valida\n");
        scanf("%d",&opcion_01);
        getchar();
    }

    //Guardado de los valores en el documento valores.txt
    if(opcion_01==1){
        archivo=fopen("valores.txt","a+t");
        for(NODO* temporal = expresion_postfija->head;temporal!=NULL;temporal=temporal->sig){
            if(temporal->operador==false) {
                fprintf(archivo,"%c %f\n",temporal->info,temporal->valor);
            }
        }
    printf("\n");
        fclose(archivo);
        printf("Los valores han sido guardados en el archivo valores.txt\n");
    }

    printf("Expresion a evaluar: ");
    imprimir_cola(expresion_postfija);
    evaluar(expresion_postfija);//Evaluación de la expresión postfija
    getchar();
    getchar(); 
    return EXIT_SUCCESS;
}
