#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "practica4.h"

int main( int argc, char* argv[]) {

	int num_divisiones, num_work_packages, num_workers;
        //creacion variables
	
	int pipefd_entrada[2];
	int pipefd_salida[2];
	
	pipe(pipefd_entrada);
        pipe(pipefd_salida);

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

	
	//creacion de workers según el número que nos dan
        workers = calloc(num_workers, sizeof(pid_t));
	
	//parte del dispatcher
	 if ( !( pipe_dispatcher = fork() ) ) {
        close(pipefd_entrada[0]);  // Cerramos el lado de la tub que no se usa
        close(pipefd_salida[0]); // Cerramos el lado de la tub que no se usa
        close(pipefd_salida[1]); // 

        dispatcher(pipefd_entrada[1], num_work_packages, num_divisiones); //se llama al dispatcher

        close(pipefd_entrada[1]);  // cerramos
        exit(0);
    }

	 //comprobaciones
	 if (pipe(pipefd_salida) == -1) {
         perror("[pipe]");
         exit(1);
           }

    // creamos los workers
    for (int i=0; i< num_workers; i++ ) {
        workers[i] = fork();  

        if (workers[i] == 0 ) {   
            
	    close(pipefd_entrada[1]);     // cerramos
            close(pipefd_salida[0]);    // cerramos

            worker(pipefd_entrada[0], pipefd_salida[1]); //se llama al worker

            close(pipefd_entrada[0]);     // cerramos
            close(pipefd_salida[1]);    // cerramos

            exit(0);
        }
    }

    // creacion de gatherer
    if (!(pipe_gatherer = fork() )) {
        close(pipefd_salida[1]); // cerramos lado tuberia
        close(pipefd_entrada[0]);  // cerramos lado tuberia
        close(pipefd_entrada[1]);  // cerramos lado tuberia

        gatherer(pipefd_salida[0]);

        close(pipefd_salida[0]); // cerramos lado tuberia
        exit(0);
    }


    // cerramos todo para finalizar
    close(pipefd_entrada[1]);
    close(pipefd_entrada[0]);
    close(pipefd_salida[1]);
    close(pipefd_salida[0]);

    //fuente: https://pubs.opengroup.org/onlinepubs/007904875/functions/wait.html
    for (int i=0; i<(num_workers+2); i++) {
        int stat_loc;
        wait(&stat_loc);
    }


    free(workers);
    
    return 0;


}
