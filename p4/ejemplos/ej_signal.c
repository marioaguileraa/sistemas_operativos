#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void mysighandler( int n);

int main( int argc, char* argv[]){

	signal( SIGINT, mysighandler);

	while( 1);

	return 0;
}

void mysighandler( int n){

	printf("It is a good day to die... but the day is not yet over.\n");
	signal( SIGINT, SIG_DFL); //sin esta linea, el programa no podría acabar, por lo menos con el comando Ctrl+C
}
