#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <fcntl.h>
#include "practica4.h"

int main(int argc, char *argv[])
{
        int myfd;


	if(!(((argc == 3) && (*argv[2] == 'p')) || (argc ==2)) ){
                printf("Argumentos incorrectos. Uso:\n");
                printf("%s <results fifo> [<p>ermanente}\n", argv[0]);
                return 1;
        }
	

        char *results_fifo = argv[1];

	do{ //hay que hacerlo con do while ya que asi, aun que no se cumpla la condicion entra una vez, "primero dispara, luego pregunta"
        //abrimos
        myfd = open(results_fifo, O_RDONLY);


        //llamamos a la funcion gatherer del ejercicio anterior
        gatherer(myfd);

        //cerramos
        close(myfd);
	}while(argv[2] != NULL);

        return 0;

}

