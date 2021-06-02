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
	int num_divisiones, num_work_packages, pipeout;

        if(argc != 4){
                printf("Argumentos incorrectos. Uso:\n");
                printf("%s <num div> <num work packages> <work fifo>\n", argv[0]);
                return 1;
        }


        num_divisiones = atoi(argv[1]);
        num_work_packages = atoi(argv[2]);
        char *work_fifo = argv[3];

        if (num_divisiones <= 0 || num_work_packages <= 0) {
                printf("ERROR: por favor introduzca un numero de divisiones y workers superiores a cero\n");
                return 1;
        }

        //abrimos
        pipeout = open(work_fifo, O_WRONLY);


	//llamamos a la funcion dispatcher del ejercicio anterior
	dispatcher(pipeout, num_work_packages, num_divisiones);

	//cerramos
        close(pipeout);

	return 0;


}


