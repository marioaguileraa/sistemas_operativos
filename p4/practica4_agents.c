#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include "practica4.h"



void dispatcher( int workpipe, int numwp, long ndiv)
{

	double	num_divisiones_paquete = (ndiv/numwp), tamanyo_division = (double) (1.0/ndiv), posicion_extra=0, tam_struct;
	int resto = (ndiv % numwp);
	struct args *contenedor = (struct args *)malloc(sizeof(struct args));
	tam_struct = sizeof(struct args);

	for (int i = 0; i < numwp; i++) {
		
		contenedor->num_veces = num_divisiones_paquete;
		if(resto != 0)
		{
			contenedor->num_veces += 1;
			resto --;
		}

                contenedor->tam_div = tamanyo_division;		
                contenedor->posicion_inicial = posicion_extra;
		if(i== 0)
		{
			contenedor->posicion_inicial = 0;
		}
		if( i != numwp-1)
		{
		posicion_extra = contenedor->posicion_inicial + contenedor->num_veces * contenedor->tam_div;
		}
		
		write(workpipe, contenedor, tam_struct);
	}
}





void worker( int workpipe, int resultpipe)
{
	//struct args pepe;
	double tam_struct, area_trapecio=0;
	tam_struct = sizeof(struct args);
	struct args *argumento = (struct args *)malloc(sizeof(struct args));
	while( read(workpipe, argumento, tam_struct) > 0)
	{
	
		int numero_intervalos = argumento->num_veces; //numero de intervalos que integra cada hilo
		double start_pos = argumento->posicion_inicial;//dato a tener en cuenta ya que ha habido otros hilos
						              //antes que ya han integrado trozos
		double num_divisiones = argumento->tam_div ;//numero de divisiones totales que se han pedido para
							            //saber el tamaño de cada división.
	
		double x1=0, x2=0, y1=0, y2=0, area_trapecio_aux=0; 	
       	 
		x1= start_pos;
		x2= x1 + num_divisiones;

		for(int u=0; u < numero_intervalos; u++)
		{
			if(x2<1)
			{
				y1 = funcion(x1);
				y2 = funcion(x2);
				area_trapecio_aux = (((y2+y1)*(x2-x1))/(2)) ;
	                	area_trapecio = area_trapecio + area_trapecio_aux;
				x1 += num_divisiones;
				x2 += num_divisiones;
			}
		}
	}
	
	write(resultpipe, &area_trapecio, sizeof(double));

}







void gatherer( int resultpipe)
{

	double valorPi=0, area_trapecio=0, tam_struct;
	tam_struct = sizeof(double);

	while( read(resultpipe, &area_trapecio, tam_struct) > 0)
	{
		valorPi = valorPi + area_trapecio;
	}

	valorPi = valorPi*4;
	printf("Valor calculado= %.14f\n", valorPi);
}



