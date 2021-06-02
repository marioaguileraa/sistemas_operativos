

all: practica2_mmap practica2_std practica2_mostrar


practica2_std: ordenanotas_std.o practica2.o
	gcc  practica2.o ordenanotas_std.o -o practica2_std


ordenanotas_std.o: ordenanotas_std.c practica2.h
	gcc -g -Wall -c ordenanotas_std.c


practica2_mmap: ordenanotas_mmap.o practica2.o
	gcc -g practica2.o ordenanotas_mmap.o -o practica2_mmap


ordenanotas_mmap.o: ordenanotas_mmap.c practica2.h
	gcc -g -Wall -c ordenanotas_mmap.c

practica2_mostrar: muestranotas.o 
	gcc muestranotas.o -o practica2_mostrar

muestranotas.o: muestranotas.c practica2.h
	gcc -g -Wall -c muestranotas.c 


practica2.o: practica2.c practica2.h
	gcc -g -Wall -c practica2.c

datos:
	tar -xvf datos.tgz

clean:
	rm -f *.o
	rm -f practica2_std practica2_mmap
