#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include "practica3.h"
#include <unistd.h>
#include <stdbool.h>

/*MUTEX: Mutual Exclusion para sincronizar el uso de un recurso compartido entre hilos */
//idea para pasar argumentos: http://www.cse.cuhk.edu.hk/~ericlo/teaching/os/lab/9-PThread/Pass.html
double valorPi=0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct args {
	int div_aux;
	int posicion_inicial;
	int divisiones_totales;
};

void * hilo (void *arg) {

	int numero_intervalos = ((struct args*)arg)->div_aux; //numero de intervalos que integra cada hilo
	int start_pos = ((struct args*)arg)->posicion_inicial;//dato a tener en cuenta ya que ha habido otros hilos
						              //antes que ya han integrado trozos
	int num_divisiones = ((struct args*)arg)->divisiones_totales;//numero de divisiones totales que se han pedido para
							            //saber el tamaño de cada división.
	
	double x1=0, x2=0, y1=0, y2=0, area_trapecio=0, area_trapecio_aux=0; 	
       	       
	 //de derecha a izquierda
	 for(int i=numero_intervalos; i>0; i--)
         {
                
         	if(i==numero_intervalos){
                        x1=(numero_intervalos -1)*(1./num_divisiones);
                	if(start_pos !=0){
                        	x1=start_pos*(1./num_divisiones)+ (numero_intervalos -1)*(1./num_divisiones);
                	}
                }
                else{
                	x1=x1 -(1./(num_divisiones));
                }
		
                x2= x1 + (1./num_divisiones);
		y1= funcion_y(x1);
                y2 = funcion_y(x2);
                area_trapecio_aux = (((y2+y1)*(x2-x1))/(2)) ;
                area_trapecio = area_trapecio + area_trapecio_aux;
	}
	pthread_mutex_lock(&mutex);
	valorPi = valorPi + area_trapecio*4;
	pthread_mutex_unlock(&mutex);

	pthread_exit(NULL);	
}







int main( int argc, char* argv[]) {
	int nthreads, num_divisiones, num_divisiones_todos_hilos =0, hilo_final_conDivExtra = 1, numero_de_hilos;
	bool impar = false;
	pthread_t * th;
	

	if(argc != 3){
		printf("Argumentos incorrectos. Uso:\n");
		printf("%s <numero de hilos> <numero de divisiones>\n", argv[0]);
		return 1;
	}

	nthreads = atoi( argv[1]);
	num_divisiones = atoi( argv[2]);

	if (nthreads <= 0 || num_divisiones <= 0) {
    		printf("ERROR: por favor introduzca un numero de hilos y divisiones superiores a cero\n");
    		return 1;
  	}
	
        if ((num_divisiones % nthreads)==0){ //divisiones exactas

        	num_divisiones_todos_hilos = num_divisiones / nthreads;
	      	hilo_final_conDivExtra = 0;
	     	impar = false;
	}
	else {  //divisiones no exactas
		num_divisiones_todos_hilos =  num_divisiones / nthreads;
		hilo_final_conDivExtra = num_divisiones - (nthreads*num_divisiones_todos_hilos); //num de hilos con una div más
		impar = true;	
	}
	
	th = (pthread_t *) calloc( nthreads, sizeof( pthread_t));

	
     	if(hilo_final_conDivExtra==0){
          	numero_de_hilos=nthreads;         //todos los hilos tendrán las mismas divisiones
     						  //se hará un bucle con todos los hilos
     	}
     	else{
        	numero_de_hilos= hilo_final_conDivExtra; //no todos los hilos tienen las mismas divisiones
	                               		         // se hará un bucle de los que tienen una división más que el resto.
						         // luego otro bucle del resto 
    	 }

	for(int u=0; u< numero_de_hilos;u++) {
                struct args *contenedor = (struct args *)malloc(sizeof(struct args));
                contenedor->div_aux = num_divisiones_todos_hilos;
                
                contenedor->posicion_inicial = (num_divisiones_todos_hilos)*u;
                contenedor->divisiones_totales = num_divisiones;

                if(impar){
                	contenedor->div_aux = num_divisiones_todos_hilos + 1;   //si es una division no exacta algunos tienen 
										//una division más
			contenedor->posicion_inicial = (num_divisiones_todos_hilos+1)*u; //indica que ya ha habido divisiones en los 											    //anteriores hilos.	
		}

                pthread_create(&th[u], NULL, hilo, (void *)contenedor);
        }
     

	
	if(impar) {
 
		for( int i = numero_de_hilos; i < nthreads; i++){ //creamos los hilos que no tienen una division extra
          
        		struct args *contenedor = (struct args *)malloc(sizeof(struct args));
        		contenedor->div_aux = num_divisiones_todos_hilos;
        	      
			if(i==numero_de_hilos){ //primera vez, como venimos de divisiones +1 se pone así,
			contenedor->posicion_inicial = (num_divisiones_todos_hilos + 1)*(i);  
			}
			else{
			contenedor->posicion_inicial = (num_divisiones_todos_hilos + 1)*(numero_de_hilos)+num_divisiones_todos_hilos*(i-numero_de_hilos);  
			}
			contenedor->divisiones_totales = num_divisiones;

			pthread_create(&th[i], NULL, hilo, (void *)contenedor);
	
		}
	}
	
	
	//permite esperar a la terminacion de un hilo
	for(int j=0; j < nthreads; j++){
		pthread_join(th[j], NULL);
	}

	
	printf("Valor calculado= %.14f\n", valorPi);
	free(th); //borramos la memoria dinamica asignada a los hilos 
	return 0;
}

