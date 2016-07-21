#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <string.h>

/* cd Dropbox/Universidad/3º\ Semestre/Programación\ para\ Sistemas/Tema\ 2\ -\ Programación\ en\ C/Ficheros/ */

/* gcc -g -Wall -ansi -pedantic -o secuencia secuencia.c */

int main ( int argc, char *argv[], char *envp[]) {

        /* Datos del argv[] */

        double hasta = 10;
        double desde = 1;
        double paso = 1;

        /* Variables Auxiliares */
        
        double number = 1;
        int counter = 0;
        double maximo;

        /* Variable de Entorno MAX_OUTPUT */

        if(getenv("MAX_OUTPUT") == NULL){
            maximo = 100;
        }
        else{
            maximo = atof(getenv("MAX_OUTPUT"));
        }

        if(maximo < 0 || strlen(getenv("MAX_OUTPUT")) == 0){
            maximo = 100;
        }

        /*
        const char *cadena = "-1234567abc";     inicializa el apuntador cadena
        char *ptrResto;                         crea una apuntador char
        long x;                                 variable para almacenar la secuencia convertida 
        x = strtol( cadena, &ptrResto, 0 );
        */

        /* Caso de secuencia sin datos */

        if(argv[1] == NULL){

            number = desde;

            while(number <= hasta && counter < maximo){
                printf("\t%g\n", number);
                number = number + paso;
                counter++;
            }

            if(counter == maximo){

                fprintf (stderr, "secuencia: Error(EX_NOPERM), permiso denegado. \"Success\". \n");
                fprintf (stderr, "secuencia+ Se intento superar el limite de salida.\n");
                exit(EX_NOPERM);
            }
  
        }

        /* Caso de -h y --help */

        else if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
                printf ("secuencia: Uso: secuencia [ hasta [ desde [ paso ]]]\n");
                printf ("secuencia: Genera la secuencia de numeros en el intervalo y paso indicados\n");
        }

        /* Caso de un argumento valido */

        else if(argv[1] != NULL && argv[2] == NULL){

            number = desde;
            hasta = atof(argv[1]);

            while(number <= hasta && counter < maximo){
                printf("\t%g\n", number);
                number = number + paso;
                counter++;
            }
            
            if(counter == maximo){
                fprintf (stderr, "secuencia: Error(EX_NOPERM), permiso denegado. \"Success\". \n");
                fprintf (stderr, "secuencia+ Se intento superar el limite de salida.\n");
                exit(EX_NOPERM);
            }
            
        }

        /* Caso de dos argumentos valido */

        else if(argv[1] != NULL && argv[2] != NULL && argv[3] == NULL){

            hasta = atof(argv[1]);
            desde = atof(argv[2]);
            number = desde;

            if(desde < hasta){

                while(number <= hasta && counter < maximo){
                    printf("\t%g\n", number);
                    number = number + paso;
                    counter++;
                }

                if(counter == maximo){

                    fprintf (stderr, "secuencia: Error(EX_NOPERM), permiso denegado. \"Success\". \n");
                    fprintf (stderr, "secuencia+ Se intento superar el limite de salida.\n");
                    exit(EX_NOPERM);
                }

            }

            else{

                while(number >= hasta && counter < maximo){
                    printf("\t%g\n", number);
                    number = number + paso;
                    counter++;
                }

                if(counter == maximo){

                    fprintf (stderr, "secuencia: Error(EX_NOPERM), permiso denegado. \"Success\". \n");
                    fprintf (stderr, "secuencia+ Se intento superar el limite de salida.\n");
                    exit(EX_NOPERM);
                }
            }

        }

        /* Caso de tres argumentos validos */

        else if(argv[1] != NULL && argv[2] != NULL && argv[3] != NULL && argv[4] == NULL){

            hasta = atof(argv[1]);
            desde = atof(argv[2]);
            number = desde;
            paso = atof(argv[3]);

            if(paso == 0){
                
                fprintf (stderr, "secuencia: Error(EX_USAGE), uso incorrecto del mandato. \"Success\". \n");
                fprintf (stderr, "secuencia+ El parametro \"paso\" no puede valer 0.\n");
                exit(EX_USAGE);
            }

            if((hasta > desde && paso < 0) || (hasta < desde && paso > 0)){

                fprintf (stderr, "secuencia: Error(EX_USAGE), uso incorrecto del mandato. \"Success\". \n");
                fprintf (stderr, "secuencia+ El signo de \"paso\" no permite recorrer el intervalo en el sentido \"desde\" a \"hasta\".\n");
                exit(EX_USAGE);
            }

            if(desde < hasta){

                while(number <= hasta && counter < maximo){
                    printf("\t%g\n", number);
                    number = number + paso;
                    counter++;
                }

                if(counter == maximo){

                    fprintf (stderr, "secuencia: Error(EX_NOPERM), permiso denegado. \"Success\". \n");
                    fprintf (stderr, "secuencia+ Se intento superar el limite de salida.\n");
                    exit(EX_NOPERM);
                }
            }

            else{

                while(number >= hasta && counter < maximo){
                    printf("\t%g\n", number);
                    number = number + paso;
                    counter++;
                }

                if(counter == maximo){

                    fprintf (stderr, "secuencia: Error(EX_NOPERM), permiso denegado. \"Success\". \n");
                    fprintf (stderr, "secuencia+ Se intento superar el limite de salida.\n");
                    exit(EX_NOPERM);
                }
            }

        }

        /* Caso de cuatro argumentos */

        else if(argv[1] != NULL && argv[2] != NULL && argv[3] != NULL && argv[4] != NULL && argv[5] == NULL){

            fprintf (stderr, "secuencia: Error(EX_USAGE), uso incorrecto del mandato. \"Success\". \n");
            fprintf (stderr, "secuencia+ El numero de argumentos no es correcto.\n");
            exit(EX_USAGE);

        }

        exit(EX_OK);

        
}

