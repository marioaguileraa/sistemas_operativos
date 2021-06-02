
all: calculapi practica3_1 practica3_2


practica3_1: practica3.o f1.o
	       gcc practica3.o f1.o -o practica3_1 -lpthread -lm

practica3_1.o: f1.c practica3.h 
		gcc -g -Wall -c f1.c

practica3_2: practica3.o f2.o
		gcc practica3.o f2.o -o practica3_2 -lpthread

practica3_2.o: f2.c practica3.h
		gcc -g -Wall -c f2.c



calculapi: calculapi.o
		gcc calculapi.o -o calculapi -lm 

calculapi.o: calculapi.c
		gcc -g -Wall -c calculapi.c 




practica3.o: practica3.c practica3.h
		gcc -g -Wall -c practica3.c


clean:
		rm -f *.o
		rm -f practica3_1 practica3_2 calculapi


