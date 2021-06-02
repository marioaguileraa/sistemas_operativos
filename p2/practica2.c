
#include <sys/stat.h>
#include <sys/time.h> //para poder calcular los tiempos
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "practica2.h"




int main(int argc, char** argv)
{
	int intercambios=0;
	int dif_de_segundos_en_microseg=0, dif_de_microseg=0, dif_final_microseg=0;
	struct timeval t1, t2;
	int fd = open(argv[1], O_RDWR);
	


	if(argc < 2)
        {
                printf("Número de argumentos insuficiente.\n");
                printf("Uso: %s file\n",argv[0]);
                exit(-1);
        }

        if( fd == -1)
        {
                perror("Error al abrir el archivo");
                exit( -1);
        }




	gettimeofday( &t1, NULL);
	intercambios = ordenanotas( fd);
	gettimeofday( &t2, NULL);

	printf("Intercambios: %d\n", intercambios);

	dif_de_segundos_en_microseg = (t2.tv_sec - t1.tv_sec)*1000000;
	dif_de_microseg = t2.tv_usec - t1.tv_usec;
	dif_final_microseg= dif_de_segundos_en_microseg + dif_de_microseg;

	printf("Tiempo empleado: %dus\n", dif_final_microseg);
	

	close(fd);

	return 0;

}
