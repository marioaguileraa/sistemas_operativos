#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main( int argc, char* argv[]){

	int pid;

	if( (pid = fork()) != 0)
		printf("Soy (%d), mi hijo es (%d).\n", getpid(), pid);
	else
		printf("Soy (%d), mi padre es (%d).\n", getpid(), getppid());

	return 0;
}
