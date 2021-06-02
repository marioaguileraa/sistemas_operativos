#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 
int main( int argc, char* argv[]){

	int myfd, n;

	if( fork() != 0){

		myfd = open( "myfifo", O_RDONLY);
		while( read( myfd, &n, sizeof( int) ) > 0)
			printf("Recibido: %d\n", n);
		printf("Se ha cerrado el otro lado del pipe. Finalizando.\n");
		close( myfd);

	} else {

		myfd = open( "myfifo", O_WRONLY);
		for( n = 2; n < 7; n++){
			write( myfd, &n, sizeof( int));
			sleep( 1);
		}
	close( myfd);

	}
	return 0;
}
