#include <stdio.h>
#include <string.h>

struct trabajador
{
    char nombre[50];
    float sueldo;
    float sueldofinal;
    int horas1;
    int horas2;
};

int main(){

int opcion;
int num;
int aux;
int aux1;
float aux2;
FILE*archivo;

printf("Coloque el numero de empleados que desee ingresar\n");
scanf("%d",&num);

struct trabajador trabajadores[num];

do
{
    printf("\nOpcion 1. Ingresar datos de trabajadores\n");
    printf("Opcion 2. Mostrar los trabajadores\n");
    printf("Opcion 3. Salir\n");
    scanf("%d", &opcion);
    
    switch (opcion)
    {
    case 1:
    for (int i = 0; i < num; i++)
    {
        printf("Datos del trabajador %d:\n", i+1);

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



        }
        else if (aux==3)
        {
        
            trabajadores[i].sueldofinal=trabajadores[i].sueldo;
        }
        
        

        archivo = fopen("trabajadores.txt", "w");
        for (int i = 0; i < num; i++)
        {
            fprintf(archivo, "\nTrabajador %d:\t", i +1);
            fprintf(archivo, "%s\t", trabajadores[i].nombre);
            fprintf(archivo, "%f\t", trabajadores[i].sueldo);
            fprintf(archivo, "%f\t", trabajadores[i].sueldofinal);

        }
        fclose(archivo); 
    }
    

        break;
    case 2:
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