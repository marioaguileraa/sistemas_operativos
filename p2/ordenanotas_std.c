
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "practica2.h"

//Metodo burbuja en https://www.geeksforgeeks.org/bubble-sort/


int ordenanotas(int fd)
{
	
	int valor=0, numAlumnos=0;
	struct stat longbytes;
	int intercambios=0;
	struct evaluacion alu1, alu2;

	fstat(fd,&longbytes);
	
	valor = sizeof(struct evaluacion); //calculo tamaño de la estructura evaluacion
	numAlumnos = (longbytes.st_size/valor); //divido el numero total de bytes entre el tamao de una estructura


	
	for(int i=0; i<(numAlumnos-1); i++)
	//for(int i=0; i < numAlumnos; i++)	
	{
		lseek(fd,0,SEEK_SET); //el puntero se coloca al comienzo
		for(int j=0; j < numAlumnos-i-1; j++)
		//for(int j=0; j<numAlumnos; j++)
		{
			read(fd, &alu1, valor);
			read(fd, &alu2, valor);

			if(alu1.notamedia < alu2.notamedia)
			{
				lseek(fd, -2*valor,SEEK_CUR); 
				write(fd, &alu2, valor);
				write(fd, &alu1, valor);
				intercambios++;
			}
			lseek(fd,-valor,SEEK_CUR);
		}
	}
	return intercambios;
}
