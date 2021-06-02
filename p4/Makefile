all: practica4_pimc practica4_pipes practica4_dispatcher practica4_worker practica4_gatherer practica4_fifos 

practica4_pimc: practica4_pimc.c 
	gcc -g -Wall practica4_pimc.c -o practica4_pimc -lm

practica4_pipes: practica4_pipes.o funcion.o practica4_agents.o
	gcc practica4_pipes.o funcion.o practica4_agents.o -o practica4_pipes

practica4_pipes.o: practica4_pipes.c practica4.h
	gcc -g -Wall -c practica4_pipes.c

practica4_agents.o: practica4_agents.c practica4.h
	gcc -g -Wall -c practica4_agents.c

funcion.o: funcion.c practica4.h
	gcc -g -Wall -c funcion.c

practica4_dispatcher: practica4_dispatcher.o practica4_agents.o funcion.o
		gcc practica4_dispatcher.o practica4_agents.o funcion.o -o practica4_dispatcher

practica4_dispatcher.o: practica4_dispatcher.c practica4.h
	gcc -g -Wall -c practica4_dispatcher.c 

practica4_gatherer: practica4_gatherer.o practica4_agents.o funcion.o  
	cc -g -Wall funcion.o practica4_gatherer.o practica4_agents.o -o practica4_gatherer      

practica4_gatherer.o: practica4_gatherer.c practica4.h  
	cc -g -Wall -c practica4_gatherer.c

practica4_worker: practica4_worker.o practica4_agents.o funcion.o
	gcc practica4_worker.o practica4_agents.o funcion.o -o practica4_worker


practica4_worker.o: practica4_worker.c practica4.h
	gcc -g -Wall -c practica4_worker.c

practica4_fifos: practica4_fifos.o
	gcc practica4_fifos.o -o practica4_fifos

practica4_fifos.o: practica4_fifos.c practica4.h
	 gcc -g -Wall -c practica4_fifos.c
	 
run_fifos:
	mkfifo trabajo
	mkfifo resultados
	./practica4_gatherer resultados &
	./practica4_worker trabajo resultados &
	./practica4_worker trabajo resultados &
	./practica4_worker trabajo resultados &
	./practica4_dispatcher 1000000000 100 trabajo


clean:
	 rm -f *.o
	 rm -f practica4_pimc practica4_pipes practica4_dispatcher practica4_worker practica4_gatherer
	 rm -rf resultados trabajo



