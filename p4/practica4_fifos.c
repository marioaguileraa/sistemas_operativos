#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include "practica4.h"




//CASI IGUAL A PIPES.C LAS POCAS MODIFICACIONES COMENTADAS CON COMENTARIOS EXTRA


int main( int argc, char* argv[], char* envio[]) {


	//creacion mkfifos resultados y trabajo https://www.youtube.com/watch?v=--r9XYsj2ew
        mkfifo("resultados", 0666); //el segundo parametro es para darle permisos
        mkfifo("trabajo", 0666); //el segundo parametro es para darle permisos
	
	//comprobacion posibles erroes mkfifos
	if ((mkfifo("trabajo", 0666) != 0) ||(mkfifo("resultados", 0666) != 0) )
	{
		if(errno != EEXIST)
		{
			perror("Error al crear los fifos");
			exit(-1);
		}
	}

        int num_divisiones, num_work_packages, num_workers;
        //creacion variables


        pid_t *workers;
        pid_t pipe_gatherer;
        pid_t pipe_dispatcher;


        if(argc != 4){
                printf("Argumentos incorrectos. Uso:\n");
                printf("%s <num divisiones> <num work packages> <numero de workers>\n", argv[0]);
                return 1;
        }

        num_divisiones = atoi(argv[1]);
        num_work_packages = atoi(argv[2]);
        num_workers = atoi(argv [3]);


        if (num_divisiones <= 0 || num_work_packages <= 0 || num_workers <= 0) {
                printf("ERROR: por favor introduzca un numero de divisiones, paquetes y workers superiores a cero\n");
                return 1;
        }


        //creacion de workers según el número que nos dan igual que la otra vez
        workers = calloc(num_workers, sizeof(pid_t));






/*
	//creacion mkfifos resultados y trabajo https://www.youtube.com/watch?v=--r9XYsj2ew
	mkfifo("resultados", 0666); //el segundo parametro es para darle permisos
	mkfifo("trabajo", 0666); //el segundo parametro es para darle permisos
*/

	



    	// creamos los workers
	for (int i=0; i< num_workers; i++ ) {
	
    		//primera diferencia	    
		char *argumentos_work[] = {"worker", "trabajo", "resultados", NULL}; //donde resultados y trabajo son los
	       									     //mkfifos creados
        	workers[i] = fork();

        	if (workers[i] == 0 ) {
	
			//segunda diferencia usamos excve: bibliogafria-> https://linux.die.net/man/2/execve
			execve("./practica4_worker", argumentos_work, envio);

		}

	}	

	sleep(1);


    	//llamada dispatcher
	if ( !( pipe_dispatcher = fork() ) ) {
	
		char *argumentos_dispatcher[] = {"dispatcher", argv[1], argv[2], "trabajo", NULL};
		execve("./practica4_dispatcher", argumentos_dispatcher, envio);
	}



	// llamda gathereri IGUAL QUE WORKERS  USANDO EXECVE
	if (!(pipe_gatherer = fork() )) {
        
		char *argumentos_gatherer[] = {"gatherer", "resultados", NULL};
		execve("./practica4_gatherer", argumentos_gatherer, envio);
	}


    

    //fuente: https://pubs.opengroup.org/onlinepubs/007904875/functions/wait.html
    for (int i=0; i<(num_workers+2); i++) {
        int stat_loc;
        wait(&stat_loc);
    }


    free(workers);

    return 0;


}

