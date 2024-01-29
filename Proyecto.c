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

