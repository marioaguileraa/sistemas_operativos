#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>

double valor_pi = 0;
int num_iteraciones=0;

void mysigaction( int n, siginfo_t * info, void * context);


void sig_handler(int signum){
	
 //printf("Proceso lanzado (PID= %d)\n", getpid());
 printf("Finalizando por timeout tras %d iteraciones.\n", num_iteraciones);
 printf("Valor calculado: %f\n", valor_pi );
 signal( SIGINT, SIG_DFL );
 //   signal( SIGINT, sig_handler);

 exit(0);
      	
  
}

void sig_handler_c(int signum){

// printf("Proceso lanzado (PID= %d)\n", getpid());
 printf("Finalizado por interrupción.\n");
 printf("Valor calculado: %f\n", valor_pi );
 signal( SIGINT, sig_handler_c);
 exit(0);


}




int main(int argc, char** argv)
{

 
double num_puntos = 0, num_segundos_limite = 0, dardos_dentro = 0, dardos_fuera = 0;
double x_centro = 0.5, y_centro = 0.5;
double division = 0, distancia = 0;


	if(argc != 3){
                printf("Argumentos incorrectos. Uso:\n");
                printf("%s <numero de puntos> <numero de segundos>\n", argv[0]);
                return 1;
        }

        num_puntos = atoi( argv[1]);
        num_segundos_limite = atoi( argv[2]);

        if (num_puntos <= 0 || num_segundos_limite <= 0) {
                printf("ERROR: por favor introduzca un numero de puntos y segundos superiores a cero\n");
                return 1;
        }


	printf("Proceso lanzado (PID= %d)\n", getpid());


	signal(SIGALRM,sig_handler); // Register signal handler del tiempo

 
  	alarm(num_segundos_limite);  // Scheduled alarm after 2 seconds

	//para contrl c
	signal(SIGINT,sig_handler_c); // Register signal handler de control c

	
	struct sigaction a;

	a.sa_sigaction = mysigaction;
	sigemptyset( &a.sa_mask);
	a.sa_flags = SA_SIGINFO;

	sigaction( SIGUSR1, &a, NULL);
	
	

	srand48(time(NULL));


	for(int i=0; i<num_puntos; i++)
	{

		//generar 2 numeros aleatorios entre 0 y 1 para tener el primer punto
		double x_dardo = 0, y_dardo = 0;
		num_iteraciones++;
	

		x_dardo = drand48();
		y_dardo = drand48();
			


		distancia = sqrt(fabs((((x_dardo - x_centro)*(x_dardo - x_centro)) + ((y_dardo - y_centro)*(y_dardo - y_centro)))));

		if(distancia <= 0.5)
		{
			//dentro circulo
			dardos_dentro++;

		}
		else{
			//fuera circulo
			dardos_fuera++;

		}

	
	
		//se divide entre numero de iteraciones, no entre el numero de puntos, si no, solo funcionaria para el pi ejecuta todas las iteraciones	
		 division = (dardos_dentro / num_iteraciones);


		//multiplicamos *4 para tener el valor aproximado de pi
		valor_pi = (division * 4);

	}





printf("Proceso lanzado (PID= %d)\n", getpid());
printf("Finalizando despues de %d iteraciones.\n", num_iteraciones);	
printf("Valor calculado: %f\n", valor_pi);
return 0;
}



void mysigaction( int n, siginfo_t * info, void * context){

//printf ("Proceso lanzado (PID= %ld)\n", (long)info->si_pid);	
//printf("Valor calculado: %f\n", valor_pi );
printf("Resultado parcial solicitado (SIGURS1 de %d).\nValor calculado hasta ahora: %.6f\n",info->si_pid, valor_pi);
} 


