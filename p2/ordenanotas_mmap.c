#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "practica2.h"

int ordenanotas(int fd)
{       
        int valor=0, numAlumnos=0;
        struct stat longbytes;
        struct evaluacion auxiliar;
        int intercambios;

        fstat(fd,&longbytes);

        valor = sizeof(struct evaluacion); //calculo tamaño de la estructura evaluacion
        numAlumnos = (longbytes.st_size/valor); //divido el numero total de bytes entre el tamao de una estructura
	
	struct evaluacion *archivo_en_memoria = mmap(NULL, longbytes.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	


        for(int i=0; i<numAlumnos-1; i++)
        
        {
                for(int j=0; j < numAlumnos-1; j++)
                {
                        if(archivo_en_memoria[j].notamedia < archivo_en_memoria[j+1].notamedia)
                        {
                                auxiliar = archivo_en_memoria[j];
                                archivo_en_memoria[j] = archivo_en_memoria[j+1];
                                archivo_en_memoria[j+1] = auxiliar;
				intercambios++;
                        }
                }
        }
        
	munmap(archivo_en_memoria, longbytes.st_size); //deshacer proyeccion del archivo proyectado con mmap()
	return intercambios;
        
        
        
        
        
}       

