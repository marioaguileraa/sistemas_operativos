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
        int pipe, pipe2;
	
	/*
        if(argc != 3){
                printf("Argumentos incorrectos. Uso:\n");
                printf("%s <work fifo> <results fifo>\n", argv[0]);
                return 1;
        }
	*/
	if(!(((argc == 4) && (*argv[3] == 'p')) || (argc ==3)) ){	
                printf("Argumentos incorrectos. Uso:\n");
                printf("%s <work fifo> <results fifo> [<p>ermanente]\n", argv[0]);
                return 1;
        } 


	char *work_fifo = argv[1];
	char *results_fifo = argv[2];

        

	do{ //hay que hacerlo con do while ya que asi, aun que no se cumpla la condicion entra una vez, "primero dispara, luego pregunta"
        //abrimos
        pipe = open(work_fifo, O_RDONLY);

	//abrimos
	pipe2 = open(results_fifo, O_WRONLY);


        //llamamos a la funcion worker del ejercicio anterior
	worker(pipe, pipe2); 

        //cerramos
        close(pipe);
	close(pipe2);
	}while(argv[3] != NULL);

	return 0;


}

