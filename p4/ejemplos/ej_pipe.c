#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
 
int main( int argc, char* argv[]){
 
	int n, pipefd[2];

	pipe( pipefd);

	if( fork() != 0){

		close( pipefd[1]);
		while( read( pipefd[0], &n, sizeof( int) ) > 0)
			printf("Recibido: %d\n", n);
		printf("Se ha cerrado el otro lado del pipe. Finalizando.\n");
		close( pipefd[0]);

	} else {

		close( pipefd[0]);
		for( n = 2; n < 7; n++){
			write( pipefd[1], &n, sizeof( int));
			sleep( 1);
		}
		close( pipefd[1]);

	}
	return 0;
}
