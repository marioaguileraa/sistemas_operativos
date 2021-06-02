#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void mysigaction( int n, siginfo_t * info, void * context);

int main( int argc, char* argv[]){

	struct sigaction a;

	a.sa_sigaction = mysigaction;
	sigemptyset( &a.sa_mask);
	a.sa_flags = SA_SIGINFO;

	sigaction( SIGINT, &a, NULL);

	while( 1);

	return 0;
}

void mysigaction( int n, siginfo_t * info, void * context){

	printf("It is a good day to die... but the day is not yet over.\n");
	signal( SIGINT, SIG_DFL);
} 
