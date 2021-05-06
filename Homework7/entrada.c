#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    header();
    int i;
    int j;
    int pintemporal;
    matrix = (int**)malloc(sizeof(int*) * USUARIOS);
    for (i = 0; i < USUARIOS; i ++){
            matrix[i] = (int*)malloc(sizeof(int) * 6);
            for (j=0; j<6; j++){
            matrix[i][j]=-1;
            }
    }
    int salir=0;
    int opcion=0;
    while(salir==0){
        int limite;
        limite=count();
      printf("\n so we've %d registered workers\n", limite);
        printf("FIRST YOU HAVE TO USE OPTION 3: REGISTER A WORKER, then you can do the rest*");
        printf("\nType\n1 To register an entery \n2 To register an exit\n3 To register a worker\n4 To finish\n");
        scanf("%d", &option);
        if (option==1){ 
        printf("Please, enter your pin\n");
        scanf("%d", &temporalpin);
        if (temporalpin<=0){
            printf("Type a valid entry\n");
        }
             else if (temporalpin<=limit){
                if (matrix[temporalpin-1][1]==-1){ 
                    hiorbye(temporalpin, 0);
                }
                else{
                    printf("you have already registered your entry\n");
                }
            }
            else{
                printf("There are %d workers. Invalid pin\n", limit);
            }
        }
        else if (option==2){   
        printf("Please, type your pin\n");
        scanf("%d", &temporalpin);
        }
        else if (opcion==2){
            
        printf("Cual es su pin?\n");
        scanf("%d", &pintemporal);
        
        if (pintemporal<=0){
            printf("Entrada no valida\n");
        }
        
            else if (pintemporal<=limite){
                if (entrada[pintemporal-1][1]!=-1){
                    entradaosalida(pintemporal, 1);
                }
                else{
                    printf("Para registrar una salida debio registrarse una entrada\n");
                }
            }
            else{
                printf("En este momento hay %d trabajadores no puedes poner ese pin\n", limite);
            }
        }
        else if (opcion==3){
            registrar();
        }
        else if (opcion==4){
            int flag=0;
            for (i=0; i<MAX; i++){
                if(matrix[i][0]*matrix[i][1]*matrix[i][2]>0&&matrix[i][3]*matrix[i][4]*matrix[i][5]<0){
                    flag=-1; 
            }
            if (flag==0){
            horario();
            printf("Have a Good day\n");
            salir=1;
            }
        }
        else{
            printf("Opcion no disponible\n\n");
        }
    }
    return 0;
}

int count(){
    FILE* sistema = fopen("sistema.txt", "r");
    char c;
    int count=0;
    while ((c = fgetc(sistema)) != EOF) {
    if (c == '\n') {
      count++;
    }
    }
    
    return count;
}

void registrar(){
    int pin;
    pin=count()+1;
    char user[MAX];
    int sunday;
    int monday;
    int tuesday;
    int wednesday;
    int thursday;
    int friday;
    int saturday;
    int hour;
    int min;
    int trabajo;
    printf("The pin of this person is <%d>\n", pin);
    registrados++;
    printf("What is the name?\n");
    scanf("%s", user);
   
    do {
        printf("\nEscriba a que hora y minuto trabajara (separados con un espacio)\n");
        printf("Un ejemplo: 20 30\n");
        scanf("%d %d", &hour, &min);
    } while(hour<0||hour>23||min<0||min>60);
        
    do {
        printf("\nCuantos segundos trabajara (un numero entre 1 y 60)\n");
        scanf("%d", &trabajo);
    }while(trabajo<=0||trabajo>60);
    printf("Registro exitoso\n\n");
    
    FILE* escribirsistema = fopen("sistema.txt", "a");
    fprintf(escribirsistema, "%d %s %d %d %d %d %d %d %d %d %d %d\n",pin, user, sunday, monday, tuesday, wednesday, thursday, friday, saturday, hour, min, trabajo);
    fclose(escribirsistema);
}

void entradaosalida(int pin, int estado){
    int diferencia=0; 
    time_t tiempoahora;
    time(&tiempoahora);
    struct tm *mitiempo = localtime(&tiempoahora);
    int actualsec=mitiempo->tm_sec;
    int actualmin=mitiempo->tm_min;
    int actualhora=mitiempo->tm_hour;
    int actualyear=mitiempo->tm_year+1900;
    int actualmes=mitiempo->tm_mon+1;
    int actualdia=mitiempo->tm_mday;
    int actualwdia=mitiempo->tm_wday;
    if (estado==0){ //es una entrada
    FILE* entrada = fopen("entradas.txt", "a");
    fprintf(entrada, "%d %d %d/%d/%d %d:%d:%d\n", pin, actualwdia, actualdia, actualmes, actualyear, actualhora, actualmin, actualsec);
    fclose(entrada);
    matrix[pin-1][0]=actualhora;
    matrix[pin-1][1]=actualmin;
    matrix[pin-1][2]=actualsec;
    printf("Entrada registrada\n");
    }
    if (estado==1){
    FILE* salida = fopen("salidas.txt", "a"); 
    fprintf(salida, "%d %d %d/%d/%d %d:%d:%d\n", pin, actualdia, actualmes, actualyear, actualhora, actualmin, actualsec);
    fclose(salida);
    printf("Salida registrada\n");
    matrix[pin-1][3]=actualhora;
    matrix[pin-1][4]=actualmin;
    matrix[pin-1][5]=actualsec;
    FILE* reporte = fopen("reporte.txt", "a");
    if (totaldesalidas==0){
        fprintf(reporte, "Reporte generado el "); 
            switch(actualwdia){
                case 0:
                fprintf(reporte, "Sunday");
                break;
                case 1:
                fprintf(reporte, "Monday");
                break;
                case 2:
                fprintf(reporte, "Tuesday");
                break;
                case 3:
                fprintf(reporte, "Wednesday");
                break;
                case 4:
                fprintf(reporte, "Thursday");
                break;
                case 5:
                fprintf(reporte, "Friday");
                break;
                case 6:
                fprintf (reporte, "Saturday");
                break;
            }
        fprintf(reporte, " %d/%d/%d\n", actualdia, actualmes, actualyear);
    }
    
    diferencia=(matrix[pin-1][3]*3600+matrix[pin-1][4]*60+matrix[pin-1][5])-(matrix[pin-1][0]*3600+matrix[pin-1][1]*60+matrix[pin-1][2]);
    int horapin=matrix[pin-1][0];
    int minpin=matrix[pin-1][1];
    int segundopin=matrix[pin-1][2];                                                    
    fprintf(reporte, "El trabajador con el pin <%d> entro a la hora: <%d:%d:%d> el dia: <%d/%d/%d> trabajo %d segundos\n", pin, horapin, minpin, segundopin, actualdia, actualmes, actualyear, diferencia);
    fclose(reporte);
    matrix[pin-1][0]=-1;
    matrix[pin-1][1]=-1;
    matrix[pin-1][2]=-1;
    matrix[pin-1][3]=-1;
    matrix[pin-1][4]=-1;
    matrix[pin-1][5]=-1;
    
    totaldesalidas=9;
    }
}
void header(){
    time_t tiempoahora;
    time(&tiempoahora);
    struct tm *mitiempo = localtime(&tiempoahora);
    switch(mitiempo->tm_wday){
        case 0:
        printf("Today is Sunday\n");
        break;
        case 1:
        printf("Today is Monday\n");
        break;
        case 2:
        printf("Tday is Tuesday\n");
        break;
        case 3:
        printf("Today is Wednesday\n");
        break;
        case 4:
        printf("Today is Thursday\n");
        break;
        case 5:
        printf("Today is Friday\n");
        break;
        case 6:
        printf ("Today is Saturday\n");
        break;
    }
    printf("Day: %d/%d/%d\n", mitiempo->tm_mday, mitiempo->tm_mon+1, mitiempo->tm_year+1900);
    printf("Hour: %d:%d\n", mitiempo->tm_hour, mitiempo->tm_min);
}
void horario(){
    time_t tiempoahora;
    time(&tiempoahora);
    int pinleido;
    char usuarioleido[MAX];
    int domingohorario;
    int luneshorario;
    int marteshorario;
    int miercoleshorario;
    int jueveshorario;
    int vierneshorario;
    int sabadohorario;
    int horaleida;
    int minutoleido;
    int trabajo;
    int i;
   
    char c;
  while (fscanf(readgo, "%d %s %d %d %d %d %d %d %d %d %d %d\n", &pinleido, usuarioleido, &sundayhorario, &mondayhorario, &tuesdayhorario, &wednesdayhorario, &thursdayhorario, &fridayhorario, &saturdayhorario, &horaleida, &minutoleido, &trabajo) == 12) {
    fprintf(writehorario, "User <%s> with the pin <%d>, must enter at: %d:%d, must work for <%d seconds> the days:\n", usuarioleido, pinleido,horaleida, minutoleido, trabajo);
    if (sundayhorario==1)
    fprintf(writehorario, "Sunday ");
    if (mondayhorario==1)
    fprintf(writehorario, "Monday ");
    if (tuesdayhorario==1)
    fprintf(writehorario, "Tuesday ");
    if (wednesdayhorario==1)
    fprintf(writehorario, "Wednesday ");
    if (thursdayhorario==1)
    fprintf(writehorario, "Thursday ");
    if (fridayhorario==1)
    fprintf(writehorario, "Friday ");
    if (saturdayhorario==1)
    fprintf(writehorario, "Saturday ");
    
    fprintf(writehorario, "\n\n");    
    }
