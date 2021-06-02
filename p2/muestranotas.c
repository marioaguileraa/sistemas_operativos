#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "practica2.h"

int main(int argc, char** argv)
{
	int valor=0, valor2=0;
	int fd = open(argv[1], O_RDONLY);
	struct stat longbytes;


	if(argc < 2)
	{
		printf("Número de argumentos insuficiente.\n");
                printf("Uso: ./practica2_mostrar file\n");
		exit(-1);
	}

	if( fd == -1)
	{	
		perror("Error al abrir el archivo");
		exit( -1);
	}



	fstat(fd,&longbytes);
	

	struct evaluacion *archivo_en_memoria = mmap(NULL, longbytes.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	valor2 = sizeof(struct evaluacion);
	valor = (longbytes.st_size/valor2);

	printf("Imprimiendose archivo..\n\n");
	for(int i=0; i<valor; i++)

	{
		printf("%9s: ", archivo_en_memoria[i].id);
		printf("%5.2f: ", archivo_en_memoria[i].nota1p);
		printf("%5.2f: ", archivo_en_memoria[i].nota2p);
                printf("%5.2f:", archivo_en_memoria[i].notamedia);
		printf("%s ", archivo_en_memoria[i].apellido1);
		printf("%s, ", archivo_en_memoria[i].apellido2);
		printf("%s\n", archivo_en_memoria[i].nombre);
	}
	printf("\n");

	munmap(archivo_en_memoria, longbytes.st_size); //deshacer proyeccion del archivo proyectado con mmap()
	close(fd);

}

