#include <stdio.h>
#include <stdlib.h>
#include "factprint.h"

int main( int argc, char* argv[])
{
	int n;

	if( argc <2){
		printf("Insuficiente número de argumentos.\n");
		return(-1);
	}

	n = atoi( argv[1]);
	factprint( n);

	return 0;
}
