#include <stdio.h>
#include <string.h>
//librerias usadas para el programa

struct trabajador //estructura la cual se va utilizar para el programa
{
    char nombre[50];
    float sueldo;
    float sueldofinal;

};

int main(){
//variables que se usaran dentro del programa
int opcion;
int num;
int aux;
int aux1;
float aux2;
FILE*archivo;//puntero hacia el archivo 

printf("Coloque el numero de empleados que desee ingresar\n");
scanf("%d",&num);

struct trabajador trabajadores[num];//estructura echo vector

do
{
    printf("\nOpcion 1. Ingresar datos de trabajadores\n");
    printf("Opcion 2. Mostrar los trabajadores\n");
    printf("Opcion 3. Salir\n");
    scanf("%d", &opcion);//opciones las cuales el usuario va a poder escojer para realizar diferentes actividades
    
    switch (opcion)//switch para navegar por las diferentes opciones que tiene el menu
    {
    case 1:
    for (int i = 0; i < num; i++)
    {
        printf("Datos del trabajador %d:\n", i+1);
//se ingresan los diferentes datos del trabajador 
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(trabajadores[i].nombre);

        printf("Ingrese el sueldo: ");
        fflush(stdin);
        scanf("%f", &trabajadores[i].sueldo);
        printf("Solo se puede escoger entre trabajar horas extra entre semana o fin de semana y feriados\n");
        printf("Coloque 1 si trabajo horas extra entre semana\n");
        printf("Coloque 2 si trabajo horas extra fin de semana y feriados\n");
        printf("Coloque 3 si no trabajo horas extra\n");
        scanf("%d", &aux);

        if (aux==1)//if para saber cuales horas extras trabajo 
        {
            printf("Coloque cuantas horas extras trabajo\n");
            scanf("%d",&aux1);
            if (aux1<48){//if para que el trabajador no puede trabajar mas de 48 horas extras
            trabajadores[i].sueldofinal=trabajadores[i].sueldo/240;
            aux2=trabajadores[i].sueldofinal;
            trabajadores[i].sueldofinal=trabajadores[i].sueldofinal*0.50;
            trabajadores[i].sueldofinal=trabajadores[i].sueldofinal+aux2;
            trabajadores[i].sueldofinal=trabajadores[i].sueldofinal*aux1;
            trabajadores[i].sueldofinal=trabajadores[i].sueldofinal+trabajadores[i].sueldo;
            printf("Datos guardados en el archivo 'trabajadores.txt'.\n");
            }
            else{
                printf("No se puede colocar mas de 48 horas\n");
            }



        }
        else if (aux==2)
        {
            printf("Coloque cuantas horas extras trabajo\n");
            scanf("%d",&aux1);
            if(aux1<48){//if para que el trabajador no puede trabajar mas de 48 horas extras
            trabajadores[i].sueldofinal=trabajadores[i].sueldo/240;
            aux2=trabajadores[i].sueldofinal;
            trabajadores[i].sueldofinal=trabajadores[i].sueldofinal+aux2;
            trabajadores[i].sueldofinal=trabajadores[i].sueldofinal*aux1;
            trabajadores[i].sueldofinal=trabajadores[i].sueldofinal+trabajadores[i].sueldo;
            printf("Datos guardados en el archivo 'trabajadores.txt'.\n");
            }
            else {
            printf("No se puede colocar mas de 48 horas\n");

            }


        }
        else if (aux==3)
        {
        // ultimo if el cual sirve para controlar cuando no trabajo ninguna hora extra
            trabajadores[i].sueldofinal=trabajadores[i].sueldo;
        }
        
        

        archivo = fopen("trabajadores.txt", "w");//se habre el archivo en modo de escritura 
        for (int i = 0; i < num; i++)//bucle for para imprimir los trabajadores ingresados 
        {
            fprintf(archivo, "\nTrabajador %d:\t", i +1);
            fprintf(archivo, "%s\t", trabajadores[i].nombre);
            fprintf(archivo, "%f\t", trabajadores[i].sueldo);
            fprintf(archivo, "%f\t", trabajadores[i].sueldofinal);

        }
        fclose(archivo); //se cierra el archivo
    }
    

        break;
    case 2://case que se usa para poder mostrar en pantalla los datos de los trabajadores
    for (int i = 0; i < num; i++)
    {
    printf("\nTrabajador %d:\t", i +1);
    printf("%s\t", trabajadores[i].nombre);
    printf("%f\t", trabajadores[i].sueldo);
    printf("%f\t", trabajadores[i].sueldofinal);

    }
    
   
    }
} while (opcion !=3);


}