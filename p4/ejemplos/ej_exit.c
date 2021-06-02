#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
int main( int argc, char* argv[]){
 
int pid, status;

if( (pid = fork()) != 0){
printf("Esperando a que finalice %d...\n", pid);
wait( &status);
printf("Hijo finalizado con estado %d.\n", WEXITSTATUS(status));
} else {
printf("Durmiendo unos segundos...\n");
sleep( 5);
printf("Finalizando.\n");
exit( 10);
}

return 0;
}
