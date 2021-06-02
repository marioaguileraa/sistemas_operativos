#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double funcion_y(double a);
int main(int argc, char** argv)
{

double area_trapecio = 0,area_trapecio_aux=0, valor_pi=0;
int numero_intervalos = 0;
double y2=0, y1=0, x2=0, x1=0;


	 if(argc != 2)
        {
		printf("Argumentos incorrectos. Uso:\n");
                printf("%s <numero de intervalos>\n", argv[0]);
                return 1;
        }



numero_intervalos = atoi(argv[1]);


	
		for(int i=numero_intervalos; i>0; i--)
                {

                if(i==numero_intervalos){
                        x1=(numero_intervalos -1)*(1./numero_intervalos);
                }
                else{
                    x1=x1 -(1./(numero_intervalos));

                }
		x2= x1 + (1./numero_intervalos);
                y1= funcion_y(x1);
		y2 = funcion_y(x2);
		area_trapecio_aux = (((y2+y1)*(x2-x1))/(2)) ;
		area_trapecio = area_trapecio + area_trapecio_aux;
		//sumar todos los trapecios
		
	}
valor_pi = 4 * area_trapecio;
printf("Valor calculado: %.14f \n", valor_pi);
return 0;
}

double funcion_y(double a){
	return sqrt(1 - (a * a));
}




