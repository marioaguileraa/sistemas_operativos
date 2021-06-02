#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
 

void mysighandler( int n);

int main( int argc, char* argv[]){

	struct sigaction a;

	a.sa_handler = mysighandler;
	sigemptyset( &a.sa_mask);
	a.sa_flags = 0;

	sigaction( SIGINT, &a, NULL);

	while( 1);

	return 0;
}

void mysighandler( int n){

	printf("It is a good day to die... but the day is not yet over.\n");
	signal( SIGINT, SIG_DFL);
}
